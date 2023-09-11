#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

void testBalancedParenthesesinExpression();
void testQueueWithTwoStack();
void testStack();
void testQueue();
void testIsCycle();
void testLinkedList();
void testCheckBST();
void testBinarySearchTree();
void testContactString();
void testMinHeap();

class linkedlistNode{
private:
public:
    int data;
    class linkedlistNode *next;
    linkedlistNode(int data);
    ~linkedlistNode();
};

class treeNode{
private:
public:
    int data;
    class treeNode* left;
    class treeNode* right;
    treeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    };
    ~treeNode(){};
    void getchild(treeNode* leftNode, treeNode* rightNode);
};

void testGraph();
#endif
