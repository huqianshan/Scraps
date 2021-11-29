#!/bin/bash

PMDIR="/data/pmem0/vecsearch1/"
# PMDIR="/pmem/poolset/"
if [ ! -d $PMDIR ]; then
    mkdir -p $PMDIR
    echo "Creating $PMDIR"
fi

if [ ! -z "$(ls ${PMDIR})" ]; then
    echo "${PMDIR} Not Empty;So clear it"
    rm -f ${PMDIR}*
    ls ${PMDIR}
fi

make clean && make

if [ $? -eq 0 ]; then
    ./unittest && ./demo && ./demo --populate false --test_count 40000000
    # ./demo && ./demo --populate false --test_count 40000000 && ./demo --populate false --test_count 40000000
    # ./demo --populate false --test_count 40000000
    # ./unittest && ./demo --nodes 1000000 && ./demo --populate false --test_count 1000000
else
    echo "make Failed;Don't execute"
fi
