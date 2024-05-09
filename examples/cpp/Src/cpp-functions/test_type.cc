#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

#include<iostream>
#include<string>

namespace testtype {
  struct A {
    double d;
  };

  enum x {a, b, c};

  void test_type_cast(void) {
    std::cout << x::a << std::endl;
    std::cout << x::b << std::endl;
    std::cout << x::c << std::endl;
    std::cout << x::a << std::endl;
    std::cout << "" << std::endl;
  }

  auto add(int a, int b) {
    return a + b;
  }

  void test_auto(void) {
    auto x = 1;
    auto y = add(1, 2);
    auto a = {1, 2, 3};
    // auto b = {1, 2, 3.0}; // error

    int c = 3;
    decltype(c) d = 2;  // int

    int& r_a = c;
    decltype(r_a) r_b = d;  // int&

    int&& xx = 3;
    decltype(xx) yy = 2;  // int&&

    A* aa;
    decltype(aa->d) dd = 0.1;  // double

    auto z = 'a';
    auto pptr = &r_a;  // pointer to a pointer

    /*
      ‘i’ for integers, ‘d’ for doubles,
      ‘f’ for float, ‘c’ for char, 
      Pi’ for the pointer to the integer,
      ‘Pd’ for the pointer to double,’
      Pf’ for the pointer to float, 
      ‘Pc’ for the pointer to char,
      ‘PPi’ for the pointer to pointer to integer.
      Single Pointer results in  prefix ‘P’,
      double-pointer results in ‘PP’ as a prefix and so on.
    */
    std::cout << typeid(x).name() << std::endl
        << typeid(y).name() << std::endl
        << typeid(z).name() << std::endl
        << typeid(c).name() << std::endl
        << typeid(r_a).name() << std::endl
        << typeid(pptr).name() << std::endl;
  }

  int& foo_lref();
  int&& foo_rref();
  int foo_value();
  template <typename T>
  std::string type_name() {
      // https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c
      typedef typename std::remove_reference<T>::type TR;
      std::unique_ptr<char, void(*)(void*)> own(
  #ifndef _MSC_VER
      abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                  nullptr, nullptr),
  #else
      nullptr,
  #endif
      std::free);

      std::string r = own != nullptr ? own.get() : typeid(TR).name();
      if (std::is_const<TR>::value)
          r += " const";
      if (std::is_volatile<TR>::value)
          r += " volatile";
      if (std::is_lvalue_reference<T>::value)
          r += "&";
      else if (std::is_rvalue_reference<T>::value)
          r += "&&";
      return r;
  };

  void test_print_decltype(void) {
      int i = 0;
      const int ci = 0;
      std::cout << "decltype(i) is "
                << type_name<decltype(i)>() << '\n';
      std::cout << "decltype((i)) is "
                << type_name<decltype((i))>() << '\n';
      std::cout << "decltype(ci) is "
                << type_name<decltype(ci)>() << '\n';
      std::cout << "decltype((ci)) is "
                << type_name<decltype((ci))>() << '\n';
      std::cout << "decltype(static_cast<int&>(i)) is "
                << type_name<decltype(static_cast<int&>(i))>() << '\n';
      std::cout << "decltype(static_cast<int&&>(i)) is "
                << type_name<decltype(static_cast<int&&>(i))>() << '\n';
      std::cout << "decltype(static_cast<int>(i)) is "
                << type_name<decltype(static_cast<int>(i))>() << '\n';
      std::cout << "decltype(foo_lref()) is "
                << type_name<decltype(foo_lref())>() << '\n';
      std::cout << "decltype(foo_rref()) is "
                << type_name<decltype(foo_rref())>() << '\n';
      std::cout << "decltype(foo_value()) is "
                << type_name<decltype(foo_value())>() << '\n';
  }

  int test_const_var(const int &x) {
    return x;
  }

  void test_const(void) {
    int test_const_x = 10;
    test_const_x = test_const_var(test_const_x);
    std::cout << "test_const_x : " << test_const_x << std::endl;
  }

  void test_type(void) {
    test_type_cast();
    test_auto();
    test_print_decltype();
    test_const();
  }
}