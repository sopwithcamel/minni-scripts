import os,sys,subprocess

metaserver = "jedi063"
uniq = 100
rep = 10
fanout = 16
selected = "cbt"
so_name = "/usr/local/lib/minni/wc_proto.so"
# Generate file
#subprocess.call("../inputgen/genr " + str(uniq * 1000000) + " " + str(rep) + " 7 /localfs/hamur/randinput.txt", shell=True)
# Copy to kfs
#subprocess.call("cd ~/code/kfs-0.5/build/bin/tools; ./kfsshell -s " + metaserver + " -p 20000 -q rm dataset.txt; ./cptokfs -s " + metaserver + " -p 20000 -d /localfs/hamur/randinput.txt -k ./dataset.txt; cd -", shell=True)
# Generate new config file
for buffer_size in [x*1024**2 for x in [180, 210, 240]]: #[30, 60, 90, 120, 150]]: #range(7)[3:]]:
# Generate new config file
    print "Run: CBT buffer size: " + str(buffer_size)
    subprocess.call("../config/mod -minni__input_files dataset.txt " + " -minni__internal__selected " + selected + " -minni__so_name " + so_name + " -minni__internal__cbt__buffer_size " + str(buffer_size) + " -minni__internal__cbt__fanout " + str(fanout), shell=True)
    for iterat in [1]:
        subprocess.call("cd ../monitoring/; ./run_minni_local.sh; cd -", shell=True)
#        subprocess.call("grep -R 'depth' /localfs/hamur/wlog")
#        subprocess.call("grep -R 'leaves' /localfs/hamur/wlog")
        subprocess.call("sleep 5", shell=True)
