
#include <iostream>
template <typename T>
struct product {
product(T& storage) : value(storage) {}
    template <typename V>
    void operator()(V& v) {
        std::cout << "v: " << v << std::endl;
        value *= v;
    }
    T& value;
};

void test_functor(void) {
    std::vector<int> cardinal;
    for (int i = 1; i < 11; i++) cardinal.push_back(i);
    int total_elements = 1;
    for_each(cardinal.begin(), cardinal.end(), product<int>(total_elements));

    std::cout << "total elements : " << total_elements << std::endl;
}

void test_functor_lambda(void) {
    std::vector<int> cardinal;
    for (int i = 1; i < 11; i++) cardinal.push_back(i);
    int total_elements = 1;
    std::for_each(cardinal.begin(), cardinal.end(),
            [&total_elements](int i) {
                std::cout << "i: " << i << std::endl;
                total_elements *= i;
            });

    std::cout << "total elements : " << total_elements << std::endl;
}

void test_basic_lambda(void) {
    auto f = []() -> void { std::cout << "foo" << std::endl; };
    f();
    []() { std::cout << "foo" << std::endl; }();
    [](int v) { std::cout << v << "*6=" << v * 6 << std::endl; }(7);

    int i = 7;
    [](int& v) { v *= 6; }(i);
    std::cout << "the correct value is: " << i << std::endl;
}

template <typename T>
void fill(std::vector<int>& v, T done) {  // NOLINT
    int i = 0;
    while (!done()) {
        v.push_back(i++);
    }
};

void test_capture_lambda(void) {
    int total_elements = 1;
    std::vector<int> cardinal;

    cardinal.push_back(1);
    cardinal.push_back(2);
    cardinal.push_back(4);
    cardinal.push_back(8);

    std::for_each(cardinal.begin(), cardinal.end(), \
                [&](int i) { total_elements *= i; });

    std::cout << "total elements : " << total_elements << std::endl;

    std::vector<int> stuff;
    fill(stuff, [&]() -> bool { return stuff.size() >= 8; });
    std::for_each(stuff.begin(), stuff.end(), \
            [](int i) { std::cout << i << " "; });
    stuff.clear();

    fill(stuff, [&]() -> bool {
        int sum = 0;
        for_each(stuff.begin(), stuff.end(), [&](int i) { sum += i; });
        return sum >= 10;
    });
    for_each(stuff.begin(), stuff.end(), [](int i) { std::cout << i << " "; });

    std::for_each(stuff.begin(), stuff.end(), \
            [](int i) { std::cout << i << " "; });


    int v = 42;
    auto func = [=] { std::cout << v << std::endl; };
    v = 8;
    func();
}

void test_mutable_lambda(void) {
    int i = 10;

    // // error : expression must be a modifiable lvalue
    // auto two_i_err = [=]() -> int {
    //     i *= 2;
    //     return i;
    // };

    auto two_i = [=]() mutable -> int {
        i *= 2;
        return i;
    };
    std::cout << "2i:" << two_i() << " i:" << i << std::endl;
}

class gorp {
  std::vector<int> values;
  int m_;

 public:
  gorp(int mod) : m_(mod) {}
  gorp& put(int v) {
    std::cout << "put: " << v << std::endl;
    values.push_back(v);
    return *this;
  }
  int extras() {
    int count = 0;
    std::for_each(values.begin(), values.end(),
             [=, &count](int v) { count += v % m_; });
    return count;
  }
};

struct foo {
  foo() : i(0) {}
  void amazing() {
    [=] { i = 8; }();
  }
  int i;
};

void test_range_capture(void) {
    gorp g(4);
    g.put(3).put(7).put(8);

    // capture range in class
    std::cout << "extras: " << g.extras() << std::endl;

    // modifiable capture range in class without mutable
    // because it captures "this"
    foo f;
    f.amazing();
    std::cout << "f.i : " << f.i << std::endl;

    // capture range in scope
    int i = 8;
    {
        int j = 2;
        auto f = [=] { std::cout << i / j << std::endl;};  // capture i
        f();
    }

    auto f1 = [i]() {  // capture i
        int j = 2;
        auto m = [=] { std::cout << i / j << std::endl; };
        m();
    };
    f1();
    
    // error C3493: 'i' cannot be implicitly captured
    // because no default capture mode has been specified
    // auto f2 = []() {
    // int j = 2;
    // auto m = [=] { std::cout << i / j; }; // error
    // m();
    // };
    // f2();

    // // 'i': a by-value capture cannot be modified in a non-mutable lambda
    // // auto f3 = [=]() {
    // //     int j = 2;
    // //     auto m = [&] { i /= j; }; // error
    // //     m();
    // //     std::cout << "inner: " << i;
    // // };
    // // f3();
    // // std::cout << " outer: " << i;

    // mutable
    i = 8;
    auto f4 = [i]() mutable {
        int j = 2;
        auto m = [&, j]() mutable { i /= j; };
        m();
        std::cout << "inner: " << i << std::endl;
    };
    f4();
    std::cout << " outer: " << i << std::endl;
}

struct trace {
  trace() : i(0) { std::cout << "construct\n"; }
  trace(trace const&) { std::cout << "copy construct\n"; }
  ~trace() { std::cout << "destroy\n"; }
  trace& operator=(trace&) {
    std::cout << "assign\n";
    return *this;
  }
  int i;
};

void test_constructor_lambda(void) {
    trace t;
    int i = 8;

    // no copy constructor
    auto f = [=]() { return i / 2; };

    trace t2;
    int i2 = 8;

    // copy constructor since t2 is captured
    auto m1 = [=]() { int i2 = t2.i; };

    std::cout << " --- make copy --- " << std::endl;

    // copy constructor
    auto m2 = m1;
}

void test_transfer_lambda(void) {
    typedef int (*f_type)(int);
    f_type f = [](int i) -> int { return i + 20; };
    std::cout << f(8) << std::endl;

    std::function<int(std::string const &)> f2;
    f2 = [](std::string const &s) -> int { return s.size(); };
    int size = f2("http://itguru.tistory.com");

    std::cout << size << std::endl;

    std::function<int(int)> f3;
    std::function<int(int)> f4 = [&](int i) -> int {
        std::cout << i << " ";
        if (i > 5) {
            return f3(i - 2);
        }
    };
    f3 = [&](int i) -> int {
        std::cout << i << " ";
        return f4(++i);
    };
    f3(10);

    std::cout << std::endl;

    // recursive
    std::function<int(int)> fact;
    fact = [&fact](int n) -> int {
    if (n == 0) {
        return 1;
    } else {
        return (n * fact(n - 1));
    }
    };
    std::cout << "factorial(4) : " << fact(4) << std::endl;
}