#ifndef TEST_C_FUNCTIONS_H
#define TEST_C_FUNCTIONS_H

extern "C" {
// test_static_func.c
void test_static_func(void);

// test_define_func.c
void test_define_func(void);

// test_switch_func.c
void test_switch_func(void);

// test_condition.c
void test_condition(void);

}


#include "../Src/c-functions/static_func/test_static_func_internal.h"
#define TEST_STATIC_FUNC()          \
static_func_in_header();

#endif