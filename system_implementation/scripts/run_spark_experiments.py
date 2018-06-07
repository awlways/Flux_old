import commands
import jobs

SERVERS = ['bach21','bach22','bach23','bach26','bach27','bach29']
LOGGER_PATH = '/tmp/logger.so'

YARN_START = '/mnt/local/vdukic/hadoop-2.7.3/sbin/start-yarn.sh'
YARN_STOP = '/mnt/local/vdukic/hadoop-2.7.3/sbin/stop-yarn.sh'

SOURCE_LOGS = '/tmp/ld_preload_logs'
DESTINATION_LOGS = '/home/voja/work/syscall_traces'

SSH_COMMAND = 'ssh vdukic@{0} {1}'

def run_command(cmd):
    print 'EXECUTE:', cmd
    return commands.getstatusoutput(cmd)[1]

def run_command_all(cmd):
    for server in SERVERS:
        command = cmd;
        if '|SERVER_HOST|' in cmd:
            command = command.replace('|SERVER_HOST|', server)
        run_command(command)

def ssh(cmd, machine):
    x = run_command(SSH_COMMAND.format(machine, cmd))
    print 'RESULT', x
    return x

def ssh_all(cmd):
    for server in SERVERS:
        command = cmd;
        if '|SERVER_HOST|' in cmd:
            command = command.replace('|SERVER_HOST|', server)
        ssh(command, server)


def run_experiment():
    #stop yarn
    ssh(YARN_STOP, 'bach22');
    ssh(YARN_STOP, 'bach22');

    #remove old logs
    ssh_all('rm {0}'.format(SOURCE_LOGS))

    #create destination folders
    date_part = run_command('date +%s')
    folder_name = DESTINATION_LOGS + '/' + date_part
    run_command('mkdir ' + folder_name)
    trace_name = folder_name + '/trace_|SERVER_HOST|.log'

    #start yarn
    ssh(YARN_START, 'bach22');

    print 'RUN_JOB'
    #ssh('/mnt/local/vdukic/submit.sh', 'bach27')
    workload = jobs.get_workload()
    ssh(workload[0],'bach27')

    #stop yarn
    ssh(YARN_STOP, 'bach22');
    ssh(YARN_STOP, 'bach22');

    #copy traces
    run_command_all('scp vdukic@|SERVER_HOST|:{0} {1}'.format(SOURCE_LOGS, trace_name))

    with open(folder_name + '/info_'+date_part+'.txt', 'w') as f:
        for key in workload[1]:
            f.write(str(key)+' '+str(workload[1][key])+'\n')

for i in range(1000):
    run_experiment()
