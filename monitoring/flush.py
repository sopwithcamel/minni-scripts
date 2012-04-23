import select
import sys
import os

while True:
    select.select([open("./flush_pipe")], [], [])
    sys.stdin.read()
    os.system("sync")
    os.system("sysctl vm.drop_caches=3")
