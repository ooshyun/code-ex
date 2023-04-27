/*
    Test vector for data structure
        1. test vector of each problem
            build **.cc files using shell file and CMakelists.txt
        2. test memory leakage
            leaks --atExit --list -- *.exe
*/
#include "stdio.h"
#include "../Inc/data_structure.h"

int main(void) {
    printf("Hello World!\n");
    
    // 1. Practice Data Structures in HackerRank Youtube
    // testBalancedParenthesesinExpression();
    // testQueueWithTwoStack();
    // testQueue();
    // testStack();
    // testIsCycle();
    // testLinkedList();
    // testCheckBST();
    testBinarySearchTree();

    return 0;
}