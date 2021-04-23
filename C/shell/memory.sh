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
