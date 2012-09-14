#include <iostream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/binary_object.hpp> 
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3) {
        fprintf(stderr, "./genpr <input> <proto_input>\n");
        exit(1);
    }
    string line;
    
    char* inpfile = argv[1];
    ifstream* f;
    f  = new ifstream(inpfile, ios::in);

    char* outfile = argv[2];
    boost::archive::binary_oarchive* oa;
    ofstream* of;

    of = new ofstream(outfile, ios::out);
    oa = new boost::archive::binary_oarchive(*of);

    vector<string> prev_links;
    string prev = "";
    long num_key = 0;
        
    while (getline(*f, line)) {
        stringstream ss(line);
        string key, val;
        getline(ss, key, '\t');
        getline(ss, val, '\r');
        string buf;
        if (prev.compare(key)) {// different from prev
            if (prev.compare("")) {// prev not null
//                cout << num_key << ", " << prev << ": ";
//                for (int i=0; i<prev_links.size(); i++) cout << prev_links[i] << ", ";
//                cout << endl;

                int num_links = prev_links.size();
                float pr = 1.0;

                // write size and then serialize PAO
                uint32_t len = prev.size();
                (*oa) << len;
                (*oa) << prev;
                (*oa) << pr;
                (*oa) << num_links;
                // copy links into buffer
                for (int i=0; i<num_links; i++) {
                    buf.append(prev_links[i]);
                    if (i < num_links-1)
                        buf.append(" ");
                }
                len = buf.size();
                (*oa) << len;
                (*oa) << buf;
                // clear prev state
                prev_links.clear();            
                prev = "";
                buf = "";
            }
            num_key++;
            prev = key; // set new prev
            prev_links.push_back(val);
        } else
            prev_links.push_back(val);
    }

    delete oa;
    delete f;
}
