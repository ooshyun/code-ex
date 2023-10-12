#include<fstream>
#include<iostream>
#include<filesystem>
namespace fs = std::__fs::filesystem;

void test_copy_fs(void) {
    fs::path src_path("./1.txt");
    fs::path dst_path("./2.txt");
    if(fs::exists(src_path)) 
        fs::copy(src_path, dst_path);
    else{
        std::cout << "src_path not exist" << std::endl;
        std::ofstream os(src_path, std::ios::app);
        os << "src_path not exist" << std::endl;

        fs::copy(src_path, dst_path);
    }
}