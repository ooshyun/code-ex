#include <iostream>
#include "../../Inc/data_structure.h"

void treeNode::getchild(treeNode* leftNode, treeNode* rightNode){
    left = leftNode;
    right = rightNode;
}

bool checkBST(treeNode* node, int min=INT32_MIN, int max=INT32_MAX){
    if (node==nullptr)
        return true;
    
    if (node->data < min || node->data > max)
        return false;

    return checkBST(node->left, min=min, max=node->data-1) && checkBST(node->right, min=node->data+1, max=max);
}

void testCheckBST(){
    treeNode root = treeNode(50);
    
    treeNode node11 = treeNode(10);
    treeNode node12 = treeNode(80);
    root.getchild(&node11, &node12);

    treeNode node21 = treeNode(5);
    treeNode node22 = treeNode(30);
    node11.getchild(&node21, &node22);

    treeNode node23 = treeNode(70);
    treeNode node24 = treeNode(90);
    node12.getchild(&node23, &node24);

    treeNode node33 = treeNode(20);
    treeNode node34 = treeNode(40);
    node22.getchild(&node33, &node34);

    treeNode node35 = treeNode(85);
    // treeNode node35 = treeNode(5);
    node24.getchild(&node35, nullptr);

    if (checkBST(&root))
        printf("Binary Search Tree? Yes %d\n", checkBST(&root));
    else
        printf("Binary Search Tree? No\n");

}