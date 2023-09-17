#include "iostream"
#include "../../Inc/data_structure.hpp"

void preorder(treeNode *root, treeNode *node=nullptr){
    if(root!=nullptr){
        if(node==nullptr) node = root;

        std::cout << node->data << "(" << node << ")" << " ";

        if(node->left != nullptr){
            // if(node->left->left != nullptr) 
            preorder(root, node->left);
            // else{
            //     std::cout << node->left->data << "(" << node->left << ")" << " ";
            // }
        }

        if(node->right != nullptr){
            preorder(node->right);
        }
    }    
}

void inorder(treeNode *root, treeNode *node=nullptr){
    if(root!=nullptr){
        if(node==nullptr) node = root;

        if(node->left != nullptr){
            // if(node->left->left == nullptr){
            //     std::cout << node->left->data << "(" << node->left << ")" << " ";
            // }
            // else{
            inorder(node->left);
            // }
        }

        std::cout << node->data << "(" << node << ")" << " ";

        if(node->right != nullptr){
            inorder(node->right);
        }
    }
}

void postorder(treeNode *root, treeNode *node=nullptr){
    if(root!=nullptr){
        if(node==nullptr) node = root;

        if(node->left != nullptr){
            // if(node->left->left != nullptr) 
            postorder(root, node->left);
            // else if (node->left->right != nullptr)
            //     postorder(root, node->left->right);
            // else{
            //     std::cout << "del " <<node->left->data << "(" << node->left << ")" << " ";
            //     delete node->left;
            // }
        }
        
        if(node->right != nullptr){
            postorder(root, node->right);
        }

        std::cout << "del " << node->data << "(" << node << ")" << " ";
        delete node;
    }
}


class BinarySearchTree{
private:
    treeNode *root;
public:
    void insert(int data, treeNode *node);
    bool contain(int data, treeNode *node);
    void printInorder();
    void printPreorder();
    // void printPostorder();

    BinarySearchTree();
    ~BinarySearchTree();
};
BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree(){ //TODO
    std::cout << "Destructor and Post order\n";
    postorder(root);
}

void BinarySearchTree::insert(int data, treeNode *node=nullptr){
    if(root == nullptr){
        std::cout << "Root" << data << std::endl; 
        root = new treeNode(data);
        root->getchild(nullptr, nullptr);
    }
    else{
        if(node==nullptr)node = root;

        if(data <= node->data){
            std::cout<< " << ";
            if(node->left == nullptr){
                std::cout << data<< std::endl;
                node->left = new treeNode(data);
                node->left->getchild(nullptr, nullptr);
            }
            else
                insert(data, node->left);
        }
        else{
            std::cout<< " >> ";
            if(node->right == nullptr){
                std::cout << data << std::endl;
                node->right = new treeNode(data);
                node->right->getchild(nullptr, nullptr);
            }
            else
                insert(data, node->right);
        }
    }
}

bool BinarySearchTree::contain(int data, treeNode *node=nullptr){ //TODO
    if (root == nullptr)
        return false;
    else{
        if(node == nullptr) node = root;

        if(data == node->data)
            return true;
        else{
            if(data < node->data)
            { 
                if(node->left == nullptr)
                    return false;
                else  
                    return contain(data, node->left);
            }
            else{
                if(node->right == nullptr)
                    return false;
                else
                    return contain(data, node->right);
            }
        }
    }

    return false;
}

void BinarySearchTree::printInorder(){
    inorder(root);
}

void BinarySearchTree::printPreorder(){
    preorder(root);
}


void testBinarySearchTree(){
    std::cout << "Hello Test Tree World!\n";
    int testArr[] = {10, 5, 20, 3, 9, 15, 25, 1, 4, 13, 17, 30, 19};
    uint32_t sizeTestArr = sizeof(testArr) / sizeof(int);
    uint32_t index;
    BinarySearchTree tree = BinarySearchTree();
    
    for(index=0; index<sizeTestArr; index++){ 
        std::cout << "  GO INSERT "<< testArr[index] << "\n";
        tree.insert(testArr[index]);
    }
    std::cout << std::endl;

    std::cout << "Print Inorder\n";
    tree.printInorder();
    std::cout << std::endl;

    std::cout << "Print Preorder\n";
    tree.printPreorder();
    std::cout << std::endl;

    uint32_t isel = 10;
    int num = testArr[isel];
    num = 500;
    std::cout << "Contain? "<< num << "\n";
    std::cout << tree.contain(num);
    std::cout << std::endl;
}