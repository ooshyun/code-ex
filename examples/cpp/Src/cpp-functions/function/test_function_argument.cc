/*
  Copyright from none
  This copy from https://stackoverflow.com/questions/73904873/how-can-i-pass-a-function-name-and-variadic-list-of-arguments-to-a-function-in-c
*/

// C++ includes
#include <cstdint>  // For `uint8_t`, `int8_t`, etc.
#include <cstdio>   // For `printf()`
#include <iostream>  // For `std::cin`, `std::cout`, `std::endl`, etc.
#include <string>

void print1(int i) {
    printf("print1: %i\n", i);
}

void print2(double d, int i) {
    printf("print2: %f, %i\n", d, i);
}

void print3(int i, double d, const std::string& str) {
    printf("print3: %i, %f, %s\n", i, d, str.c_str());
}

// See: https://en.cppreference.com/w/cpp/language/parameter_pack
// template<class FuncType, class... FuncArgs>
template<typename FuncType, typename... FuncArgs>
void OuterFunc(FuncType innerFunc, FuncArgs... args) {
    printf("OuterFunc start.\n");

    // Call the inner function with all passed-in args!
    printf("Calling inner function with all passed-in args.\n");
    // See the "Expansion loci" section of this documentation here:
    // https://en.cppreference.com/w/cpp/language/parameter_pack
    // This is really cool, because calling the inner function like this is
    // **just like the Python example here!**: https://stackoverflow.com/a/803632/4561887
    // --except you pass the arguments to the inner function as `args...`
    // in C++ here instead of as `*args` (the contents of the arguments list)
    // in Python.
    innerFunc(args...);

    printf("OuterFunc end.\n\n");
}

// int main(int argc, char *argv[])  // alternative prototype
void test_function_argument(void) {
    printf("Demonstrate variadic templates (parameter packs) in C++!\n\n");

    OuterFunc(print1, 100);
    OuterFunc(print2, 99.1234, 77);
    OuterFunc(print3, 123, 10.55, "hey you!");
}