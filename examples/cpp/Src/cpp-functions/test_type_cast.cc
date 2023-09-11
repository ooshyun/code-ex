#include<iostream>
#include<string>

enum x {a, b, c};

void test_type_cast(void){
     std::cout << x::a << std::endl;
     std::cout << x::b << std::endl;
     std::cout << x::c << std::endl;
     std::cout << x::a << std::endl;
     std::cout << "" << std::endl;
}