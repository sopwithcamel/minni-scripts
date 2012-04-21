python vary_cbt_fanout.py &> res1.txt
sleep 50
python vary_cbt_buffer_size.py &> res2.txt
sleep 50
python vary_input.py &> res3.txt
