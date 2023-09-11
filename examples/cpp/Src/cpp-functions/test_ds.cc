#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <list>
// template <typename T>
// #include <stdio.h>
// #include <stdlib.h>
// #include "sys/queue.h"

/*
    https://stackoverflow.com/questions/7904947/what-is-underlying-data-structure-of-stl-list-vector-and-set
    Based on comments, to clarify, these are the most common choices, but based on desired complexity and other factors, the backing of these implementations may vary:

    Vector = dynamically resizing array
    List = Doubly Linked List
    Set = Red/Black Tree (balanced Binary Search Tree)
*/
int testDataStructure() 
{
    printf("Hello Balanced Parentheses inExpression World!\n");

    std::stack<int> s;
    std::queue<std::string> q;
    std::set<int> st;
    std::map<int, int> m;
    std::vector<int> v;
    std::list<int> l;

    s.push(20);
    return 0;
}
