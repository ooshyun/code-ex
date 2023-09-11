#include <iostream>

class A_copy_elision {
  int data_;

 public:
  A_copy_elision(int data) : data_(data) { std::cout << "일반 생성자 호출!" << std::endl; }

  A_copy_elision(const A_copy_elision& a) : data_(a.data_) {
    std::cout << "복사 생성자 호출!" << std::endl;
  }
};

void test_copy_elision(void) {
  A_copy_elision a(1);  // 일반 생성자 호출
  A_copy_elision b(a);  // 복사 생성자 호출

  // 그렇다면 이것은?
  // Compiler Elision of Copy
  A_copy_elision c(A_copy_elision(2));
}