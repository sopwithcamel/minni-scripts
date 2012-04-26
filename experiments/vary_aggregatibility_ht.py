import os,sys,subprocess

metaserver = "jedi063"
buffer_size = 30*1024**2;
fanout = 8
for uniq in [60]:
    for rep in [4*i for i in range(11)[2:]]:
        print str(uniq) + "mil" + str(rep) + "x" + "10b.txt"
        # Generate file
        subprocess.call("../inputgen/genr " + str(uniq * 1000000) + " " + str(rep) + " 7 /localfs/hamur/randinput.txt", shell=True)
        os.system("sudo echo 1 > /dev/null")
        # Copy to kfs
        subprocess.call("cd ~/code/kfs-0.5/build/bin/tools; ./kfsshell -s " + metaserver + " -p 20000 -q rm dataset.txt; ./cptokfs -s " + metaserver + " -p 20000 -d /localfs/hamur/randinput.txt -k ./dataset.txt; cd -", shell=True)
        os.system("sudo echo 1 > /dev/null")

        for (selected, so_name) in [("sparsehash", "/usr/local/lib/minni/wcplain.so")]:
        # Generate new config file
            subprocess.call("../config/mod -minni__input_files dataset.txt " + " -minni__internal__selected " + selected + " -minni__so_name " + so_name, shell=True)
            subprocess.call("cd ../monitoring/; ./run_minni_local.sh; cd -", shell=True)
            os.system("sudo echo 1 > /dev/null")
            subprocess.call("sleep 5", shell=True)
