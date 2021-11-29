#!/bin/bash
# PROCESS=ycsb_multi_thread_test work
DIR="./result/data/rawdata/"
LOG="${DIR}memory_log.txt"
PFILE="${DIR}memory_usg.txt"
# 监控的进程名
cmd="ycsb_multi_thread_test work"
#删除上次的监控文件
if [ -f "$LOG" ]; then
    rm "$LOG"
fi

if [ -f "$PFILE" ]; then
    rm "$PFILE"
fi

last=""
tmpMem=""

# 开始循环
while true; do
    #过滤出需要的进程ID
    PID=$(ps -Acf | grep "$cmd" | grep -v 'grep' | awk '{print $2;}')

    # 没有找到pid进程ID,等待2s
    if [ -z "$PID" ]; then
        sleep 2
        echo "Not found PID"
        continue
    fi

    # pid 进程改变，输出进程内存映射信息到$log
    if [ "$PID" != "$last" ]; then
        echo $PID
        echo "PID: ${PID}" >>$LOG
        tmpMem="$(sudo pmap -x $PID)"

        echo "$tmpMem" >>$PFILE
        echo "\n" >>$PFILE
        last=$PID
    fi

    # 查找RSS实际物理内存使用量 输出到$LOG
    cat /proc/$PID/status | grep RSS >>$LOG
    last=$PID
    # 每次查找睡眠间隔
    sleep 0.5
done

# 字段	说明
# VmPeak	进程所使用的虚拟内存的峰值
# VmSize	进程当前使用的虚拟内存的大小
# VmLck	已经锁住的物理内存的大小（锁住的物理内存不能交换到硬盘）
# VmHWM	进程所使用的物理内存的峰值
# VmRSS	进程当前使用的物理内存的大小
# VmData	进程占用的数据段大小
# VmStk	进程占用的栈大小
# VmExe	进程占用的代码段大小（不包括库）
# VmLib	进程所加载的动态库所占用的内存大小（可能与其它进程共享）
# VmPTE	进程占用的页表大小（交换表项数量）
# VmSwap	进程所使用的交换区的大小
