#include <iostream>
#include "Stack.h"

template <typename T>
class DoubleArrayStack : public AbstractStack<T>
{
private:
    T *array;
    int capacity; // maximum array size
public:
    DoubleArrayStack() : array(new T[100]), capacity(100) {} //default constructor
    DoubleArrayStack(int initSize) : array(new T[initSize]), capacity(initSize) {}
    ~DoubleArrayStack()
    {
        delete[] array;
    }
    // bool isEmpty() const;
    // int size() const;
    T top() 
    {
        if (AbstractStack<T>::isEmpty())
            return -1;
        return array[AbstractStack<T>::sizeIndex - 1]; 
    }
    T pop()
    {
        AbstractStack<T>::sizeIndex--; //decreases size by one to avoid accessing "popped" elements
        return array[AbstractStack<T>::sizeIndex];
    }
    void push(T input)
    {
        if (AbstractStack<T>::sizeIndex == capacity)
        {
            capacity *= 2;
            T *newArray = new T[capacity];
            for (int i = 0; i < AbstractStack<T>::sizeIndex; i++)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            newArray = nullptr;
        }
        array[AbstractStack<T>::sizeIndex] = input;
        // std::cout << "Array at " << AbstractStack<T>::sizeIndex << ": " << array[AbstractStack<T>::sizeIndex] << std::endl;
        AbstractStack<T>::sizeIndex++;
    }
    void printStack() // for debugging
    {
        for (int i = 0; i < AbstractStack<T>::sizeIndex; i++)
            std::cout << array[i] << std::endl;
    }
};