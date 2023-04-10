#include <iostream>
#include <stack>

const char* basket[] = {"{}", "()", "[]"};

bool is_open(char c){
    uint8_t i;
    for(i=0; i<3; i++){
        if(c == basket[i][0])
            return true;
    }
    return false;
}
bool is_match(char c1, char c2){
    uint8_t i;
    for(i=0; i<3; i++){
        if (c1 == basket[i][0])
            return c2 == basket[i][1];
    }
    return false;
}

bool isBalanced(std::string expression) {
    std::stack<int> stack;
    uint16_t i;
    for(i=0; i<expression.size(); i++){
        if(is_open(expression[i]))
            stack.push(expression[i]);
        else{
            if(stack.empty() || !(is_match(stack.top(), expression[i])))
                return false;
            else
                stack.pop();
        }
    }
    return stack.empty();
}

void testBalancedParenthesesinExpression() {
    std::string expression = "{()[{({})[]()}]}([])";
    bool result = isBalanced(expression);
    std::cout << "Got" << expression << std::endl;
    std::cout << "Balanced? "<< result << std::endl;
    std::cout << "------------" << std::endl;

    expression = "{()[{({})[]()}]}([]";
    result = isBalanced(expression);
    std::cout << "Got" << expression << std::endl;
    std::cout << "Balanced? "<< result << std::endl;
    std::cout << "------------" << std::endl;

    expression = "{()[{({})[]()}]}([])/";
    result = isBalanced(expression);
    std::cout << "Got" << expression << std::endl;
    std::cout << "Balanced? "<< result << std::endl;
    std::cout << "------------" << std::endl;
}