#include <iostream>

class A_rvalue_simple {
 public:
  A_rvalue_simple() { std::cout << "ctor\n"; }
  A_rvalue_simple(const A_rvalue_simple& a) { std::cout << "copy ctor\n"; }
  A_rvalue_simple(A_rvalue_simple&& a) { std::cout << "move ctor\n"; }
};

class B_rvalue_simple {
 public:
  B_rvalue_simple(const A_rvalue_simple& a) : a_(a) {}
  B_rvalue_simple(A_rvalue_simple&& a) : a_(std::move(a)) {}

  A_rvalue_simple a_;
};

// template <typename T>
// void wrapper(T u) {
//   g_perfect_forward(u);
// }

// template <typename T>
// void wrapper(T& u) {
//   std::cout << "T& 로 추론됨" << std::endl;
//   g_perfect_forward(u);
// }

// template <typename T>
// void wrapper(const T& u) {
//   std::cout << "const T& 로 추론됨" << std::endl;
//   g_perfect_forward(u);
// }

template <typename T>
void wrapper(T&& u) {
  g_perfect_forward(std::forward<T>(u));
}

class A_perfect_forward {};

void g_perfect_forward(A_perfect_forward& a) {
  std::cout << "좌측값 레퍼런스 호출" << std::endl;
}
void g_perfect_forward(const A_perfect_forward& a) {
  std::cout << "좌측값 상수 레퍼런스 호출" << std::endl;
}
void g_perfect_forward(A_perfect_forward&& a) {
  std::cout << "우측값 레퍼런스 호출" << std::endl;
}

void test_rvalue_simple(void) {
  A_rvalue_simple a;

  std::cout << "---------" << std::endl;
  A_rvalue_simple b(a);

  std::cout << "---------" << std::endl;
  A_rvalue_simple c(std::move(a));

  std::cout << "create D-- \n";
  B_rvalue_simple d(a);
  B_rvalue_simple e(std::move(a));

  //////////////////

  A_perfect_forward a_pf;
  const A_perfect_forward ca_pf;

  std::cout << "원본 --------" << std::endl;
  g_perfect_forward(a_pf);
  g_perfect_forward(ca_pf);
  g_perfect_forward(A_perfect_forward());

  std::cout << "Wrapper -----" << std::endl;
  wrapper(a_pf);
  wrapper(ca_pf);
  wrapper(A_perfect_forward());

  int && rxval = 10;
  std::cout << "rxval: " << rxval << std::endl;
  
  /*
    typedef int& T;
    T& r1;   // int& &; r1 은 int&
    T&& r2;  // int & &&;  r2 는 int&

    typedef int&& U;
    U& r3;   // int && &; r3 는 int&
    U&& r4;  // int && &&; r4 는 int&&
  */
}