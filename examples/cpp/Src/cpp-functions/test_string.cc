
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

    char* tmp_char_ptr;
    size_t tmp_size = 0;
    const size_t size = 14;
    char char_ptr_y[size]="Hello World";
    tmp_char_ptr = &char_ptr_y[0];
    while (*tmp_char_ptr != '\0') {
        std::cout << "char_ptr_y["
                << tmp_size
                << "] : "
                << *tmp_char_ptr
                << std::endl;
        tmp_size++;
        tmp_char_ptr++;
    }
    tmp_size = 0;

    std::string str_y(static_cast<char *>(char_ptr_y), size);
    std::cout << "str_y : " << str_y << std::endl;
    std::cout << "str_y size : " << str_y.size() << std::endl;
    std::string str_z = "+Hello World";
    tmp_char_ptr = &str_z[0];
    while (*tmp_char_ptr != '\0') {
        std::cout << "str_z["
                << tmp_size
                << "] : "
                << *tmp_char_ptr
                << std::endl;
        tmp_size++;
        tmp_char_ptr++;
    }
    tmp_size = 0;

    std::cout << "str_z : " << str_z << std::endl;
    // confirm last of string has \0
    std::cout<< "str_z size : " << str_z.size() << std::endl;
    std::cout << "Start:" << str_y + str_z << std::endl;

}