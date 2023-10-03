#pragma once
#include <stdio.h>
// if declared as static, this function is only visible in this file
static void static_func_in_header(void) {
    printf("static_func_in_header\n");
}
