
#include <stdio.h>

#define test_define_func_1()            \
    printf("test_define_func\n");       \
    input_define++;                     \


void test_define_func1(void) {
    int input_define = 1;
    test_define_func_1()

    printf("1 input_define: %d\n", input_define);

    test_define_func_1()
    printf("2 input_define: %d\n", input_define);
}

void test_define_func2(void) {
    int input_define = 11;
    test_define_func_1()

    printf("1 input_define: %d\n", input_define);

    test_define_func_1()
    printf("2 input_define: %d\n", input_define);
}


void test_define_func(void) {
    test_define_func1();
    test_define_func2();
}