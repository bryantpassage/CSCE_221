#include <iostream>
#include "Stack.h"

template<typename T>
struct Node
{
    T data;
    Node* next;
    Node() {}
    Node(T input):
        data(input), next(nullptr) {}
    ~Node() {}
};

template<typename T>
class LinkedList : public AbstractStack<T>
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList():
        head(nullptr), tail(nullptr) {}
    ~LinkedList()
    {
        if(head == nullptr) {}
        else
        {
            Node<T>* cur = head;
            while(cur->next != nullptr)
            {
                head = cur->next;
                delete cur;
                cur = head;
            }
            delete tail;
        }
    }

    T top() 
    {
        return head->data;
    }

    T pop() 
    {
        if(AbstractStack<T>::sizeIndex == 0) {}
        else
        {
            AbstractStack<T>::sizeIndex--;
            Node<T>* cur = head;
            Node<T> tempNode;
            if(cur->next == nullptr)
            {
                tempNode.data = cur->data;
                delete cur;
                head = nullptr;
                tail = nullptr;
                return tempNode.data;
            }
            head = cur->next;
            tempNode.data = cur->data;
            delete cur;
            return tempNode.data;
        }
    }

    void push(T input) 
    {
        Node<T>* newData = new Node<T>(input);
        if(AbstractStack<T>::sizeIndex == 0)
        {
            head = newData;
            tail = newData;
        }
        else
        {
            newData->next = head;
            head = newData;
        }
        AbstractStack<T>::sizeIndex++;
    }
};