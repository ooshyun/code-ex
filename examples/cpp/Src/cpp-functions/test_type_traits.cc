#include <set>
#include <vector>
#include <iostream>

template <typename T>
struct is_void
{
  static constexpr bool value = false;
};

template <>
struct is_void<void>
{
  static constexpr bool value = true;
};

template <typename T>
void tell_type()
{
  if (is_void<T>::value)
  {
    std::cout << "T 는 void ! \n";
  }
  else
  {
    std::cout << "T 는 void 가 아니다. \n";
  }
}

int test_is_void()
{
  tell_type<int>(); // void 아님!

  tell_type<void>(); // void!

  return 0;
}

class A
{
};

// 정수 타입만 받는 함수
template <typename T>
void only_integer(const T &t)
{
  static_assert(std::is_integral<T>::value);
  std::cout << "T is an integer \n";
}

int test_only_integer()
{
  int n = 3;
  only_integer(n);

  //   A a;
  //   only_integer(a); // compile error

  return 0;
}

class Aptr
{
public:
  int n;

  explicit Aptr(int n) : n(n) {}
};

void test_class_mem_int_ptr()
{
  int Aptr::*p_n = &Aptr::n;

  Aptr a(3);
  std::cout << "a.n : " << a.n << std::endl;
  std::cout << "a.*p_n : " << a.*p_n << std::endl;
}

/*
    is_class in cpp refernece

namespace detail {
// if class member then it should refers (if no int, then it did not refer anything)
template <class T>
char test(int T::*);
struct two {
  char c[2];
};
template <class T>
two test(...);
}  // namespace detail

template <class T>
struct is_class
    : std::integral_constant<bool, sizeof(detail::test<T>(0)) == 1 &&
                                     !std::is_union<T>::value> {};

*/

template <typename T>
void test(typename T::x a)
{
  std::cout << "T::x \n";
}

template <typename T>
void test(typename T::y b)
{
  std::cout << "T::y \n";
}

struct ASFINAE
{
  using x = int;
};

struct BSFINAE
{
  using y = int;
};

void test_SFINAE()
{
  test<ASFINAE>(33);

  test<BSFINAE>(22);
}

template <typename T,
          typename = typename std::enable_if<std::is_integral<T>::value>::type>
void test(const T &t)
{
  std::cout << "t : " << t << std::endl;
}
struct Astruct
{
};
void test_enable_if()
{
  test(1);     // int
  test(false);  // bool
  test('c');   // char
               //   test(Astruct()); /// compile error
}

template <typename T>
class vector
{
 public:
  vector(size_t num, const T &element) {
    std::cout << element << " 를 " << num << " 개 만들기" << std::endl;
  }

  template <typename Iterator>  // vector<int> v(10, 3) call this constructor
  // if we have meta function, is_iterator
  //   template <typename Iterator,
  //             typename = std::enable_if_t<is_iterator<Iterator>::value>>
  vector(Iterator start, Iterator end)
  {
    std::cout << "반복자를 이용한 생성자 호출" << std::endl;
  }
};

void test_enable_if_vector()
{
  vector<int> v(10, 3);
}

template <typename T, typename = decltype(std::declval<T>().func())>
void _test_enable_if_type(const T &t)
{
  std::cout << "t.func() : " << t.func() << std::endl;
}

struct AEnableIfType {
  int func() const { return 1; }
};

struct BEnableIfType {
};

void test_enable_if_type()
{
  _test_enable_if_type(AEnableIfType{});
  // _test_enable_if_type(BEnableIfType{}); // compile error
}

template <typename T, typename = decltype(std::declval<T>().func())>
void _test_enable_if_rettype(const T &t)
{
  std::cout << "t.func() : " << t.func() << std::endl;
}

struct AEnableIfRetType
{
  int func() const { return 1; }
};

struct BEnableIfRetType
{
  char func() const { return 'a'; }
};

struct CEnableIfRetType {
  AEnableIfRetType func() const { return AEnableIfRetType{}; }
};


void test_enable_if_rettype()
{
  _test_enable_if_rettype(AEnableIfRetType{});
  _test_enable_if_rettype(BEnableIfRetType{});
  // _test_enable_if_rettype(CEnableIfRetType{});  // compile error
}


// template <typename Cont,
//           typename = decltype(std::declval<Cont>().begin()),
//           typename = decltype(std::declval<Cont>().end())>
// template <typename Cont,
//           typename = std::void_t<decltype(std::declval<Cont>().begin()),
//                                  decltype(std::declval<Cont>().end())>>
// void print(const Cont& container) {
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

  // compile error, if using type, then it will pass
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
