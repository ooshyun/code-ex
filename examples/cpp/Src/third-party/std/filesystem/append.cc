#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::__fs::filesystem;
void test_append_file(void) {
  fs::path file_data = "/Users/seunghyunoh/workplace/examplace"
                      "/practice/examples/cpp/Src/third-party"
                      "/std/filesystem/sample.txt";

  fs::path file_data_append = "/Users/seunghyunoh/workplace/examplace"
                              "/practice/examples/cpp/Src/third-party"
                              "/std/filesystem/sample_append.txt";
  // Append a file
  // std::cout << "file_data: " << file_data << std::endl;
  std::ofstream out_file(file_data, std::ios_base::binary | std::ios_base::app);
  std::ifstream in_file(file_data_append, std::ios_base::binary);
  out_file.seekp(0, std::ios::end);
  // std::cout << in_file.rdbuf() << std::endl;
  out_file << in_file.rdbuf();
  in_file.close();
  out_file.close();
}