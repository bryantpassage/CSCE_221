#ifndef SORTED_PQ_H
#define SORTED_PQ_H

#include <iostream>
#include "PriorityQueue.h"
#include "Node.h"

template<typename T>
class SortedPQ : public PriorityQueue<T>
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SortedPQ():
        head(nullptr), tail(nullptr) {}
    
    ~SortedPQ()
    {
        Node<T>* cur = head;
        while(cur != nullptr)
        {
            cur = cur->next;
            delete head;
            head = cur;
        }
        head = nullptr;
        tail = nullptr;
    }

    // inserts a piece of data into the priority queue
    void insertItem(T data)
    {
        Node<T>* newData = new Node<T>(data);
        if(PriorityQueue<T>::size == 0)
        {
            head = newData;
            tail = newData;
        }
        else
        {
            Node<T>* finder = head;
            while(finder != nullptr && finder->data < newData->data)
                finder = finder->next;
            if(finder == nullptr)
            {
                newData->prev = tail;
                tail->next = newData;
                tail = newData;
            }
            else if(finder == head)
            {
                newData->next = head;
                head->prev = newData;
                head = newData;
            }
            else
            {
                finder->prev->next = newData;
                newData->prev = finder->prev;
                finder->prev = newData;
                newData->next = finder;
            }
        }
        PriorityQueue<T>::size++;
    }

    // removes and returns the minimum value in the queue
    // throws an exception if the queue is empty
    T removeMin()
    {
        T temp;
        if (PriorityQueue<T>::size == 0)
            throw std::runtime_error("Empty queue"); //throw exception if queue is empty
        else if(PriorityQueue<T>::size == 1)
        {
            temp = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            temp = head->data;
            Node<T>* cur = head->next;
            delete head;
            head = cur;
        }
        PriorityQueue<T>::size--;
        return temp;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    T minValue()
    {
        T temp;
        if (PriorityQueue<T>::size == 0)
            throw std::runtime_error("Empty queue");
        else
        {
            temp = head->data;
        }            
        return temp;
    }

    void printQueue()
    {
        Node<T> *cur = head;
        while (cur != nullptr)
        {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

#endif