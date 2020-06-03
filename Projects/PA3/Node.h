#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;

    Node():
        next(nullptr), prev(nullptr) {}
    
    Node(T o):
        data(o), next(nullptr), prev(nullptr) {}
    
    ~Node() {}    
};

#endif