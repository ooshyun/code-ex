
void non_static_func(void);
void static_func(void);

void test_static_func(void) {
    non_static_func();
    // static_func(); // compile error
}
