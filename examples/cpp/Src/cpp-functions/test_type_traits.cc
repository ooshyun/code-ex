/*
    MIT License

  Copyright (c) 2023 Seunghyun Oh

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <set>
#include <vector>
#include <iostream>

template <typename T>
struct is_void {
  static constexpr bool value = false;
};

template <>
struct is_void<void> {
  static constexpr bool value = true;
};

template <typename T>
void tell_type() {
  if (is_void<T>::value) {
    std::cout << "T 는 void ! \n";
  } else {
    std::cout << "T 는 void 가 아니다. \n";
  }
}

int test_is_void() {
  tell_type<int>();   // void 아님!
  tell_type<void>();  // void!
  return 0;
}

class A {};

// 정수 타입만 받는 함수
template <typename T>
void only_integer(const T &t) {
  static_assert(std::is_integral<T>::value);
  std::cout << "T is an integer \n";
}

int test_only_integer() {
  int n = 3;
  only_integer(n);

  //   A a;
  //   only_integer(a); // compile error

  return 0;
}

class Aptr {
 public:
  int n;

  explicit Aptr(int n) : n(n) {}
};

void test_class_mem_int_ptr() {
  int Aptr::*p_n = &Aptr::n;

  Aptr a(3);
  std::cout << "a.n : " << a.n << std::endl;        // 3
  std::cout << "a.*p_n : " << a.*p_n << std::endl;  // 3, it can use only
                                                    // pointer to member
                                                    // variable
}

/*
    is_class in cpp refernece

namespace detail {
// if class member then it should refers (if no int, then it did not refer anything)
template <class T>
char test(int T::*);  // size will be 1
struct two {          // size will be 2
  char c[2];
};
template <class T>
two test(...);
}  // namespace detail

template <class T>
struct is_class
    : std::integral_constant<bool, sizeof(detail::test<T>(0)) == 1 &&
                                     !std::is_union<T>::value> {};
  
    1. std::integral_constant
      - std::integeral_constant<bool, false> -> false
      - std::integeral_constant<bool, true> -> true
    2. 

*/

template <typename T>
void test(typename T::x a) {
  std::cout << "T::x \n";
}

template <typename T>
void test(typename T::y b) {
  std::cout << "T::y \n";
}

struct ASFINAE {
  using x = int;
};

struct BSFINAE {
  using y = int;
};

void test_SFINAE() {
  test<ASFINAE>(33);

  test<BSFINAE>(22);
}

template <typename T,
          typename = typename std::enable_if<std::is_integral<T>::value>::type>
void test(const T &t) {
  std::cout << "t : " << t << std::endl;
}

// It can replace with below code
// template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
// void test(const T& t) {
//   std::cout << "t : " << t << std::endl;
// }

// template <bool B, class T = void>
// using enable_if_t = typename enable_if<B, T>::type;  // C++ 14 부터 사용 가능

template <class T>
inline constexpr bool is_integral_v =
  std::is_integral<T>::value;  // C++ 17 부터 사용 가능.

struct Astruct {};

void test_enable_if() {
  test(1);      // int
  test(false);  // bool
  test('c');    // char
  // test(Astruct()); /// compile error
}

template <typename T>
class vector {
 public:
  vector(size_t num, const T &element) {
    std::cout << element << " 를 " << num << " 개 만들기" << std::endl;
  }

  template <typename Iterator>  // vector<int> v(10, 3) call this constructor
  // if we have meta function, is_iterator
  //   template <typename Iterator,
  //             typename = std::enable_if_t<is_iterator<Iterator>::value>>
  vector(Iterator start, Iterator end) {
    std::cout << "반복자를 이용한 생성자 호출" << std::endl;
  }
};

void test_enable_if_vector() {
  vector<int> v(10, 3);
}

template <typename T, typename = decltype(std::declval<T>().func())>
void _test_enable_if_type(const T &t) {
  std::cout << "t.func() : " << t.func() << std::endl;
}

struct AEnableIfType {
  int func() const { return 1; }
};

struct BEnableIfType {
};

void test_enable_if_type() {
  _test_enable_if_type(AEnableIfType{});
  // _test_enable_if_type(BEnableIfType{}); // compile error
}

// T 는 반드시 정수 타입을 리턴하는 멤버 함수 func 을 가지고 있어야 한다.
template <typename T, typename = std::enable_if_t<
                        is_integral_v<decltype(std::declval<T>().func())>>>
void _test_enable_if_rettype(const T &t) {
  std::cout << "t.func() : " << t.func() << std::endl;
}

struct AEnableIfRetType {
  int func() const { return 1; }
};

struct BEnableIfRetType {
  char func() const { return 'a'; }
};

struct CEnableIfRetType {
  AEnableIfRetType func() const { return AEnableIfRetType{}; }
};


void test_enable_if_rettype() {
  _test_enable_if_rettype(AEnableIfRetType{});
  _test_enable_if_rettype(BEnableIfRetType{});
  // _test_enable_if_rettype(CEnableIfRetType{});  // compile error
}

/*
  template <class...>
  using void_t = void;

  void_t<A, B, C, D>  // --> 결국 void
*/

// template <typename Cont,
//           typename = decltype(std::declval<Cont>().begin()),
//           typename = decltype(std::declval<Cont>().end())>
// template <typename Cont,
//           typename = std::void_t<decltype(std::declval<Cont>().begin()),
//                                  decltype(std::declval<Cont>().end())>>
// void print(const Cont& container) {
// template <class...>
// using void_t = void;  // C++17
// template <typename Cont>
// void_t<decltype(std::declval<Cont>().begin()),  // C++17
//        decltype(std::declval<Cont>().end())>
template <typename Cont>
std::__void_t<decltype(std::declval<Cont>().begin()),
       decltype(std::declval<Cont>().end())>
print(const Cont& container) {
  std::cout << "[ ";
  for (auto it = container.begin(); it != container.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "]\n";
}

struct Bad {
  void begin();
};


int test_example_enableif() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  print(v);

  std::set<char> s = {'a', 'b', 'f', 'i'};
  print(s);

  // compile error
  // print(Bad{});

  // compile error, if using type not return type, then it will pass
  // print<Bad, void>(Bad{});
}

void test_type_traits(void)
{
  test_is_void();
  test_only_integer();
  test_class_mem_int_ptr();
  test_SFINAE();
  test_enable_if();
  test_enable_if_type();
  test_enable_if_rettype();
  test_example_enableif();
}
