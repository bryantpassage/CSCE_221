#ifndef UNSORTED_PQ_H
#define UNSORTED_PQ_H

#include <iostream>
#include <exception>
#include "PriorityQueue.h"
#include "Node.h"

template<typename T>
class UnsortedPQ : public PriorityQueue<T>
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    UnsortedPQ():
        head(nullptr), tail(nullptr) {}

    ~UnsortedPQ()
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
            newData->prev = tail;
            tail->next = newData;
            tail = newData;
        }
        PriorityQueue<T>::size++;
    }

    // removes and returns the minimum value in the queue
    // throws an exception if the queue is empty
    T removeMin() 
    {
        T temp;
        if (PriorityQueue<T>::size == 0)
            throw std::runtime_error("Empty queue");    //throw exception if queue is empty
        if (PriorityQueue<T>::size == 1)
        {
            temp = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node<T>* cur = head->next;
            Node<T>* min = head;
            Node<T>* minPrev = nullptr;
            Node<T>* minNext = cur;
            while (cur != nullptr)
            {
                if (cur->data < min->data)
                {
                    min = cur;
                    minPrev = cur->prev;
                    minNext = cur->next;
                }
                cur = cur->next;
            }
            temp = min->data;
            if(minPrev == nullptr)
            {
                minNext->prev = nullptr;
                delete head;
                head = minNext;
            }
            else if(minNext == nullptr)
            {
                minPrev->next = nullptr;
                delete tail;
                tail = minPrev;
            }
            else
            {
                minPrev->next = minNext;
                minNext->prev = minPrev;
                delete min;
            }
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
        if (PriorityQueue<T>::size == 1)
        {
            T temp = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            return temp;
        }
        else
        {
            Node<T>* cur = head->next;
            Node<T>* min = head;
            while (cur != nullptr)
            {
                if (cur->data < min->data)
                    min = cur;
                cur = cur->next;
            }
            temp =  min->data;
        }
        return temp;
    }

    void printQueue()
    {
        Node<T>* cur = head;
        while(cur != nullptr)
        {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

#endif