from shell_command import shell_call
import os



latency = []
output_path = '/home/voja/Downloads/traces/communication/3_communication.log'
oracle_cmd = '/home/voja/Development/networkingdm/packettagger/3_components/oracle/bin/oracle &'
sleep_cmd = 'sleep 0.5'
exp_cmd = 'LD_PRELOAD=/home/voja/Development/networkingdm/packettagger/3_components/syscall_catch/bin/wrap-syscall.so  iperf -c bach26 -n 100000'
tail_cmd = 'dmesg | tail -n 2'

def run_experiment():
    shell_call(oracle_cmd)
    shell_call(sleep_cmd)
    shell_call(exp_cmd)
    
    output = os.popen(tail_cmd).read()
    sp = output.strip().split('\n')
    if 'CALL:' in sp[0] and 'ORACLE:' in sp[1]:
        t1 = int(sp[0].strip().split(':')[1])
        t2 = int(sp[1].strip().split(':')[1])
        return t2-t1
    else:
        return -1

for i in range(1000):
    time = run_experiment()
    if time != -1:
        latency.append(time)

with open(output_path, 'w') as f:
    for l in latency:
        f.write(str(l)+'\n')