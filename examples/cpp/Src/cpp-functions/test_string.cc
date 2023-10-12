
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
}