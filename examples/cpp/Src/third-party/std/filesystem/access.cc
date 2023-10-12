#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::__fs::filesystem;

void test_file_access(void) {
    std::ifstream iof("/Users/seunghyunoh/workplace/examplace/"
                    "practice/examples/cpp/Src/third-party/"
                    "std/filesystem/sample.txt");
    std::ifstream iof2("/Users/seunghyunoh/workplace/examplace/"
                    "practice/examples/cpp/Src/third-party/"
                    "std/filesystem/sample.txt");

    if (iof.is_open()) {
        std::cout << "file iof is open" << std::endl;
    } else {
        std::cout << "file iof is not open" << std::endl;
    }

    if (iof2.is_open()) {
        std::cout << "file iof2 is open" << std::endl;
    } else {
        std::cout << "file iof2 is not open" << std::endl;
    }

    iof.close();
    iof2.close();
}