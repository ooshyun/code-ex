#include<iostream>

void testMemAllocate(){
    int* p = new int[10];
    int* p_other = p;
    
    std::cout<<p<<std::endl;    
    std::cout<<p_other<<std::endl;
    
    delete[] p_other;
}
