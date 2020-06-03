#include <iostream>
#include <fstream>
#include <chrono>
#include "Stack.h"
#include "ArrayStack.cpp"
#include "DoubleArrayStack.cpp"
#include "LinkedList.cpp"

int main()
{
    /* Constant Array testing of functions */
    ArrayStack<int> testArray1(1);
    std::cout << testArray1.isEmpty() << std::endl; // expected output "1"
    testArray1.push(3);
    testArray1.push(4);
    std::cout << testArray1.top() << std::endl; // expected output "4"
    std::cout << testArray1.pop() << std::endl; // expected output "4"
    std::cout << testArray1.size() << std::endl; // expected output "1"
    std::cout << testArray1.isEmpty() << std::endl << std::endl; // expected output "0"

    /* Double Array testing of functions */
    DoubleArrayStack<int> testArray2(1);
    std::cout << testArray2.isEmpty() << std::endl; // expected output "1"
    testArray2.push(3);
    testArray2.push(4);
    std::cout << testArray2.top() << std::endl;     // expected output "4"
    std::cout << testArray2.pop() << std::endl;     // expected output "4"
    std::cout << testArray2.size() << std::endl;    // expected output "1"
    std::cout << testArray2.isEmpty() << std::endl << std::endl; // expected output "0"

    /* Linked List testing of functions */
    LinkedList<int> testArray3;
    std::cout << testArray3.isEmpty() << std::endl; // expected output "1"
    testArray3.push(3);
    testArray3.push(4);
    std::cout << testArray3.top() << std::endl;  // expected output "4"
    std::cout << testArray3.pop() << std::endl;  // expected output "4"
    std::cout << testArray3.size() << std::endl; // expected output "1"
    std::cout << testArray3.isEmpty() << std::endl << std::endl; // expected output "0"

    /*-----------------------------------------------------------------------------------------------------------------------*/

    std::chrono::steady_clock::time_point t1;  // initialize timer
    std::chrono::steady_clock::time_point t2;
    std::chrono::duration<double> time_span;

    /* Constant Array Stack Data Structure push of 10,000,000 integers */
    std::ofstream outFile1("StackPushDuration.csv");
    outFile1 << "n,time(seconds)" << std::endl;

    ArrayStack<int> myArray(1000);
    t1 = std::chrono::steady_clock::now(); // start timer
    for (int i = 0; i < 10000000; i++)
    {
        myArray.push(i);
        if((i > 0) && (i % 1000 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile1 << i << "," << time_span.count() << std::endl;
        }
    }

    /* Double Array Stack Data Structure push of 10,000,000 integers */
    std::ofstream outFile2("DoubleStackPushDuration.csv");
    outFile2 << "n,time(seconds)" << std::endl;

    DoubleArrayStack<int> myArray2(10000);
    t1 = std::chrono::steady_clock::now(); // start timer
    for (int i = 0; i < 10000000; i++)
    {
        myArray2.push(i);
        if ((i > 0) && (i % 1000 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile2 << i << "," << time_span.count() << std::endl;    
        }
    }

    /* Linked List Data Structure push of 10,000,000 integers */
    std::ofstream outFile3("LinkedListPushDuration.csv");
    outFile3 << "n, time(seconds)" << std::endl;
    
    LinkedList<int> myArray3;
    t1 = std::chrono::steady_clock::now(); // start timer
    for (int i = 0; i < 10000000; i++)
    {
        myArray3.push(i);
        if ((i > 0) && (i % 1000 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile3 << i << "," << time_span.count() << std::endl;
        }
    }

    /* Array debugging */
    // DoubleArrayStack<int> testArray(2);
    // for(int i = 0; i < 10; i++)
    // {
    //     testArray.push(i);
    // }
    // testArray.printStack();
}