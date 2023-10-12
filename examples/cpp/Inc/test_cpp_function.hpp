#ifndef TEST_CPP_FUNCTIONS_H
#define TEST_CPP_FUNCTIONS_H

void test_smart_pointer(void);
void testClassAddress(void);
void testChrono(void);
void testDataStructure(void);
void testDateTime(void);
void testMemAllocate(void);
void testRand(void);
void test_vector(void);
void test_typedef(void);
void test_end_func_const(void);
void test_ref(void);
void test_thread(void);
void test_thread_pattern(void);
void test_atomic(void);
void test_memory_order_relaxed(void);
void test_atomic_memory_order_relaxed(void);
void test_atomic_rel_ack(void);
void test_atomic_rel_ack_sequence(void);
void test_atomic_seq_cst_sequence(void);
void test_promise_future_scratch(void);
void test_promise_future(void);
void test_wait_for(void);
void test_shared_future(void);
void test_packaged_task(void);
void test_async(void);
void test_sync_vs_async_sync(void);
void test_sync_vs_async_async(void);
int test_thread_pool(void);

void test_copy_elision(void);
void test_rvalue(void);
void test_rvalue_simple(void);
void test_type_cast(void);
void test_template();

// function/test_function.cc
void test_callable(void);
void test_std_func(void);
void test_member_class_function(void);
void test_memfn(void);
void test_bind(void);


// function/test_labmda.cc
void test_functor(void);
void test_functor_lambda(void);
void test_basic_lambda(void);
void test_capture_lambda(void);
void test_mutable_lambda(void);
void test_range_capture(void);
void test_constructor_lambda(void);
void test_transfer_lambda(void);

// function/test_function_pointer.cc
void test_func_ptr(void);
void test_share_ptr_lambda(void);


// test_uniform_init.cc
void test_uniform_init(void);

// test_constexp.cc
void test_constexp(void);


// test_struct.cc
void test_struct_inheritance(void);

// test_post_prefix.cc
void test_post_pre_fix(void);

// test_void.cc
void test_void(void);

// test_var_type.cc
void test_const(void);

// test_exec.cc
void test_exec(void);

// test_string.cc
void test_string(void);
#endif
