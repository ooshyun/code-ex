/*
    Test vector for data structure
        1. test vector of each problem
            build **.cc files using shell file and CMakelists.txt
        2. test memory leakage
            leaks --atExit --list -- *.exe
*/
#include "stdio.h"
#include "../Inc/data_structure.h"
#include "../Inc/recursion.h"
#include "../Inc/testclass.h"
#include <iostream>

#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector


class TestClass{
private:
public:
    int32_t x;
    TestClass(){
        x=10;
    };
    ~TestClass(){};
};


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
    // testBinarySearchTree();
    // testContactString();

    // 2. Practice Recursion in HackerRank Youtube
    testGraph();
    // testBFS();
    // testDFS();


    // X. Text case
    
    // TestClass* t = new TestClass;
    // TestClass t2;
    // int64_t *addr;
    // addr = (int64_t *)t;
    // addr = (int64_t *)(&t2);
    // std::cout<< ((TestClass*)addr)->x<<std::endl;
    // testmem();
    
    return 0;
}