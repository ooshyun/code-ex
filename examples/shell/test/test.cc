#include "iostream"
#include "string.h"
// #include "../../Inc/ds_string_contacts.h"

#define NUMBER_OF_CHARACTERS 26

int getCharindex(char c){
    int buf = c;
    if((buf >= 65) && (buf <= 90))
        buf += 32; // "a" -> "A"
    return buf-97;
}

class ContactStringNode{
private:
    class ContactStringNode* children[NUMBER_OF_CHARACTERS];
    uint32_t size;
public:
    ContactStringNode* getNode(char c);
    void setNode(char c, ContactStringNode* node);
    void add(std::string s, uint32_t index);
    void del(ContactStringNode* node);
    uint32_t findCount(std::string s, uint32_t index);
    
    // void add(const char* s, size_t n);
    // void add(const char* s, size_t n, uint32_t index);
    // uint32_t findCount(const char* s, size_t n, uint32_t index);

    ContactStringNode();
    ~ContactStringNode();
};

ContactStringNode::ContactStringNode(){
    memset(&children[0], 0, sizeof(ContactStringNode*)*NUMBER_OF_CHARACTERS);
    size = 0;
}
ContactStringNode::~ContactStringNode(){
    del(this);
}

void ContactStringNode::del(ContactStringNode* node){
    uint8_t index;
    while(index<NUMBER_OF_CHARACTERS){
        if(node->children[index] != nullptr)
            del(node->children[index]);
        index++;
    }
    delete node;
}

ContactStringNode* ContactStringNode::getNode(char c){
    return children[getCharindex(c)];
}

void ContactStringNode::setNode(char c, ContactStringNode* node){
    children[getCharindex(c)] = node;
}

void ContactStringNode::add(std::string s, uint32_t index=0){
    // std::cout << "Hello Contact World\n";    
    size++;
    if(index == s.length()-1)return;
    
    // std::cout << index << s.at(index) << std::endl;
    ContactStringNode* node = getNode(s.at(index));

    if(node == nullptr)
    {
        // std::cout << "NEW!\n";
        node = new ContactStringNode; // TODO: it didn't make object
        setNode(s.at(index), node);
    }

    // std::cout << "Go Next\n";
    node->add(s, index+1);
}

uint32_t ContactStringNode::findCount(std::string s, uint32_t index=0){
    if(index == s.length()-1)
        return size;

    ContactStringNode* node = getNode(s.at(index));
    
    if(node == nullptr)
        return 0;

    return node->findCount(s, index+1);

}
void testContactString(){   
    std::string testCase[5] = {"Gayle", "Gary", "Geera", "Alex", "Andy"};
    ContactStringNode solutionTree;

    uint8_t index;
    for(index=0; index<5; index++)
    {
        std::cout << "Add " << testCase[index] << std::endl;
        solutionTree.add(testCase[index]);
    }

    std::string testCaseFindCount = "Ga";
    std::cout<< solutionTree.findCount(testCaseFindCount) << std::endl;

    std::string key = "U8D/NzdM/n9oqP0uxls7ObnUN7tQSPGAN2B+5b0sifU="
}