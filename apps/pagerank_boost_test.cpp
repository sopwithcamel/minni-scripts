#include <iostream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/binary_object.hpp> 
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "pagerank.pb.h"

using namespace std;

bool deserialize(boost::archive::binary_iarchive* input, ofstream* of)
{
    try {
        uint32_t len;
        (*input) >> len;
        char* key = (char*)malloc(len + 1);
        string key_string;
        (*input) >> key_string;
        strcpy(key, key_string.c_str());
        (*of) << key_string << " ";
        float rank;
        (*input) >> rank;
        (*of) << rank << " ";
        uint32_t num_links;
        (*input) >> num_links;
        (*of) << num_links << " ";
        string links;
        if (num_links > 0) {
            (*input) >> len;
            (*input) >> links;
            (*of) << links << "\n";
        }
        return true;
    } catch (...) {
        return false;
    }
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        fprintf(stderr, "./testbst <input> <log>\n");
        exit(1);
    }
    char* inpfile = argv[1];
    string line;
    ifstream* f;

    f = new ifstream(inpfile, ios::in);
    boost::archive::binary_iarchive* ia = new
            boost::archive::binary_iarchive(*f);

    char* outfile = argv[2];
    ofstream* of = new ofstream(outfile, ios::out);
    
    long num_des = 0;
        
    while(deserialize(ia, of)) {
            num_des++;
    }

    fprintf(stderr, "Deserialized %ld\n", num_des);

    delete of;
    delete ia;
    delete f;
}
