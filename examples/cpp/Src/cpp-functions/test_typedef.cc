#include<iostream> 

typedef int FAKE;

void test_typedef(void){
    std::cout << "test_typedef" << std::endl;
    FAKE x = 10;
    std::cout << x << std::endl;

    int y = 3, z, w;

    std::cout << y << " " << z << " " << w << std::endl;
    std::cout << (uint32_t) -1 << std::endl;
}