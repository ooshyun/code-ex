
#include <functional>
#include<iostream>

void test_ref(void){
    std::cout << "test_ref" << std::endl;
    int x = 10;
    int& y = x;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << &x << std::endl;
    std::cout << &y << std::endl;
    std::cout << "---" << std::endl;
    
    y = 20;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << "---" << std::endl;
    
    int* z = &x;
    std::cout << z << std::endl;
    std::cout << *z << std::endl;
    std::cout << "---" << std::endl;
    
    *z = 30;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << *z << std::endl;
    std::cout << "---" << std::endl;
    
    std::cout << "Compare std::ref" << std::endl;
    std::cout << "  x " << std::endl;
    std::cout << "&x = " << &x << std::endl;
    std::cout << "ref(x) = " << std::ref(x) << std::endl;
    std::cout << "ref(y) = " << std::ref(y) << std::endl;
    std::cout << "ref(z) = " << std::ref(z) << std::endl;

}