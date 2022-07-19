#/bin/bash/

gcc /home/hjl/code/Scraps/C/pmdk/libpmem/test.c -o /home/hjl/code/Scraps/C/pmdk/libpmem/test -lpmem

LD_LIBRARY_PATH=/usr/local/lib/pmdk_debug PMEM_LOG_LEVEL=4 PMEM_LOG_FILE=/home/hjl/Documents/log/logfile /home/hjl/code/Scraps/C/pmdk/libpmem/test

rm /home/hjl/code/Scraps/C/pmdk/libpmem/test
