#include <iostream>
struct base {
    int a1;
    int a2;
    base() = default;
    base(const int& a1, const int& a2) : a1{a1}, a2{a2} {}
    virtual ~base() {}
};
struct derived : public base {
    derived() = default;
    derived(const int& a1, const int& a2, const int& b1)
        : base{a1, a2}, b1{b1} {};
    int b1;
};

void test_struct_inheritance(void) {
    base b = base();
    derived d = derived();
    derived d1{1, 2, 3};                    // full explicit initialization
    std::cout << d1.a1 << " " << d1.a2 << " " << d1.b1 << std::endl;

    int x = NULL;
    derived d2{NULL, NULL, 1};        // the base is value initialized
    std::cout << d2.a1 << " " << d2.a2 << " " << d2.b1 << std::endl;
}