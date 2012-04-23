sudo sysctl vm.drop_caches=3
#echo "Starting workdaemons..."
export LD_PRELOAD="/usr/local/lib/libhoard.so" 
/net/hu17/hamur3/code/minni/src/worker/gen-cpp/workdaemon &> /localfs/hamur/wlog 
