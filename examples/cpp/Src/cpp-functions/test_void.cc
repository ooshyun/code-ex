
#include<stdio.h>

void _test_void(const int a, const int b) {
    (void) a;  // why use this?
    (void) b;
    printf("a: %d, b: %d \n", a, b);
}


void test_void(void) {
    int a = 1;
    int b = 2;
    _test_void(a, b);
}