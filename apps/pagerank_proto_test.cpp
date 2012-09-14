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

bool deserialize(PAO* p, CodedInputStream* input)
{
    uint32_t bytes;
    input->ReadVarint32(&bytes);
    CodedInputStream::Limit msgLimit = input->PushLimit(bytes);
    bool ret = p->pb.ParseFromCodedStream(input);
    input->PopLimit(msgLimit);
    return ret;
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        fprintf(stderr, "./testpr <input> <log>\n");
        exit(1);
    }
    char* inpfile = argv[1];
    string line;
    google::protobuf::io::ZeroCopyInputStream *raw_input;
    google::protobuf::io::CodedInputStream* coded_input;
    ifstream* f;

    f = new ifstream(inpfile, ios::in);
    raw_input = new IstreamInputStream(f);

    char* outfile = argv[2];
    ofstream* of = new ofstream(outfile, ios::out);
    
    PAO* pao = new PAO();
    long num_des = 0;
        
    while (true) {
        coded_input = new CodedInputStream(raw_input);
        coded_input->SetTotalBytesLimit(1073741824, -1);
        for (int i=0; i < 10000; i++) {
            if (deserialize(pao, coded_input)) {
                num_des++;
                stringstream ss;
                ss << pao->pb.key() << ", " << pao->pb.rank() << endl;
                *of << ss.str();
            } else {
                fprintf(stderr, "Deserialized %ld\n", num_des);
                delete coded_input;
                goto exit_loop;
            }
        }
        delete coded_input;
    }

exit_loop:
    delete of;
    delete raw_input;
    delete f;
}
