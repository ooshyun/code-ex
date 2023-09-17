#include <iostream>
#include <stdint.h>
#include "../../Inc/data_structure.hpp"

linkedlistNode::linkedlistNode(int data){
    this->data=data;
    this->next=nullptr;
}
linkedlistNode::~linkedlistNode(){
}

class LinkedList{
private:
    linkedlistNode *head;
public:
    bool is_cycle();
    void append(int data);
    void prepend(int data);
    void deleteWithValue(int data);
    void traversalOrder();
    LinkedList();
    ~LinkedList();
};
LinkedList::LinkedList(){
    head=nullptr;
}
LinkedList::~LinkedList(){
    std::cout << "END" << std::endl;
    while(!(head==nullptr)){
        deleteWithValue(head->data);
    }
}

bool LinkedList::is_cycle(){
    // race with speed a, b, then if cycle then it will meet
    if (head == nullptr) return false;
    if (head->next == nullptr) return false;
    linkedlistNode *fastNode = head->next;
    linkedlistNode *slowNode = head;
    
    while((fastNode!=nullptr) && (fastNode->next!=nullptr) && (slowNode!=nullptr)){
        if (fastNode == slowNode)
            return true;
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    }
    return false;
}

void LinkedList::append(int data){
    // insertion data
    linkedlistNode *tail = new linkedlistNode(data);

    // find a tail
    linkedlistNode *node = head;
    while(node->next!=nullptr){
        node = node->next;
        if(node->next == nullptr){
            node->next = tail;
            break;
        }
    }
}

void LinkedList::prepend(int data){
    // insert to head
    linkedlistNode *newHead= new linkedlistNode(data);
    if(head != nullptr)
        newHead->next = head;
    head = newHead;
}

void LinkedList::deleteWithValue(int data){
    linkedlistNode *bufNode = head;
    linkedlistNode *nextNode = nullptr;
    bool ishead = true;
    while(bufNode->next!=nullptr){
        if(bufNode->data == data)
            break;
        else{
            if (bufNode->next->data == data)
                break;
            else
                bufNode = bufNode->next;
        }
        ishead = false;
    }
    // head
    if(ishead){
        bufNode = head->next;
        delete head;
        head = bufNode;
    }
    // tail
    else if(nextNode->next==nullptr){
        delete nextNode;
        bufNode->next = nullptr;
    }
    // middle
    else{
        nextNode = bufNode->next->next;
        delete bufNode->next;
        bufNode->next = nextNode;
    }
}

void LinkedList::traversalOrder(){
    linkedlistNode *bufNode = head;
    while(bufNode!=nullptr){
        std::cout << bufNode->data << " ";
        bufNode = bufNode->next;
    }
    std::cout << std::endl;
}

void testLinkedList(){
    // allocate object
    LinkedList linkedList;

    uint8_t index = 0;
    int testArr[] = {1,2,3,4,5,6,7,8};
    uint32_t sizeTestArr = int(sizeof(testArr)/sizeof(int));
    
    // insert
    for(index=0; index<sizeTestArr; index++)
        linkedList.prepend(testArr[index]);
    
    std::cout << "  After prepend" << std::endl;
    linkedList.traversalOrder();

    for(index=0; index<sizeTestArr; index++)
        linkedList.append(testArr[index]);
    
    std::cout << " After Append" << std::endl;
    linkedList.traversalOrder();

    bool is_cycle=linkedList.is_cycle();
    std::cout << "Is cycle? " << is_cycle << std::endl;
}