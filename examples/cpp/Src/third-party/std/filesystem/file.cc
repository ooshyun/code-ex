#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::__fs::filesystem;

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void test_file_read(void) {
    std::ifstream iof("/Users/seunghyunoh/workplace/examplace/"
    "practice/examples/cpp/Src/third-party/std/filesystem/"
    "sample_empty.txt");

    if (is_empty(iof)) {
        std::cout << "empty file" << std::endl;
    } else {
        std::cout << "not empty file" << std::endl;
    }

    iof.close();
}

