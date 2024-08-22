/*
    MIT License

  Copyright (c) 2023 Seunghyun Oh

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

// Test vector for data structure
//     1. test vector of each problem
//         build **.cc files using shell file and CMakelists.txt
//     2. test memory leakage (macos)
//         leaks --atExit --list -- *.exe
//     2.1 test memory leakage (linux)
//       valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt *.exe 2>&1 | tee valgrind-out.txt

#include <iostream>  // std::cout
#include "../Inc/log.hpp"
#include "../Inc/easy_profiler.hpp"

// Practice Data Structures in HackerRank Youtube
#define TEST_ALGORITHM_PRACTICE

// Practice C Function
#define TEST_C_FUNCTION

// Practice C++ Functions
#define TEST_CPP_FUNCTION
#define TEST_BOOST
#define TEST_SPDLOG

// Practice Design Pattern
// #define TEST_DESIGN_PATTERN

// Practice Third Party Library
#define TEST_LIBRARY
#define TEST_DESIGN_PATTERN

#ifdef TEST_ALGORITHM_PRACTICE
#include "../Inc/algorithm.hpp"
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

#ifdef TEST_SPDLOG
#include "../Inc/spdlog_scratch.hpp"
#endif

int main(void) {
  practice::log_init(0);
  // easy_profiler_init();

  LOG_INFO("Start main function ");
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
  // test_graph();
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
  // test_end_func_const();
  // test_ref();

  // test_thread();
  // test_thread_pattern();
  // test_atomic();
  // test_sync_and_async();
  // test_thread_pool();

  // test_copy_elision();
  // test_rvalue_simple();
  // test_rvalue();
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

  /* function/test_function_argument.cc */
  // test_function_argument();

  /* test_unifomr_init.cc */
  // test_uniform_init();

  /* test_constexp.cc */
  // test_constexp();

  /* test_struct.cc*/
  // test_struct_inheritance();

  /* test_post_prefix.cc */
  // test_post_pre_fix();

  /* test_void.cc */
  // test_void();

  /* test_exec.cc */
  // test_exec();

  /* test_string.cc */
  test_string();

  /* test_var_type.cc */
  // test_const();

  /* test_rtti.cc */
  // test_rtti();
  // test_myarray();

  /* test_exception.cc */
  // test_exception();

  /* test_type.cc */
  // test_type();

  /* test_type_traits.cc */
  // test_type_traits();

  /* test_bellman_ford.cc */
  // test_bellmanford();

  /* test_dijkstra */
  // test_dijkstra();

  /* test_class */
  // test_static_component_in_class();
  // test_template_class();

  /* test_filesystem */
  // test_filesystem();
#endif

#ifdef TEST_C_FUNCTION
  /* static_func/test_static_func */
  // test_static_func();
  // TEST_STATIC_FUNC()

  /* test_define_func */
  // test_define_func();

  /* test_switch_func */
  // test_switch_func();

  /* test_condition */
  // test_condition();
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
    // test_easy_profiler();
    // test_time();
    // test_chronos_time();
    // test_temp_file();
    // test_append_file();
    // test_copy_fs();
    // test_temp_file();
    // test_append_file();
    // test_file_read();
    // test_file_access();
#endif

#ifdef TEST_BOOST
    // test_xml_parse();
    // test_xml_parse_complicate();
    // test_xml_parse_api();
#endif

#ifdef TEST_SPDLOG
    // test_spdlog_scratch();
#endif

  // easy_profiler_finish();
  return 0;
}
