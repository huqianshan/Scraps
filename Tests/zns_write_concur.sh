#! /bin/bash

DEV=nvme2n2
# NUMJOBS=(1 4 8 16 32 48 64)
# NUMBS=(4K 8K 16K 32K 64K 128K 256K 512K 1M)
NUMJOBS=(1)
NUMBS=(4K)
RUNTIME=30
# if [[ "$#" -ne "1" ]]; then echo "Requires device name (e.g. nvme2n2) argument" && exit; fi

# ZONED=0
# PARTITION=0

if [[ "$(cat /sys/block/$DEV/queue/zoned)" == "host-managed" ]]; then
    # Get the device information
    DEV_INFO=($(sudo bash ./get_zoned_device_info.sh $DEV | awk 'NF{ print $NF }'))

    DEV_ZONE_CAP=${DEV_INFO[0]}
    DEV_ZONE_SIZE=${DEV_INFO[1]}
    DEV_ZONES=${DEV_INFO[2]}
    DEV_MAX_ACTIVE_ZONES=${DEV_INFO[3]}
    DEV_SECT_SIZE=${DEV_INFO[4]}
    DEV_SCHEDULER=${DEV_INFO[5]}
    DEV_NUMA_NODE=${DEV_INFO[6]}
    ZONED=1

    export DEV_ZONE_CAP
    export DEV_ZONE_SIZE
    export DEV_ZONES
    export DEV_MAX_ACTIVE_ZONES
    export DEV_SCHEDULER
else
    # Device is not zoned device
    DEV_SECT_SIZE=$(cat /sys/block/$DEV/queue/hw_sector_size)
    DEV_NUMA_NODE=$(cat /sys/block/$DEV/device/numa_node)
    DEV_SIZE=$(cat /sys/block/$DEV/size)
    ZONED=0

    export DEV_SIZE
fi

ioengine=psync
for jobs in ${NUMJOBS[@]}; do
    for BS in ${NUMBS[@]}; do
        echo "Running benchmarks psync write ${DEV} ${DEV_SCHEDULER} jobs bs: $jobs $BS"
        fio --name=$(echo "${DEV}_psync_write_${DEV_SCHEDULER}_${BS}_${jobs}") \
            --output=$(echo "./data/${DEV}_psync_write_${DEV_SCHEDULER}_${BS}_${jobs}.json") --output-format=json --filename=/dev/$DEV --numjobs=$jobs --direct=1 --ioengine=psync --zonemode=zbd --rw=write --iodepth=1 --time_based --thread --group_reporting --bs=$BS --runtime=$RUNTIME --numa_cpu_nodes=$DEV_NUMA_NODE \
            --ramp_time=5 --percentile_list=50:95:99:99.9:99.99:99.999:99.9999:99.99999:100

        echo "Running benchmarks libaio write ${DEV} ${DEV_SCHEDULER} jobs bs: $jobs $BS"
        fio --name=$(echo "${DEV}_libaio_write_${DEV_SCHEDULER}_${BS}_${jobs}") \
            --output=$(echo "./data/${DEV}_libaio_write_${DEV_SCHEDULER}_${BS}_${jobs}.json") --output-format=json --filename=/dev/$DEV --numjobs=1 --direct=1 --ioengine=libaio --iodepth=$jobs --zonemode=zbd --rw=write \
            --time_based --thread --group_reporting --bs=$BS --runtime=$RUNTIME --numa_cpu_nodes=$DEV_NUMA_NODE \
            --ramp_time=5 --percentile_list=50:95:99:99.9:99.99:99.999:99.9999:99.99999:100
    done
done

# MQ_SIZE=$(echo "scale=0;$DEV_ZONE_SIZE*$DEV_SECT_SIZE*$DEV_ZONES" | bc)
# Filling namespace for read benchmark
# blkzone reset /dev/$DEV # make sure ns is empty
# set mq-deadline scheduler
# echo mq-deadline | tee /sys/block/$DEV/queue/scheduler >/dev/null
# echo "Filling entire namespace for read benchs"
# fio --name=zns-fio --filename=/dev/$DEV --direct=1 --size=$MQ_SIZE --ioengine=libaio --iodepth=4 --rw=write --bs=512K --zonemode=zbd >/dev/null

# Run fio for each active zone setup
for jobs in ${NUMJOBS[@]}; do
    for BS in ${NUMBS[@]}; do
        echo "Running benchmarks read psync ${DEV} ${DEV_SCHEDULER} jobs bs: $jobs $BS"

        fio --name=$(echo "${DEV}_psync_read_${DEV_SCHEDULER}_${BS}_${jobs}") \
            --output=$(echo "./data/${DEV}_psync_read_${DEV_SCHEDULER}_${BS}_${jobs}.json") --output-format=json --filename=/dev/$DEV --numjobs=$jobs --direct=1 --ioengine=psync --zonemode=zbd --rw=randread \
            --iodepth=1 --time_based --thread --group_reporting --bs=$BS --runtime=$RUNTIME --numa_cpu_nodes=$DEV_NUMA_NODE \
            --ramp_time=5 --percentile_list=50:95:99:99.9:99.99:99.999:99.9999:99.99999:100

        echo "Running benchmarks read libaio ${DEV} ${DEV_SCHEDULER} jobs bs: $jobs $BS"
        fio --name=$(echo "${DEV}_libaio_read_${DEV_SCHEDULER}_${BS}_${jobs}") \
            --output=$(echo "./data/${DEV}_libaio_read_${DEV_SCHEDULER}_${BS}_${jobs}.json") --output-format=json --filename=/dev/$DEV --numjobs=1 --direct=1 --ioengine=libaio --iodepth=$jobs --zonemode=zbd --rw=randread \
            --time_based --group_reporting --bs=$BS --runtime=$RUNTIME --numa_cpu_nodes=$DEV_NUMA_NODE \
            --ramp_time=5 --percentile_list=50:95:99:99.9:99.99:99.999:99.9999:99.99999:100
    done
done
