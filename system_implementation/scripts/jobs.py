import random

w1 = {
    'inf': 'hdfs://bach03:9000/user/zhanzhip/MLBench/avazu-full',
    'num_iter': 30,
    'mbf': 1,
    'steps': 1,
    'num_worker': 5,
    'cores_per_executor': 1,
    'partition_per_core': 1,
    'whether_debug': True,
    'num_features': 999990,
    'reg_para':0.001
}


w2 = {
    'inf': 'hdfs://bach03:9000/user/zhanzhip/MLBench/url_combined',
    'num_iter': 20,
    'mbf': 0.01,
    'steps': 0.01,
    'num_worker': 8,
    'cores_per_executor': 1,
    'partition_per_core': 1,
    'whether_debug': True,
    'num_features': 3231962,
    'reg_para':0.1
}

w3 = {
    'inf': 'hdfs://bach03:9000/user/zhanzhip/MLBench/webspam_wc_normalized_trigram.svm',
    'num_iter': 10,
    'mbf': 1,
    'steps': 1,
    'num_worker': 8,
    'cores_per_executor': 1,
    'partition_per_core': 1,
    'whether_debug': False,
    'num_features': 16609144,
    'reg_para':0
}

w4 = {
    'inf': 'hdfs://bach03:9000/user/zhanzhip/MLBench/kddb',
    'num_iter': 20,
    'mbf': 1,
    'steps': 0.00001,
    'num_worker': 8,
    'cores_per_executor': 1,
    'partition_per_core': 1,
    'whether_debug': False,
    'num_features': 29890096,
    'reg_para': 0.1
}

w5 = {
    'inf': 'hdfs://bach03:9000/user/zhanzhip/MLBench/kdd12',
    'num_iter': 1,
    'mbf': 1,
    'steps': 1,
    'num_worker': 8,
    'cores_per_executor': 1,
    'partition_per_core': 1,
    'whether_debug': False,
    'num_features': 54686452,
    'reg_para': 0
}

workloads = [w1, w2, w3, w4, w5]

def generate_command(parameters):
    cmd ='/mnt/local/vdukic/spark-2.1.1-bin-hadoop2.7/bin/spark-submit --master yarn\
            --conf spark.eventLog.enabled=true\
            --deploy-mode cluster\
            --num-executors {num_worker} \
            --executor-cores {cores_per_executor} \
            --conf spark.driver.memory=15g\
            --conf spark.rpc.message.maxSize=500 \
            --conf spark.reducer.maxSizeInFlight=144m\
            --conf spark.shuffle.file.buffer=32k\
            --conf spark.driver.cores=1\
            --conf spark.serializer=org.apache.spark.serializer.KryoSerializer\
            --conf spark.kryoserializer.buffer.max=1000m\
            --conf spark.driver.maxResultSize=10g\
            --conf spark.memory.fraction=0.7\
            --conf spark.locality.wait=1s\
            --conf spark.task.cpus=1\
            --conf "spark.executor.extraJavaOptions=-XX:+UseG1GC"\
            --executor-memory 15g\
            --class svmWithSGDgd /mnt/local/vdukic/ghandMLlib.jar\
            {inf} {num_iter} {mbf} {steps} {num_worker} {cores_per_executor} {partition_per_core} {whether_debug} {num_features} {reg_para}'.format(
                inf = parameters['inf'],
                num_iter = parameters['num_iter'],
                mbf = parameters['mbf'],
                steps = parameters['steps'],
                num_worker = parameters['num_worker'],
                cores_per_executor = parameters['cores_per_executor'],
                partition_per_core = parameters['partition_per_core'],
                whether_debug = parameters['whether_debug'],
                num_features = parameters['num_features'],
                reg_para = parameters['reg_para']
            )
    return cmd

def get_workload():
    params = random.choice(workloads)
    params['num_iter'] = min(params['num_iter'], random.randint(5, 15))
    cmd = generate_command(params)
    return (cmd, params)