#include <iostream>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "pagerank.pb.h"

using namespace std;
using namespace google::protobuf::io;

class PAO {
  public:
    pagerank::pao pb;
};

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
    google::protobuf::io::ZeroCopyOutputStream *raw_output;
    google::protobuf::io::CodedOutputStream* coded_output;
    ofstream* of;
    of = new ofstream(outfile, ios::out);
    raw_output = new OstreamOutputStream(of);
    coded_output = new CodedOutputStream(raw_output);
//    coded_output->SetTotalBytesLimit(107374182400, -1);

    PAO* pao = new PAO();
    vector<string> prev_links;
    string prev = "";
    long num_key = 0;
        
    while (getline(*f, line)) {
        stringstream ss(line);
        string key, val;
        getline(ss, key, '\t');
        getline(ss, val, '\r');
        if (prev.compare(key)) {// different from prev
            if (prev.compare("")) {// prev not null
//                cout << num_key << ", " << prev << ": ";
//                for (int i=0; i<prev_links.size(); i++) cout << prev_links[i] << ", ";
//                cout << endl;

                // set up new PAO
                pao->pb.set_key(prev);
                pao->pb.set_rank(1.0);
                int num_links = prev_links.size();
                pao->pb.mutable_links()->Reserve(num_links);
//                cerr << "links: " << num_links << endl;
                for (int i=0; i<num_links; i++)
                    *(pao->pb.mutable_links()->Add()) = prev_links[i];
                // write size and then serialize PAO
                coded_output->WriteVarint32(pao->pb.ByteSize());
                pao->pb.SerializeToCodedStream(coded_output);
                // clear existing PAO state
                pao->pb.mutable_links()->Clear();
                // clear prev state
                prev_links.clear();            
                prev = "";
            }
            num_key++;
            prev = key; // set new prev
            prev_links.push_back(val);
        } else
            prev_links.push_back(val);
    }

    delete coded_output;
    delete raw_output;
    delete of;
    delete f;
}
