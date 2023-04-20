#include <stdint.h>
#include <iostream>

struct Node{
    int data;
    struct Node *next;
};

bool is_cycle(Node* start){
    // race with speed a, b, then if cycle then it will meet
    if (start == nullptr) return false;
    if (start->next == nullptr) return false;

    Node *fastNode = start->next;
    Node *slowNode = start;

    while((fastNode!=nullptr) && (fastNode->next!=nullptr) && (slowNode!=nullptr)){
        if (fastNode == slowNode){
            return true;
        }
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    }
    return false;
}

void testIsCycle(){
    int testArr[] = {1,2,3,4,5,6};

    Node* head = new Node;
    Node* cycleNode;
    Node* bufNode;

    head->data = testArr[0];
    head->next = new Node;
    
    bufNode = head->next;
    bufNode->data = testArr[1];
    bufNode->next = new Node;

    bufNode = bufNode->next;
    bufNode->data = testArr[2];
    bufNode->next = new Node;

    bufNode = bufNode->next;
    cycleNode = bufNode;
    bufNode->data = testArr[3];
    bufNode->next = new Node;
    
    bufNode = bufNode->next;
    bufNode->data = testArr[4];
    bufNode->next = new Node;

    bufNode = bufNode->next;
    bufNode->data = testArr[5];
    bufNode->next = nullptr;
    // bufNode->next = cycleNode;

    bool iscycle = is_cycle(head);

    std::cout << "Is cycle? " << iscycle << std::endl;

    // delete
    Node* delNode;
    bufNode = head;
    uint8_t index = 0;
    for(index=0; index<6; index++){
        delNode = bufNode;
        bufNode = bufNode->next;
        delete delNode;
    }
}