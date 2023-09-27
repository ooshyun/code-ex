// https://modoocode.com/293

#include <iostream>
template <int N>
struct Factorial {
  static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
  static const int value = 1;
};

template <int N>
struct A {
  int operator()() { return N; }
};

constexpr int FactorialConstExpr(int n) {
  int total = 1;
  for (int i = 1; i <= n; i++) {
    total *= i;
  }
  return total;
}

template <int N>
struct B {
  int operator()() { return N; }
};

void test_constexp(void) {
  // 컴파일 타임에 값이 결정되므로 템플릿 인자로 사용 가능!
  A<Factorial<10>::value> a;
  std::cout << a() << std::endl;

  A<FactorialConstExpr(10)> a2;
  std::cout << a2() << std::endl;
}