/*
    Test vector for data structure
        1. test vector of each problem
            build **.cc files using shell file and CMakelists.txt
        2. test memory leakage
            leaks --atExit --list -- *.exe
*/
#include <iostream>  // std::cout
#include "../Inc/log.hpp"

// Practice Data Structures in HackerRank Youtube
#define TEST_ALGORITHM_PRACTICE

// Practice C Function
#define TEST_C_FUNCTION

// Practice C++ Functions
#define TEST_CPP_FUNCTION
#define TEST_BOOST

// Practice Design Pattern
// #define TEST_DESIGN_PATTERN

// Practice Third Party Library
#define TEST_LIBRARY
#define TEST_DESIGN_PATTERN

#ifdef TEST_ALGORITHM_PRACTICE
#include "../Inc/data_structure.hpp"
#endif

#ifdef TEST_CPP_FUNCTION
#include "../Inc/test_cpp_function.hpp"
#endif

#ifdef TEST_C_FUNCTION
#include "../Inc/test_c_function.h"
#endif

#ifdef TEST_DESIGN_PATTERN
#include "../Inc/design_pattern.hpp"
#endif

#ifdef TEST_LIBRARY
#include "../Inc/std.hpp"
#endif

#ifdef TEST_BOOST
#include "../Inc/boost.hpp"
#endif

int main(void) {
  practice::log_init(0);
  LOG_DEBUG("Start main function ");
#ifdef TEST_ALGORITHM_PRACTICE
  // 1. Practice Data Structures in HackerRank Youtube
  // testBalancedParenthesesinExpression();
  // testQueueWithTwoStack();
  // testQueue();
  // testStack();
  // testIsCycle();
  // testLinkedList();
  // testCheckBST();
  // testBinarySearchTree();
  // testContactString();>
  // testMinHeap();

  // 2. Practice Recursion in HackerRank Youtube
  // testGraph();
#endif

#ifdef TEST_CPP_FUNCTION
  // test_smart_pointer();
  // testClassAddress();
  // testChrono();
  // testDataStructure();
  // testDateTime();
  // testMemAllocate();
  // testRand();
  // test_vector();
  // test_typedef();
  // test_end_func_const();
  // test_ref();
  // testClassAddress();
  // testChrono();
  // testDataStructure();
  // testDateTime();
  // testMemAllocate();
  // testRand();
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
  // test_rvalue();
  // test_type_cast();
  // test_template();

  /* function/test_labmda.cc */
  // test_functor();
  // test_functor_lambda();
  // test_basic_lambda();
  // test_capture_lambda();
  // test_mutable_lambda();
  // test_range_capture();
  // test_constructor_lambda();
  // test_transfer_lambda();

  /* function/test_function.cc */
  // test_callable();
  // test_std_func();
  // test_member_class_function();
  // test_memfn();
  // test_bind();

  /* function/test_function_pointer.cc */
  // test_func_ptr();
  // test_share_ptr_lambda();
  /* function/test_function.cc */
  // test_callable();
  // test_std_func();
  // test_member_class_function();
  // test_memfn();
  // test_bind();

  /* function/test_function_pointer.cc */
  // test_func_ptr();
  // test_share_ptr_lambda();

  /* test_unifomr_init.cc */
  // test_uniform_init();

  /* test_constexp.cc */
  // test_constexp();

  /* test_struct.cc*/
  // test_struct_inheritance();

  /* test_post_prefix.cc */
  // test_post_pre_fix();

  /* test_void.cc*/
  // test_void();

  /* test_var_type.cc */
  test_const();
#endif

#ifdef TEST_C_FUNCTION
  /* static_func/test_static_func */
  // test_static_func();
  // TEST_STATIC_FUNC()

  /* test_define_func */
  // test_define_func();
#endif

#ifdef TEST_DESIGN_PATTERN
  // test_proto_type();
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


#ifdef TEST_LIBRARY
    // test_time();
    // test_chronos_time();
    // test_temp_file();
    // test_append_file();
    // test_file_read();
    // test_file_access();
#endif

#ifdef TEST_BOOST
    // test_xml_parse();
    // test_xml_parse_complicate();
#endif

  return 0;
}