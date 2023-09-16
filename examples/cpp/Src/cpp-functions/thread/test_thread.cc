// https://modoocode.com/269

#include <iostream>
#include <thread>
using std::thread;

#include <mutex>
#include <cstdio>
#include <vector>
using std::vector;

void func1(){
    for (int i=0; i<10; i++){
        std::cout << "Thread 1 operating \n";
    }
}

void func2(){
    for (int i=0; i<10; i++){
        std::cout << "Thread 2 operating \n";
    }
}

void func3(){
    for (int i=0; i<10; i++){
        std::cout << "Thread 3 operating \n";
    }
}

void _test_thread_join(void){
    std::cout << "  test_thread_join\n";
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);

    t1.join();
    t2.join();
    t3.join();
    std::cout << "  end test_thread_join\n";
}

void _test_thread_no_join(void){
    std::cout << "  test_thread_no_join\n";
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);

    std::cout << "  end test_thread_no_join\n";
}


void _test_thread_detach(void){
    std::cout << "  test_thread_detach\n";
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);

    t1.detach();
    t2.detach();
    t3.detach();
    std::cout << "  end test_thread_detach\n";
}

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result){
    int sum = 0;
    for (auto iter = start; iter != end; iter++){
        sum += *iter;
    }
    *result = sum;

    // thread id
    thread::id this_id = std::this_thread::get_id();
    printf("Thread %x: Compute from %d to %d result: %d \n", this_id, *start, *(end-1), sum);
}

void _test_thread_argument(void){
    printf("  test_thread_argument\n");
    vector<int> data(10000);
    for (int i=0; i<10000; i++){
        data[i] = i;
    }

    vector<int> partial_sums(4);

    vector<thread> workers;
    for(int i=0; i<4; i++){
        workers.push_back(thread(worker, data.begin() + i*2500, 
                                data.begin() + (i+1)*2500, &partial_sums[i]));
    }

    for (int i=0; i<4; i++){
        workers[i].join();
    }

    int total = 0;

    for (int i=0; i<4; i++){
        total += partial_sums[i];
    }

    printf("  Total sum: %d \n", total);
}


void worker_race_condition(int &counter){
    for (int i=0; i<10000; i++){
        counter++;
    }
}

void _test_thread_race_condition(void){
    printf("  test_thread_race_condition\n");
    int counter = 0;
    vector<thread> workers;
    for (int i=0; i<4; i++){
        workers.push_back(thread(worker_race_condition, std::ref(counter)));
    }

    for (int i=0; i<4; i++){
        workers[i].join();
    }

    printf("  Counter: %d \n", counter);
}

void worker_mutex(int &counter, std::mutex &m){
    for (int i=0; i<10000; i++){
        m.lock(); // critial section start
        counter++; 
        m.unlock(); // critial section end
    }
}

void worker_dead_lock(int &counter, std::mutex &m){
    for (int i=0; i<10000; i++){
        m.lock(); // critial section start
        counter++; 
    }
}

void worker_lock_guard(int &counter, std::mutex &m){
    for (int i=0; i<10000; i++){
        std::lock_guard<std::mutex> lock(m);
        counter++; 

        // if loop finish, lock is released and m is unlocked
    }
}

void _test_thread_mutex(void (*worker_func)(int &, std::mutex &)){
    printf("  test_thread_mutex\n");
    int counter = 0;
    std::mutex m;
    vector<thread> workers;
    for (int i=0; i<4; i++){
        workers.push_back(thread(worker_func, std::ref(counter), std::ref(m)));
    }

    for (int i=0; i<4; i++){
        workers[i].join();
    }

    printf("  Counter: %d \n", counter);
}


void worker1_deadlock_2(std::mutex &m1, std::mutex &m2){
 
    for (int i=0; i<5; i++){
        std::lock_guard<std::mutex> lock1(m1);
        std::lock_guard<std::mutex> lock2(m2);
        // Do something
    }
}

void worker2_deadlock_2(std::mutex &m1, std::mutex &m2){
 
    for (int i=0; i<5; i++){
        std::lock_guard<std::mutex> lock2(m2);
        std::lock_guard<std::mutex> lock1(m1);
        // Do something
    }
}

void worker1_deadlock_escape(std::mutex &m1, std::mutex &m2){
 
    for (int i=0; i<5; i++){
        m1.lock();
        m2.lock();
        printf("Thread 1 operating \n");
        m2.unlock();
        m1.unlock();
    }
}

void worker2_deadlock_escape(std::mutex &m1, std::mutex &m2){
 
    for (int i=0; i<5; i++){
        while(true){
            m2.lock();

            if (m1.try_lock()){
                printf("Thread 2 operating \n");
                m2.unlock();
                continue;
            }

            printf("Thread 2 operating \n");
            m2.unlock();
            m1.unlock();
            break;
        }
    }
}

void _test_thread_escape_deadlock(void (*func_worker1)(std::mutex &, std::mutex &), 
                                void (*func_worker2)(std::mutex &, std::mutex &)){
    printf("  test_thread_escape_deadlock\n");
    std::mutex m1, m2;
    thread t1(func_worker1, std::ref(m1), std::ref(m2));
    thread t2(func_worker2, std::ref(m1), std::ref(m2));

    t1.join();
    t2.join();

    printf("  end test_thread_escape_deadlock\n");
}

void test_thread(void){
    // // join return when thread finishs
    // // but! in function having thread, it operates.
    // // it just wait for thread to finish 
    // // if thread 1 is finished and thread 2 also is finish already, 
    // // then thread 2 returns immedately
    // _test_thread_join();
    // _test_thread_no_join(); 
    
    // // detach is like a background process, 
    // // but if process is dead, then thread cannot be operated
    // _test_thread_detach();  

    // // pass argu to thread 
    // // if printf replace std::cout, then message was messed up
    // // detail: https://stackoverflow.com/questions/23586682/how-to-use-printf-in-multiple-threads
    _test_thread_argument();

    // // Race condition, access same memory
    // _test_thread_race_condition();

    // // Mutex, lock and unlock preventning race condition
    // _test_thread_mutex(worker_mutex);

    // // Dead lock
    // _test_thread_mutex(worker_dead_lock);

    // // Mutex using lock_guard
    // _test_thread_mutex(worker_lock_guard);

    // Dead lock in lock_guard
    // _test_thread_escape_deadlock(worker1_deadlock_2, worker2_deadlock_2); 


    // Dead lock escape, but starvation(a thread is more working)
    // _test_thread_escape_deadlock(worker1_deadlock_escape, worker2_deadlock_escape);
}