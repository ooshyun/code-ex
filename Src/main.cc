/*
    Test vector for data structure
        1. test vector of each problem
            build **.cc files using shell file and CMakelists.txt
        2. test memory leakage
            leaks --atExit --list -- *.exe
*/
#include "stdio.h"
#include "../Inc/ds_is_balence_parentheses.h"
#include "../Inc/ds_queue_with_two_stack.h"
#include "../Inc/ds_queue_and_stack.h"
#include "../Inc/ds_is_cycle.h"
#include "../Inc/ds_linked_list.h"

int main(void) {
    printf("Hello World!\n");
    // testBalancedParenthesesinExpression();
    // testQueueWithTwoStack();
    // testQueue();
    // testStack();
    testIsCycle();
    testLinkedList();
    return 0;
}