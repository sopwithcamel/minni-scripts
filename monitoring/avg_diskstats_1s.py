import glob, os.path, os, numpy, sys

tim_file = open("/localfs/hamur/timelog")

i = 0
for line in tim_file:
  if i == 0:
    map_start = long(line.split(" ")[-1][:-1])
  elif i == 1:
    map_stop = long(line.split(" ")[-1][:-1]) 
  else:
    break
  i = i + 1
map_time = map_stop - map_start

os.system("head -n " + str(map_time*9+1) + " " + sys.argv[1] + " > /localfs/hamur/map_disk.temp")
tim_file.close()

file1 = open("/localfs/hamur/map_disk.temp")
reads = []
writes = []
i = 0
# Read the header lines
for line in file1:
  i = i + 1
  if (i - 4) % 9 != 0:
    continue
  line = line.split()
  reads.append(float(line[4]))
  writes.append(float(line[5]))
print "Map Rd kB/s: ", numpy.mean(reads)
print "Map Wr kB/s: ", numpy.mean(writes)
