
#include <memory>
#include <iostream>
#include <functional>

typedef int (*func_ptr)(int, int);
using func_ptr2 = int(*)(int, int);  // type alias

template <typename T>
auto _add(T a, T b) {
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    return a + b;
}

void test_func_ptr(void) {
    int (*func)(int, int) = _add;
    auto (*func2)(int, int) = _add<int>;
    func_ptr func3 = _add<int>;
    func_ptr2 func4 = _add<int>;

    std::function<int(int, int)> func5 = _add<int>;

    func(3, 5);
    func2(3, 5);
    func3(3, 5);
    func4(3, 5);
    func5(3, 5);
}

std::function<int(void)> f(
  std::shared_ptr<int> x) {
  return [&]() { return *x; };
}

void test_share_ptr_lambda(void) {
  std::function<int(void)> foo(nullptr);
  {
    std::shared_ptr<int> x(std::make_shared<int>(1));
    foo = f(x);
    std::cout << "shared ptr scope in " << foo() << std::endl;
  }
  std::cout << "shared ptr scope out " << foo() << std::endl;
}