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
print "Map time: ", map_time

os.system("head -n " + str(map_time) + " " + sys.argv[1] + " > /localfs/hamur/map_tim.temp")
tim_file.close()

file1 = open("/localfs/hamur/map_tim.temp")
mem = []
cpu = []
for line in file1:
  line = line.split(",")
  mem.append(float(line[0]))
  cpu.append(float(line[1]))
print "Map memory: (Avg): ", numpy.mean(mem), "(Max): ", max(mem)
print "Map CPU: ", numpy.mean(cpu)
