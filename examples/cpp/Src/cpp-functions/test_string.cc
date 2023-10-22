
#include "boost/filesystem.hpp"
#include "boost/filesystem/fstream.hpp"

#include <iostream>
#include <string>

void test_string(void) {
    boost::filesystem::path full_path(boost::filesystem::current_path());
    std::cout << "Current path is : " << full_path << std::endl;
    std::string folder = full_path.string();
    folder = folder.substr(0, folder.find_last_of("/"));
    std::cout << "Current path without / :" << folder << std::endl;

    char* ptr_x = 0;
    std::string str_x;
    if (ptr_x == nullptr) {
        std::cout << "ptr_x is null" << std::endl;
    } else {
        std::cout << "ptr_x is not null" << std::endl;
        str_x = std::string(ptr_x);
    }

    std::cout << "Testing empty char pointer...\n";
    if (str_x.empty()) {
        std::cout << "str_x is empty" << std::endl;
    } else {
        std::cout << "str_x is not empty" << std::endl;
    }
}