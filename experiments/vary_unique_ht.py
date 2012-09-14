import os,sys,subprocess

metaserver = "jedi063"
for uniq in [10, 20, 30, 40, 50, 60]:
    for rep in [int(1000/uniq)]:
        print str(uniq) + "mil" + str(rep) + "x" + "10b.txt"
        # Generate file
        subprocess.call("../inputgen/genr " + str(uniq * 1000000) + " " + str(rep) + " 7 /localfs/hamur/randinput.txt", shell=True)
        os.system("sudo echo 1 > /dev/null")
        # Copy to kfs
        subprocess.call("cd ~/code/kfs-0.5/build/bin/tools; ./kfsshell -s " + metaserver + " -p 20000 -q rm dataset.txt; ./cptokfs -s " + metaserver + " -p 20000 -d /localfs/hamur/randinput.txt -k ./dataset.txt; cd -", shell=True)
        os.system("sudo echo 1 > /dev/null")

        for (selected, so_name) in [("sparsehash", "/usr/local/lib/minni/wc_boost.so")]:
        # Generate new config file
            subprocess.call("../config/mod -minni__input_files dataset.txt " + " -minni__internal__selected " + selected + " -minni__so_name " + so_name , shell=True)
            for iterat in [1, 2, 3]:
                subprocess.call("cd ../monitoring/; ./run_minni_local.sh; cd -", shell=True)
                subprocess.call("sleep 5", shell=True)
