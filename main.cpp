#include "example.pb.h"
#include <fstream>
#include <iostream>
#include "string.h"
#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using google::protobuf::TextFormat;
using google::protobuf::io::FileOutputStream;
using google::protobuf::io::ZeroCopyOutputStream;
using google::protobuf::io::FileInputStream;
using google::protobuf::io::ZeroCopyInputStream;

 int main(void)
 {
   
    example::Person msg1;
    // msg1.set_age(101);
    // std::string name = "q";
    // msg1.set_name(name);
    std::string func_memory = "../example.txt";
    // 1. 打开文件
    std::ifstream fin(func_memory);
    if (!fin.is_open()) {
        std::cerr << "Failed to open file: " << func_memory << std::endl;
        return false;
    }

    // 2. 创建ZeroCopyInputStream
    google::protobuf::io::IstreamInputStream input_stream(&fin);

    // 3. 使用TextFormat解析
    if (!google::protobuf::TextFormat::Parse(&input_stream, &msg1)) {
        std::cerr << "Failed to parse text format proto from file: " << func_memory << std::endl;
        fin.close();
        return false;
    }

    fin.close();

    if(msg1.has_name()){
        std::cout << "has name = " << msg1.name() << std::endl;
    }else{
        std::cout << "has not name " << std::endl;
        msg1.set_name("b");
    }
    if(msg1.has_age()){
        std::cout << "has age = " << msg1.age() << std::endl;
    }else{
        std::cout << "has not age " << std::endl;
        msg1.set_age(102);
        std::cout << msg1.age() << std::endl;
    }







    
    // int fd = open(func_memory.c_str(),O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    // std::string text;
    // google::protobuf::io::FileOutputStream output(fd);
    // TextFormat::Print(msg1,&output);
    

    

    return 0;
 }