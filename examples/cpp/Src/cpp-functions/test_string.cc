
#include "boost/filesystem.hpp"
#include "boost/filesystem/fstream.hpp"

#include <iostream>
#include <string>

enum TestEnum2String {
  TestEnum2String0,
  TestEnum2String1,
  TestEnum2String2,
};

// // compile error
// enum TestEnum2String2 {
//   TestEnum2String0, // overlap
//   TestEnum2String3,
//   TestEnum2String4,
// };

enum struct TestEnumStruct2String {
  TestEnum2String0,
  TestEnum2String1,
  TestEnum2String2,
};


enum class TestEnumClass2String {
  TestEnum2String0,
  TestEnum2String1,
  TestEnum2String2,
};

void test_string(void) {
  boost::filesystem::path full_path(boost::filesystem::current_path());
  std::cout << "Current path is : " << full_path << std::endl;
  std::string folder = full_path.string();
  folder = folder.substr(0, folder.find_last_of("/"));
  std::cout << "Current path without / :" << folder << std::endl;

  char *ptr_x = 0;
  std::string str_x;
  if (ptr_x == nullptr) {
    std::cout << "ptr_x is null" << std::endl;
  }
  else {
    std::cout << "ptr_x is not null" << std::endl;
    str_x = std::string(ptr_x);
  }

  std::cout << "Testing empty char pointer...\n";
  if (str_x.empty())
    std::cout << "str_x is empty" << std::endl;
  else
    std::cout << "str_x is not empty" << std::endl;

  char *tmp_char_ptr;
  size_t tmp_size = 0;
  const size_t size = 14;
  char char_ptr_y[size] = "Hello World";
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
  std::cout << "str_z size : " << str_z.size() << std::endl;
  std::cout << "Start:" << str_y + str_z << std::endl;

  std::string str_a;
  if (str_a == "HelloWorld")
    std::cout << "str_a is HelloWorld" << std::endl;
  else
    std::cout << "str_a is not HelloWorld" << std::endl;

  // https://stackoverflow.com/questions/56710024/what-is-a-raw-string
  std::cout << "=================\n";
  std::string normal_str = "First line.\nSecond line.\nEnd of message.\n";
  std::string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";
  std::string raw_str_delim = R"x("(First line.\nSecond line...)")x";

  std::cout << normal_str << std::endl;
  std::cout << raw_str << std::endl;
  std::cout << raw_str_delim << std::endl;

  std::cout << R"(Jim "king" Tutt uses \n instead of endl.)" << std::endl;
  std::cout << R"+*(Jim "king" Tutt uses \n instead of endl.)+*" << std::endl;
  std::cout << R"DEL(Jim
               "king"
               Tutt uses \n instead of endl.)DEL" << std::endl;
  wchar_t abc[] = LR"(blah blah blah)";
  // TYPE:wchar_t 를 의미하는 Prefix "L"
  // TYPE:Raw string 을 의미하는 Prefix "R"
  std::cout << "=================\n";

  enum TestEnum2String test_enum2string = TestEnum2String::TestEnum2String0;
  std::cout << "test_enum2string : " << test_enum2string
            << std::endl;

  std::cout << "test_enum2string : " << std::to_string(test_enum2string)
            << std::endl;

  // compile error
  // enum TestEnumStruct2String test_enumstruct2string =
  //     TestEnumStruct2String::TestEnum2String0;
  // std::cout << "test_enumstruct2string : " << test_enumstruct2string
  //           << std::endl;

  // // compile error
  // enum TestEnumClass2String test_enumclass2string =
  //     TestEnumClass2String::TestEnum2String0;
  // std::cout << "test_enumclass2string : " << test_enumclass2string
  //           << std::endl;
}