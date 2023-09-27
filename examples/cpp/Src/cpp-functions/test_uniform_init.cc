// https://modoocode.com/286

#include <iostream>
#include <map>
#include <string>
#include <vector>

class A {
 public:
  A() { std::cout << "A 의 생성자 호출!" << std::endl; }
  A(int x) { std::cout << "int A 의 생성자 호출!" << std::endl; }
  A(double x, double y) {
    std::cout << "int, double A 의 생성자 호출!" << std::endl; }
  A(std::initializer_list<int> l) {
    std::cout << "initializer_list A 의 생성자 호출!" << std::endl;
    for (auto itr = l.begin(); itr != l.end(); ++itr) {
      std::cout << *itr << std::endl;
    }
  }
  A(std::initializer_list<std::string> lst) {
    std::cout << "str 초기화자 사용 생성자! " << std::endl;
  }
};

class B
{
 public:
  B(A a) { std::cout << "B 의 생성자 호출!" << std::endl; }
};

template <typename T>
void print_vec(const std::vector<T>& vec) {
  std::cout << "[";
  for (const auto& e : vec) {
    std::cout << e << " ";
  }
  std::cout << "]" << std::endl;
}

template <typename K, typename V>
void print_map(const std::map<K, V>& m) {
  for (const auto& kv : m) {
    std::cout << kv.first << " : " << kv.second << std::endl;
  }
}


void test_uniform_init(void)
{
  A a();  // ?
  B b(A());

  A a2 = A();
  A a3{}; // uniform initialization

  A a4(3.5);  // narrow conversion O
  // A a5{3.5};  // narrow conversion X - compile error

  A a6 = {1, 2, 3, 4, 5};

  std::vector<int> v = {1, 2, 3, 4, 5};
  print_vec(v);

  std::cout << "----------------------" << std::endl;
  std::map<std::string, int> m = {
    {"abc", 1}, {"hi", 3}, {"hello", 5}, {"c++", 2}, {"java", 6}};
  print_map(m);


  std::vector<int> v2{10};  // size 1
  std::vector<int> v3(10);  // size 10

  A a7(3, 1.5);  // Good
  // A b7{3, 1.5};  // Bad! initializer_list is first compile error
  // if there's only std::initializer_list<std::string>, then it didn't raise error
  A c{"abc", "def"};  // 초기화자
}