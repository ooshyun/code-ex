#include <stdio.h>

enum TestSwitchState {
    test_switch_state_zero,
    test_switch_state_one,
    test_switch_state_two,
};

void test_switch_func (void) {
    enum TestSwitchState state = test_switch_state_zero;
    switch (state) {
        case test_switch_state_zero:
            printf("test_switch_state_zero\n");
            // break;
        case test_switch_state_one:
            printf("test_switch_state_one\n");
            // break;
        case test_switch_state_two:
            printf("test_switch_state_two\n");
            // break;
        default:
            break;
    }
}