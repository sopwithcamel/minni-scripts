import os,sys,subprocess

metaserver = "jedi063"
uniq = 100
rep = 10
fanout = 8
selected = "cbt"
so_name = "/usr/local/lib/minni/wordcount.so"
buffer_size = 150*1024**2
# Generate file
#subprocess.call("../inputgen/genr " + str(uniq * 1000000) + " " + str(rep) + " 7 /localfs/hamur/randinput.txt", shell=True)
# Copy to kfs
#subprocess.call("cd ~/code/kfs-0.5/build/bin/tools; ./kfsshell -s " + metaserver + " -p 20000 -q rm dataset.txt; ./cptokfs -s " + metaserver + " -p 20000 -d /localfs/hamur/randinput.txt -k ./dataset.txt; cd -", shell=True)
# Generate new config file
for fanout in [2**i for i in range(7)[2:]]:
# Generate new config file
    print "Run: CBT buffer size: " + str(buffer_size)
    subprocess.call("../config/mod -minni__input_files dataset.txt " + " -minni__internal__selected " + selected + " -minni__so_name " + so_name + " -minni__internal__cbt__buffer_size " + str(buffer_size) + " -minni__internal__cbt__fanout " + str(fanout), shell=True)
    subprocess.call("cd ../monitoring/; ./run_minni_local.sh; cd -", shell=True)
    subprocess.call("sleep 5", shell=True)
