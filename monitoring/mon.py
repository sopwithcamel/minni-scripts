#!/usr/bin/python
import sys, os, time, signal

pgsize = 4096
dfs_disk = "sda"
num_samp = 10000

if len(sys.argv) < 2:
  print "What program should I monitor?"
  sys.exit(0)

if len(sys.argv) == 3:
  outfile = sys.argv[2]
else:
  outfile = "/localfs/hamur/mon.out"

pid = int(sys.argv[1])
fil = open(outfile, "w")

def sigint_handler(signum, frame):
  fil.close()
  sys.exit(0)

def sigusr1_handler(signum, frame):
  fil.writelines("--------------------------------")

inoct_prev = -1
outoct_prev = -1
busy_prev = -1
idle_prev = -1
reads_prev = -1
writes_prev = -1

signal.signal(signal.SIGINT, sigint_handler)
signal.signal(signal.SIGUSR1, sigusr1_handler)

i = 0
while True:
    i = i + 1
    if i == num_samp:
      break
    write_str = ""
    if not os.path.exists("/proc/" + str(pid)):
      fil.close()
      sys.exit(0)

    child_mem = os.popen("cat /proc/" + str(pid) + "/statm")
    mem = child_mem.read()
    write_str = write_str + str(float(mem.split(" ")[1]) * 4 / 1024)

    sys_cpu = os.popen("cat /proc/" + str(pid) + "/stat")
    cpu = sys_cpu.read()
    line_cpu = cpu.split()

    busy = int(line_cpu[13]) + int(line_cpu[14])
#    idle = int(line_cpu[5])
    if busy_prev > 0:
      this_busy = busy - busy_prev
#      this_idle = idle - idle_prev 
      write_str = write_str + ", " + str(this_busy) #str(float(this_busy) / (this_busy + this_idle))
      fil.writelines(write_str + "\n")
    busy_prev = busy
#    idle_prev = idle  

#    pidd = os.popen("pidstat -p `pgrep chunkserver` -d -t")
#    pidd.readline()
#    pidd.readline()
#    pidd.readline()
#    sys_disk = pidd.readline().split()
#    num_reads = float(sys_disk[4])
#    num_writes = float(sys_disk[5])
#    print sys_disk, num_reads, num_writes
#    if reads_prev > 0:
#      reads_now = num_reads - reads_prev
#      writes_now = num_writes - writes_prev
#      write_str = write_str + ", " + str(reads_now) + ", " + str(writes_now)
#    reads_prev = num_reads
#    writes_prev = num_writes


#    child_net = os.popen("cat /proc/" + str(pid) + "/net/netstat | grep IpExt")
#    nets = child_net.read().split("\n")[1].split(" ")
#    inoct = int(nets[7])
#    outoct = int(nets[8])
#    if inoct_prev > 0:
#      write_str = write_str + ", " + str(float(inoct - inoct_prev) / 1024**2)
#      write_str = write_str + ", " + str(float(outoct - outoct_prev) / 1024**2)
#    inoct_prev = inoct
#    outoct_prev = outoct
#    child_net.close()
    
    child_mem.close()
    time.sleep(1)

    
    
