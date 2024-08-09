
#pragma once
#include <iostream>
#include <memory>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

// class StaticComponentInClass {
//  public:
//   static std::string get_static_member() {
//     if (_static_member.empty()) {
//       return "none";
//     }
//     return "_static_member";
//   }
//   static void set_static_member(const std::string& value) {
//     if(value.empty()){
//       return;
//     }
//     _static_member = value;
//   }
//   static std::string get_install_path() {
//     return GetInstance().get_static_member();
//   }
//  private:
//   static StaticComponentInClass& GetInstance() {
//     static StaticComponentInClass instance;
//     return instance
//   }
//   static std::string _static_member;
// };


template <class T1, typename T2>
static void do_function(const T1* base_class){
  // std::cout << base_class->get_info<T2>(static_cast<T2>(M_PI)) << std::endl;
}

template <class T1, typename T2>
static void do_function(std::shared_ptr<T1>&& base_class){
  // std::cout << base_class->get_info<T2>(static_cast<T2>(M_PI)) << std::endl;
}

// what is difference class and typename?
// class is class ㅋ
// typename is such as float32
class BaseClassA {
 public:
  virtual void print_function(float num) = 0;
  virtual ~BaseClassA() = default;
 
  template <typename T> 
  T get_info (T* a) {
    T* b = 10*a;
    return b;
  }
  /// Disable copy assignament/ctr by declaring move operator
  BaseClassA& operator=(BaseClassA&&) = default;

 protected:
   BaseClassA() = default;
};

class BaseClassB {
 public:
  template <typename T> 
  T get_info (T* a) {
    T* b = a;
    return b;
  }
};

class ParentClassA: public BaseClassA {
 public:
  ParentClassA(): BaseClassA() {}
  virtual ~ParentClassA() {
    std::cout << "deconstruct ParentClassA" << std::endl;
  };

  void print_function(float num) final {
    print_function<float>(num);
  }

  // Cannot reach this function from outside
  template <typename T>
  void print_function(T num) {
    std::cout << std::to_string(num) << std::endl;
  }

 private:
  ParentClassA& operator=(const ParentClassA&) = delete;
  ParentClassA(const ParentClassA&) = delete;
};

void test_static_component_in_class(void) {
//   // StaticComponentInClass obj;
//   StaticComponentInClass::set_static_member("test");
//   std::cout << StaticComponentInClass::get_static_member() << std::endl;
//   StaticComponentInClass::set_static_member("");
//   std::cout << StaticComponentInClass::get_static_member() << std::endl;
}

void test_template_class(void) {
  std::unique_ptr<BaseClassA> a_class;
  a_class.reset(new ParentClassA());

  std::cout << "test_template_class" << std::endl;

  float x = 10.123;
  int y = 123;
  a_class->print_function(x); 
  a_class->print_function(y);

  // std::shared_ptr<ParentClassA> a_class = std::shared_ptr<ParentClassA>();
  // BaseClassB b_class = BaseClassB();
  // do_function<BaseClassA, float>(std::move(a_class));
  // do_function<BaseClassB, float>(&b_class);
}