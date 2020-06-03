#pragma once

#include "Node.h"
#include <assert.h>

template <typename T>
class Deque
{
private:
    int s;
    Node<T>* firstNode;
    Node<T>* lastNode;

public:
    Deque():
        s(0), firstNode(nullptr), lastNode(nullptr) {}

    ~Deque()
    {
        if(firstNode != nullptr)
        {
            Node<T>* cur = firstNode;
            while(cur != lastNode)
            {
                cur = cur->getNext();
                delete firstNode;
                firstNode = cur;
            }
            delete lastNode;
            firstNode = nullptr;
            lastNode = nullptr;
        }
    }

    bool isEmpty()
    {
        if(s == 0)
            return true;
        return false;
    }

    int size()
    {
        return s;
    }

    T first()
    {
        assert(!isEmpty());
        return firstNode->getData();
    }

    T last()
    {
        assert(!isEmpty());
        return lastNode->getData();
    }

    void insertFirst(T o)
    {
        Node<T>* newData = new Node<T>(o);
        if(s != 0)
        {
            newData->setNext(firstNode);
            firstNode->setPrev(newData);
            firstNode = newData;
        }
        else
        {
            firstNode = newData;
            lastNode = newData;
        }
        s++;        
    }

    void insertLast(T o)
    {
        Node<T>* newData = new Node<T>(o);
        if (s != 0)
        {
            newData->setPrev(lastNode);
            lastNode->setNext(newData);
            lastNode = newData;
        }
        else
        {
            firstNode = newData;
            lastNode = newData;
        }
        s++;
    }

    T removeFirst()
    {
        assert(!isEmpty());
        T tempData = firstNode->getData();
        if(s == 1)
        {
            delete firstNode;
            firstNode = nullptr;
            lastNode = nullptr;
        }
        else
        {
            Node<T>* cur = firstNode;
            firstNode = cur->getNext();
            delete cur;
            firstNode->setPrev(nullptr);
        }
        s--;
        return tempData;       
    }

    T removeLast()
    {
        assert(!isEmpty());
        T tempData = lastNode->getData();
        if (s == 1)
        {
            delete lastNode;
            firstNode = nullptr;
            lastNode = nullptr;
        }
        else
        {
            Node<T>* cur = lastNode;
            lastNode = cur->getPrev();
            delete cur;
            lastNode->setNext(nullptr);
        }
        s--;
        return tempData;
    }
};