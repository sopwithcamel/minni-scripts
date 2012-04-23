#!/bin/bash

metas=jedi063
metaport=20000
hostsfile=/net/hu17/hamur3/code/kfs-0.5/scripts/machines.txt
kfshome=/net/hu17/hamur3/code/kfs-0.5
tempfiles=/localfs/hamur/

# Clear old files
#echo "Clearing old files..."
cd $tempfiles
rm -f wlog *map* *reduce* timelog result0 &> /dev/null
cd -

# Start workdaemons
./run_workdaemon_local.sh &

sleep 10
#Start master
#echo "Starting master..."
./run_master.sh &

#Start monitoring scripts
#echo "Starting monitoring scripts..."
pidstat -p `pgrep chunkserver` -d -t 1 > $tempfiles"/disk.out" &
./mon.py `pgrep workdaemon` $tempfiles"/mon.out"

kill -9 `pgrep test`
kill -9 `pgrep pidstat`

#echo "Map Statistics" 
python avg_map_mem_2s.py $tempfiles"/mon.out"
python avg_diskstats_2s.py $tempfiles"/disk.out"

