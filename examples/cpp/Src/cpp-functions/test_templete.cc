#include <iostream>

class ATestTemplete {
 public:
    void print(int a, int b) {
        std::cout << a << b <<std::endl;
    }

    template <typename T>  // treat this as a function
    void print(T a) {
        std::cout << a << std::endl;
    }
};

void test_template() {
    ATestTemplete test_template;
    test_template.print(1, 2);
    test_template.print<double>(1);
}