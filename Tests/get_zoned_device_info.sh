#! /bin/bash

set -e

if [[ "$#" -ne "1" ]]; then echo "Requires device name (e.g. nvme2n2) argument" && exit; fi

DEV=$1
DEV_CAP=$(nvme zns report-zones /dev/$DEV -d 1 | grep -o 'Cap:.*$' | awk '{print int($2)}')
DEV_ZONE_SIZE=$(cat /sys/block/$DEV/queue/chunk_sectors)
DEV_ZONES=$(cat /sys/block/$DEV/queue/nr_zones)
DEV_MAX_ACTIVE_ZONES=$(cat /sys/block/$DEV/queue/max_active_zones)
DEV_SECT_SIZE=$(cat /sys/block/$DEV/queue/hw_sector_size)
DEV_SCHEDULER=$(cat /sys/block/$DEV/queue/scheduler | awk '{print $1}')
DEV_NUMA_NODE=$(cat /sys/block/$DEV/device/numa_node)

echo "Zone size (in 512B Sectors): $DEV_ZONE_SIZE"
echo "Zone capacity (in ${DEV_SECT_SIZE}B Sectors): $DEV_CAP"
echo "Nr. of zones: $DEV_ZONES"
echo "Max. active zones: $DEV_MAX_ACTIVE_ZONES"
echo "Sector size: $DEV_SECT_SIZE"
echo "Scheduler: $DEV_SCHEDULER"
echo "Device NUMA Node: $DEV_NUMA_NODE"
