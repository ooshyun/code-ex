#include <stdio.h>

void test_tenary_op(void) {
    int a = 10;
    int b = 12;
    int result = a > b ? a : b;
    printf("result: %d\n", result);

    if (a > b) {
        result = a;
    } else {
        result = b;
    }
    printf("result: %d\n", result);
}

void test_condition(void) {
    test_tenary_op();
}
