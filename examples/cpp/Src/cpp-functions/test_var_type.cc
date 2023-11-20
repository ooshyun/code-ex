#include <iostream>

class TestVarType {
 public:
    TestVarType() {
        std::cout << "TestVarType" << std::endl;
        std::cout << a << " and " << b << std::endl;
    }
    ~TestVarType() {
        std::cout << "~TestVarType" << std::endl;
    }
 private:
    static const int a = 1;
    const int b = 2;
};

static const int a = 1;
const int b = 2;

void test_const_func2(void *buffer) {
    std::cout << "test_const_func2" << std::endl;
}

void test_const_func(int* buffer) {
    std::cout << "test_const_func1" << std::endl;
    test_const_func2(buffer);
}

void test_const(void) {
    int buf[100];
    for (int i = 0; i < 100; i++) {
        buf[i] = i;
    }
    test_const_func(buf);

    TestVarType t;
}