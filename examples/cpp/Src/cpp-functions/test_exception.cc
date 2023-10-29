// https://modoocode.com/230

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
 public:
  Vector(size_t size) : size_(size) {
    data_ = new T[size_];
    for (int i = 0; i < size_; i++) {
      data_[i] = 3;
    }
  }
  const T& at(size_t index) const {
    if (index >= size_) {
      throw std::out_of_range("vector 의 index 가 범위를 초과하였습니다.");
    }
    return data_[index];
  }
  ~Vector() { delete[] data_; }

 private:
  T* data_;
  size_t size_;
};

void test_excpetion_example_1(void) {
  Vector<int> vec(3);

  int index, data = 0;
//   std::cin >> index;
  index = 1;

  try {
    data = vec.at(index);
  } catch (std::out_of_range& e) {
    std::cout << "예외 발생 ! " << e.what() << std::endl;
  }
  // 예외가 발생하지 않았다면 3을 이 출력되고, 예외가 발생하였다면 원래 data 에
  // 들어가 있던 0 이 출력된다.
  std::cout << "읽은 데이터 : " << data << std::endl;
}

class Resource {
 public:
  Resource(int id) : id_(id) {}
  ~Resource() { std::cout << "리소스 해제 : " << id_ << std::endl; }

 private:
  int id_;
};

int func3() {
  Resource r(3);
  throw std::runtime_error("Exception from 3!\n");
}
int func2() {
  Resource r(2);
  func3();
  std::cout << "실행 안됨!" << std::endl;
  return 0;
}
int func1() {
  Resource r(1);
  func2();
  std::cout << "실행 안됨!" << std::endl;
  return 0;
}

void test_excpetion_example_2(void) {
  try {
    func1();
  } catch (std::exception& e) {
    std::cout << "Exception : " << e.what();
  }
}

int func_throw_exceptions(int c) {
  if (c == 1) {
    throw 10;
  } else if (c == 2) {
    throw std::string("hi!");
  } else if (c == 3) {
    throw 'a';
  } else if (c == 4) {
    throw "hello!";
  }
  return 0;
}

void test_excpetion_example_3(void) {
  int c;
//   std::cin >> c;
  c = 3;

  try {
    func_throw_exceptions(c);
  } catch (char x) {
    std::cout << "Char : " << x << std::endl;
  } catch (int x) {
    std::cout << "Int : " << x << std::endl;
  } catch (std::string& s) {
    std::cout << "String : " << s << std::endl;
  } catch (const char* s) {
    std::cout << "String Literal : " << s << std::endl;
  }
}


class Parent : public std::exception {
 public:
  virtual const char* what() const noexcept override {
    return "Parent!\n"; }
};

class Child : public Parent {
 public:
  const char* what() const noexcept override { return "Child!\n"; }
};

int func_inheritance(int c) {
  if (c == 1) {
    throw Parent();
  } else if (c == 2) {
    throw Child();
  }
  return 0;
}

void test_excpetion_example_4(void) {
  int c;
//   std::cin >> c;
  c = 2;

  try {
    func_inheritance(c);
  } catch (Parent& p) {
    std::cout << "Parent Catch!" << std::endl;
    std::cout << p.what();
  } catch (Child& c) {
    std::cout << "Child Catch!" << std::endl;
    std::cout << c.what();
  }

  try {
    func_inheritance(c);
  } catch (Child& c) {
    std::cout << "Child Catch!" << std::endl;
    std::cout << c.what();
  }catch (Parent& p) {
    std::cout << "Parent Catch!" << std::endl;
    std::cout << p.what();
  }
}

void test_excpetion_example_5(void) {
  int c;
//   std::cin >> c;
  c = 2;

  try {
    func_throw_exceptions(c);
  } catch (int e) {
    std::cout << "Catch int : " << e << std::endl;
  } catch (...) {
    std::cout << "Default Catch!" << std::endl;
  }
}

int foo() noexcept {}

int bar() noexcept { throw 1; }

int test_excpetion_example_6() {
  foo();
  try {
    bar();
  } catch (int x) {
    std::cout << "Error : " << x << std::endl;
  }
}

void test_exception(void) {
    std::cout << "test_exception\n";
    test_excpetion_example_1();     // throw exception
    test_excpetion_example_2();     // stack unwinding
    test_excpetion_example_3();     // throw different types and catch
    test_excpetion_example_4();     // exception inheritance and catch
    test_excpetion_example_5();     // catch all
    // test_excpetion_example_6();     //  noexcept
}