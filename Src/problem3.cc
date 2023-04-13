#include<iostream>

struct Node{
public:
    int data;
    struct Node *next;
};

class Queue{
private:
    // warning: default member initializer for non-static data member is a C++11 extension [-Wc++11-extensions]
    Node *head;
    Node *tail;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    int peek();
    void add(int data);
    int remove();
};

Queue::Queue(){
    head = nullptr;
    tail = nullptr;
}

Queue::~Queue(){
    int buf;
    while(!(head==nullptr)){
        buf = remove();
    }
}

bool Queue::isEmpty(){
    return head == nullptr;
}
int Queue::peek(){
    return head->data;
}
void Queue::add(int data){
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;

    if (tail != nullptr){
        tail->next = node; // previous node points to next node
    }
    tail = node;

    if(head == nullptr)
        head = node;
}
int Queue::remove(){
    int data = head->data;
    if(head->next == nullptr){
        delete head;
        head = nullptr;
    }
    else{
        Node *node = head;
        head = node->next;
        delete node;
    }
    
    if(head == nullptr){
        tail = nullptr;  
    }          
    return data;
}


class Stack{
private:
    Node *top;
public:
    Stack();
    ~Stack();
    bool isEmpty();
    int peek();
    void push(int data);
    int pop();
};

Stack::Stack(){
    top = nullptr;
}
Stack::~Stack(){
    int buf;
    while(!(top==nullptr)){
        buf = pop();
    }
}

bool Stack::isEmpty(){
    return top == nullptr;
}
int Stack::peek(){
    return top->data;
}

void Stack::push(int data){
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;
    if(top != nullptr){
        node->next = top;
    }
    top = node;
}

int Stack::pop(){
    Node *node = top;
    int data = node->data;
    top = node->next;
    delete node;

    return data;
}

void testQueue(){
    std::cout << "Hello Test Queue World!" << std::endl;
    Queue testQueue;
    int testData[] = {1,2,3,4,5,6};
    int topBuf;
    uint8_t size = static_cast<int>(sizeof(testData)/sizeof(int));
    uint8_t id = 0;

    for(id=0; id<size; id++)
        testQueue.add(testData[id]);

    for(id=0; id<size-3; id++){
        std::cout << testQueue.peek() << std::endl;
        topBuf = testQueue.remove();
        std::cout << topBuf << std::endl;
    }
}

void testStack(){
    std::cout << "Hello Test Stack World!" << std::endl;
    Stack testStack;
    int testData[] = {1,2,3,4,5,6};
    int topBuf;
    uint8_t size = static_cast<int>(sizeof(testData)/sizeof(int));
    uint8_t id = 0;

    for(id=0; id<size; id++)
        testStack.push(testData[id]);

    for(id=0; id<size-3; id++){
        std::cout << testStack.peek() << std::endl;
        topBuf = testStack.pop();
        std::cout << topBuf << std::endl;
    }
}