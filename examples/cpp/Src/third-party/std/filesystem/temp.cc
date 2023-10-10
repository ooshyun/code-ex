#include<iostream>
#include<fstream>
#include<filesystem>

namespace fs = std::__fs::filesystem;


void test_temp_file(void) {
    fs::path file_data = "/Users/seunghyunoh/workplace/examplace/practice"
                        "/examples/cpp/Src/third-party"
                        "/std/filesystem/sample.txt";
    // char *temp_file1 = strdup("/tmp/tmpfileXXXXXX");
    std::string temp_file1 = "/tmp/tmpfileXXXXXX";
    mkstemp(&temp_file1[0]);
    // mkstemp(&temp_file1);
    char *temp_file2 = strdup("/tmp/tmpfileXXXXXX");
    mkstemp(temp_file2);


    // fs::path temp_dir = fs::temp_directory_path();
    // std::cout << "temp_dir: " << temp_dir << std::endl;
    // fs::path temp_file = fs::temp_directory_path() / "temp.txt";

    std::cout << "temp_file: " << temp_file1 << std::endl;
    std::cout << "temp_file: " << temp_file2 << std::endl;
    // std::ofstream ofs(temp_file1);
    std::ifstream ifs(file_data);
    // ofs << ifs.rdbuf() << std::endl;
    // std::cout << ifs.rdbuf() << std::endl;
    // ofs << std::fstream(file_data, std::ios::in).rdbuf() << std::endl;
    std::fstream(temp_file1, std::ios::out)
            << std::fstream(file_data, std::ios::in).rdbuf()
            // << ifs.rdbuf()
            << std::endl;
    std::ifstream ofs(temp_file1);
    std::cout << "---" << std::endl;
    std::cout << ofs.rdbuf() << std::endl;

    ofs.close();
    ifs.close();

    // remove all data
    // std::fstream(file_data, std::ios::out | std::ios::trunc);

    fs::remove(temp_file1);
    fs::remove(temp_file2);
}