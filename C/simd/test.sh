#/bin/bash

function create_file() {
    if [[ ! -f "${1}" ]]; then
        touch ${1}
        echo "create log ${1}"
    fi
}

bucket_nums=(1 2 4 8 16 32 64)
repeat_nums=(1 4 8 12 16)
base_nums=(16 64 128 256)

log="test.log"

create_file ${log}
exe=/home/hjl/code/Scraps/bin/simd_benchmark

for bkt in ${bucket_nums[@]}; do
    for n in ${repeat_nums[@]}; do
        for base in ${base_nums[@]}; do
            numactl -N 0 ${exe} ${bkt} ${n} ${base} >>${log}
        done
    done
done
