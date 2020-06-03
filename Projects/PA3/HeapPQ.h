#ifndef HEAP_PQ_H
#define HEAP_PQ_H

#include <iostream>
#include <exception>
#include <vector>
#include "assert.h"
#include "PriorityQueue.h"

template <typename T>
class HeapPQ : public PriorityQueue<T>
{
private:
    std::vector<T> arr;

    void swap(int p, int c)   //private helper function to swap parent and child
    {
        T temp = arr[p];
        arr[p] = arr[c];
        arr[c] = temp;
    }
    void downHeap()
    {
        int parent = 0;
        int leftC = parent * 2 + 1;
        int rightC = parent * 2 + 2;
        while (leftC <= PriorityQueue<T>::getSize() - 1)
        {
            if (arr[parent] > arr[leftC] || arr[parent] > arr[rightC])
            {
                if (arr[leftC] <= arr[rightC])
                {
                    swap(parent, leftC);
                    parent = leftC;
                }
                else
                {
                    swap(parent, rightC);
                    parent = rightC;
                }
                leftC = parent * 2 + 1;
                rightC = parent * 2 + 2;
            }
            else
                break;
        }
        // std::cout << "Min Val " << minValue << std::endl;
    }
    void upHeap()
    {
        int child = PriorityQueue<T>::size - 1;
        int parent = (child - 1) / 2;
        while (child > 0)
        {
            if (arr[child] < arr[parent])
                swap(parent, child);
            child = parent;
            parent = (child - 1) / 2;
        }
    }

public:
    HeapPQ() {}

    ~HeapPQ() {}

    // inserts a piece of data into the priority queue
    void insertItem(T data)
    {
        arr.push_back(data);         //insert new data and increment the size/lastIndex
        PriorityQueue<T>::size++;
        upHeap();
    }

    // removes and returns the minimum value in the queue
    // throws an exception if the queue is empty
    T removeMin()
    {
        if(PriorityQueue<T>::getSize() == 0)
            throw std::runtime_error("Empty queue");
        T minValue = arr[0];
        arr[0] = arr[PriorityQueue<T>::getSize() - 1];
        arr.pop_back();
        PriorityQueue<T>::size--;
        downHeap();
        return minValue;
    }

    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    T minValue()
    {
        if(PriorityQueue<T>::getSize() == 0)
            throw std::runtime_error("Empty queue");
        return arr[0];
    }

    // prints the Heap PQ for debugging
    void printPQ()
    {
        for(int i = 0; i < PriorityQueue<T>::size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif