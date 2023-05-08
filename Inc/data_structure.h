#ifndef DATA_STRUCTURE
#define DATA_STRUCTURE

void testBalancedParenthesesinExpression();
void testQueueWithTwoStack();
void testStack();
void testQueue();
void testIsCycle();
void testLinkedList();
void testCheckBST();
void testBinarySearchTree();
void testContactString();

// struct Node{
//     int data;
//     struct Node *next;
// };

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

#endif
