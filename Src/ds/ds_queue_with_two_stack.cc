/*
    Last Input First Output(LIFO) > First Input First Output(FIFO)
*/

#include <iostream>
#include <stack>

class queueWithTwoStack {
private:
    std::stack<int> stackNewestOnTop;
    std::stack<int> stackOldestOnTop;
public:
    queueWithTwoStack();
    ~queueWithTwoStack();
    void enqueue(int val);
    int peek();       
    int dequeue();
    void shiftNewtoOld();
};

queueWithTwoStack::queueWithTwoStack(){
    
}
queueWithTwoStack::~queueWithTwoStack(){

}

void queueWithTwoStack::enqueue(int val){
    stackNewestOnTop.push(val);
}

void queueWithTwoStack::shiftNewtoOld(){
    if(!stackNewestOnTop.empty()){
        while(!stackNewestOnTop.empty()){
            stackOldestOnTop.push(stackNewestOnTop.top());
            stackNewestOnTop.pop();
        }
    }
}

int queueWithTwoStack::peek(){
    if(stackOldestOnTop.empty()){
        if(stackNewestOnTop.empty()){
            return 0;
        }
        else{
            shiftNewtoOld();
        }
    }
    return stackOldestOnTop.top();
}

int queueWithTwoStack::dequeue(){
    if(stackOldestOnTop.empty()){
        if(stackNewestOnTop.empty()){
            return 0;
        }
        else{
            shiftNewtoOld();
        }
    }
    int buf = stackOldestOnTop.top();
    stackOldestOnTop.pop();
    return buf;
}

void testQueueWithTwoStack(){
    queueWithTwoStack testQueueWithTwoStackObj;
    int testArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    uint8_t index;

    std::cout << "  Test 1 " << std::endl;

    for(index=0; index<int(sizeof(testArr)/sizeof(int)); index++){
        testQueueWithTwoStackObj.enqueue(testArr[index]);
    }
    
    for(index=0; index<int(sizeof(testArr)/sizeof(int)); index++){
        std::cout << "Peek: "<< testQueueWithTwoStackObj.peek() << std::endl;
        std::cout << "Pop: " << testQueueWithTwoStackObj.dequeue() << std::endl;
    }
    std::cout << "-----------"<< std::endl;

    std::cout << "  Test 2 " << std::endl;
    
    for(index=0; index<5; index++){
        testQueueWithTwoStackObj.enqueue(testArr[index]);
    }
    
    for(index=0; index<3; index++){
        std::cout << "Peek: "<< testQueueWithTwoStackObj.peek() << std::endl;
        std::cout << "Pop: " << testQueueWithTwoStackObj.dequeue() << std::endl;
    }

    for(index=5; index<int(sizeof(testArr)/sizeof(int)); index++){
        testQueueWithTwoStackObj.enqueue(testArr[index]);
    }

    for(index=0; index<10; index++){
        std::cout << "Peek: "<< testQueueWithTwoStackObj.peek() << std::endl;
        std::cout << "Pop: " << testQueueWithTwoStackObj.dequeue() << std::endl;
    }
}

