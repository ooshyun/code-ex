#include <stdio.h>

void non_static_func(void) {
    printf("non_static_func\n");
}

// if declared as static, this function is only visible in this file
static void static_func(void) {
    printf("static_func\n");
}