#include <stdint.h>
#include <iostream>

struct NodeTestCycle{
    int data;
    struct NodeTestCycle* next;
};

bool is_cycle(NodeTestCycle* start) {
    // race with speed a, b, then if cycle then it will meet
    if (start == nullptr) return false;
    if (start->next == nullptr) return false;

    NodeTestCycle* fastNode = start->next;
    NodeTestCycle* slowNode = start;

    while((fastNode!=nullptr) && (fastNode->next!=nullptr)
                            && (slowNode!=nullptr)) {
        if (fastNode == slowNode) {
            return true;
        }
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
    }
    return false;
}

void testIsCycle() {
    int testArr[] = {1,2,3,4,5,6};

    NodeTestCycle* head = new NodeTestCycle;
    NodeTestCycle* cycleNode;
    NodeTestCycle* bufNode;

    head->data = testArr[0];
    head->next = new NodeTestCycle;
    
    bufNode = head->next;
    bufNode->data = testArr[1];
    bufNode->next = new NodeTestCycle;

    bufNode = bufNode->next;
    bufNode->data = testArr[2];
    bufNode->next = new NodeTestCycle;

    bufNode = bufNode->next;
    cycleNode = bufNode;
    bufNode->data = testArr[3];
    bufNode->next = new NodeTestCycle;

    bufNode = bufNode->next;
    bufNode->data = testArr[4];
    bufNode->next = new NodeTestCycle;

    bufNode = bufNode->next;
    bufNode->data = testArr[5];
    bufNode->next = nullptr;
    // bufNode->next = cycleNode;

    bool iscycle = is_cycle(head);

    std::cout << "Is cycle? " << iscycle << std::endl;

    // delete
    NodeTestCycle* delNode;
    bufNode = head;
    uint8_t index = 0;
    for(index=0; index<6; index++){
        delNode = bufNode;
        bufNode = bufNode->next;
        delete delNode;
    }
}