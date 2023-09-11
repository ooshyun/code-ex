#include <iostream>
#include <LibTemplateCMake.h>

int main(void){
    LibTemplateCMake::summationClass summation;
    LibTemplateCMake::differenceClass difference;
    
    std::cout << summation.doSomething(1, 2) << std::endl;
    std::cout << difference.doSomething(1, 2) << std::endl;
    return 0;
}