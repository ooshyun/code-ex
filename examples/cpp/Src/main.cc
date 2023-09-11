/*
    Test vector for data structure
        1. test vector of each problem
            build **.cc files using shell file and CMakelists.txt
        2. test memory leakage
            leaks --atExit --list -- *.exe
*/

// Practice Data Structures in HackerRank Youtube
// #define TEST_ALGORITHM_PRACTICE 

// Practice C++ Functions
#define TEST_CPP_FUNCTION

// Practice Design Pattern
// #define TEST_DESIGN_PATTERN

#include <iostream>  // std::cout

#ifdef TEST_ALGORITHM_EXAM
#include "../Inc/data_structure.h"
#endif 

#ifdef TEST_CPP_FUNCTION
#include "../Inc/test_cpp_function.h"
#endif

#ifdef TEST_DESIGN_PATTERN
#include "../Inc/design_pattern.h"
#endif

int main(void) {
    printf("Hello World!\n");
#ifdef TEST_ALGORITHM_EXAM
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
    testMinHeap();
    // 2. Practice Recursion in HackerRank Youtube
    // testGraph();
    // testBFS();
    // testDFS();
#endif

#ifdef TEST_CPP_FUNCTION
    // testClassAddress();
    // testChrono();
    // testDataStructure();
    // testDateTime();
    // testMemAllocate();
    // testRand();
    // test_vector_reference();
    // test_typedef();
    // test_end_func_const();
    // test_ref();

    // test_thread();
    // test_thread_pattern();
    // test_atomic();
    // test_memory_order_relaxed();
    // test_atomic_memory_order_relaxed();
    // test_atomic_rel_ack();
    // test_atomic_rel_ack_sequence();
    // test_atomic_seq_cst_sequence();

    // test_promise_future_scratch();
    // test_promise_future();
    // test_wait_for();
    // test_shared_future();
    // test_packaged_task();
    // test_async();
    // test_sync_vs_async_sync();
    // test_sync_vs_async_async();
    // test_thread_pool();
    // test_copy_elision();
    // test_rvalue_simple();
    test_rvalue();
    // test_type_cast();
    // test_template();
#endif

#ifdef TEST_DESIGN_PATTERN
    // test_test_proto_type();
    // test_type_object_pattern();

    // bool result = factorial::Test().Main();
    // printf("  Before\n");
    // printf(result ? "true\n" : "false\n");

    // if(factorial::Init() < 0){
    //     printf("factorial::Init() failed\n");
    //     return -1;
    // }
    // printf("  After\n");
    // result = factorial::Test().Main();
    // printf(result ? "true\n" : "false\n");
#endif


    return 0;
}