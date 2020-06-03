#include <iostream>
#include <fstream>
#include <algorithm> //algorithm library only used for is_sorted() function to check if heap works correctly
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include "PriorityQueue.h"
#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"

int main()
{
    srand(time(NULL));

    /* Unsorted Queue testing */
    std::cout << "--Unsorted Queue pre-liminary testing--" << std::endl;
    UnsortedPQ<int> queue1;
    try                                                         // check empty queue
    {
        std::cout << queue1.minValue() << std::endl;            //minValue() should throw exception "Empty Queue"
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << " exception" << std::endl;
    }
    for(int i = 0; i < 10; i++)
    {
        queue1.insertItem(rand() % 100);
    }
    std::cout << "Unsorted Queue contents: ";
    queue1.printQueue();
    std::cout << "Unsorted Queue size: " << queue1.getSize() << std::endl;  //getSize() should return 10
    std::cout << "Unsorted Queue's Minimum Value: " << queue1.minValue() << std::endl;
    std::cout << "Unsorted Queue removed Min Value: " << queue1.removeMin() << std::endl;
    std::cout << "Unsorted Queue contents after removeMin(): ";
    queue1.printQueue();
    std::cout << std::endl;

    /* Sorted Queue testing */
    std::cout << "--Sorted Queue pre-liminary testing--" << std::endl;
    SortedPQ<int> queue2;
    try                                                 // check empty queue
    {
        std::cout << queue2.minValue() << std::endl;    //minValue() should throw exception "Empty Queue"
    } 
    catch (const std::exception& e)
    {
        std::cout << e.what() << " exception" << std::endl;
    }
    for (int i = 0; i < 10; i++)
    {
        queue2.insertItem(rand() % 100);
    }
    std::cout << "Sorted Queue contents: ";
    queue2.printQueue();
    std::cout << "Sorted Queue size: " << queue2.getSize() << std::endl; //getSize() should return 10
    std::cout << "Sorted Queue's Minimum Value: " << queue2.minValue() << std::endl;
    std::cout << "Sorted Queue's removed Min Value: " << queue2.removeMin() << std::endl;
    std::cout << "Sorted Queue contents after removeMin(): ";
    queue2.printQueue();
    std::cout << std::endl;

    /* Heap Priority Queue testing */
    std::cout << "--Heap Queue pre-liminary testing--" << std::endl;
    HeapPQ<int> queue3;
    try                                                 // check empty queue
    {
        std::cout << queue3.minValue() << std::endl;    //minValue() should throw exception "Empty Queue"
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << " exception" << std::endl;
    }
    for (int i = 0; i < 10; i++)                       //insert random numbers into heap pq
    {
        queue3.insertItem(rand() % 100);
    }
    std::cout << "Heap Queue contents: ";
    queue3.printPQ();
    std::cout << "Heap Queue size: " << queue3.getSize() << std::endl;  //should return size 10
    std::cout << "Heap Queue's Minimum Value: " << queue3.minValue() << std::endl;
    std::cout << "Heap Queue's removed Min Value: " << queue3.removeMin() << std::endl;
    std::cout << "Heap Queue contents after removeMin(): ";
    queue3.printPQ();

    /** 
     * This block is to test if removeMin() function works for Heap Priority Queue.
     * It appends all removed minimums from the queue and checks if the end queue
     * is sorted.
     */
    std::vector<int> allMin;
    for(int i = 0; i < 9; i++)
    {
        allMin.push_back(queue3.removeMin());
    }
    if(is_sorted(allMin.begin(), allMin.end()))
        std::cout << "removeMin() function produces ordered minimum values!" << std::endl;
    else
    {
        std::cout << "removeMin() function error" << std::endl;
        // for(int i = 0; i < allMin.size(); i++)
        // {
        //     std::cout << allMin[i] << " ";
        // }
        // std::cout << std::endl;
    }
    std::cout << std::endl;

    /* File reading test */
    std::cout << "--File testing--" << std::endl;
    ifstream inFile("numbers.txt");
    if(inFile.is_open())
    {
        std::cout << "File \"numbers.txt\" opened successfully" << std::endl;
        int qType = -1;
        int n = 0;
        inFile >> qType >> n;
        if (qType == 0)                                 // insert into unsorted queue
        {
            std::cout << "Inserting " << n << " numbers into unsorted queue" << std::endl;
            UnsortedPQ<int> fileQ;
            int data = -1;
            while(!inFile.eof())
            {
                inFile >> data;
                fileQ.insertItem(data);
            }
            std::cout << "File Queue contents: ";
            fileQ.printQueue();
            std::cout << "Removing all elements in queue..." << std::endl;
            for(int i = 0; i < n; i++)
            {
                std::cout << fileQ.removeMin() << std::endl;
            }
            std::cout << "Is the queue empty? ";
            if (fileQ.isEmpty())
                std::cout << "Yes" << std::endl;
            else
                std::cout << "No" << std::endl;
        }
        else if (qType == 1)                            // insert into sorted queue
        {
            std::cout << "Inserting " << n << " numbers into sorted queue" << std::endl;
            SortedPQ<int> fileQ;
            int data = -1;
            while (!inFile.eof())
            {
                inFile >> data;
                fileQ.insertItem(data);
            }
            std::cout << "File Queue contents: ";
            fileQ.printQueue();
            std::cout << "Removing all elements in queue..." << std::endl;
            for (int i = 0; i < n; i++)
            {
                std::cout << fileQ.removeMin() << std::endl;
            }
            std::cout << "Is the queue empty? ";
            if(fileQ.isEmpty())
                std::cout << "Yes" << std::endl;
            else   
                std::cout << "No" << std::endl;
        }
        else if (qType == 2)                            // insert into heap pq
        {
            std::cout << "Inserting " << n << " numbers into heap queue" << std::endl;
            HeapPQ<int> fileQ;
            int data = -1;
            while (!inFile.eof())
            {
                inFile >> data;
                fileQ.insertItem(data);
            }
            std::cout << "File Queue contents: ";
            fileQ.printPQ();
            std::cout << "Removing all elements in queue..." << std::endl;
            for (int i = 0; i < n; i++)
            {
                std::cout << fileQ.removeMin() << std::endl;
            }
            std::cout << "Is the queue empty? ";
            if (fileQ.isEmpty())
                std::cout << "Yes" << std::endl;
            else
                std::cout << "No" << std::endl;
        }
        else
        {
            std::cout << "Invalid data in file" << std::endl;
        }
    }
    else
    {
        std::cout << "Could not open \"numbers.txt\"" << std::endl;
    }
    std::cout << std::endl;

    /*------------------------------------------------------------------------------------------------------------------------------------------------------*/

    /* Begin testing time complexity */
    std::chrono::steady_clock::time_point t1; // initialize timer
    std::chrono::steady_clock::time_point t2;
    std::chrono::duration<double> time_span;
    int n = 100000;

    /* Unsorted Queue push only */
    ofstream outFile1("UnsortedPQ_push_" + std::to_string(n) + ".csv");
    outFile1 << "n,time(seconds)" << std::endl;
    std::cout << "--Testing complexity of " + std::to_string(n) + " pushes for unsorted queue--" << std::endl;

    UnsortedPQ<int> unsortedPush;
    t1 = std::chrono::steady_clock::now(); // start timer
    for (int i = 0; i < n; i++)
    {
        unsortedPush.insertItem(rand() % 100);
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile1 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t" << "Time = " << time_span.count() << std::endl;    //gives status update on time every 100,000 pushes
        }
    }
    std::cout << "Total Time: " << time_span.count() << " seconds" << std::endl << std::endl;

    /* Sorted Queue push only */
    ofstream outFile2("SortedPQ_push_" + std::to_string(n) + ".csv");
    outFile2 << "n,time(seconds)" << std::endl;
    std::cout << "--Testing complexity of " + std::to_string(n) + " pushes for sorted queue--" << std::endl;

    SortedPQ<int> sortedPush;
    t1 = std::chrono::steady_clock::now(); // start timer
    for (int i = 0; i < n; i++)
    {
        sortedPush.insertItem(rand() % 100);
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile2 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t" << "Time = " << time_span.count() << std::endl;    //gives status update on time every 100,000 pushes
        }
    }
    std::cout << "Total Time: " << time_span.count() << " seconds" << std::endl << std::endl;

    /* Heap Queue push only */
    ofstream outFile3("HeapPQ_push_" + std::to_string(n) + ".csv");
    outFile3 << "n,time(seconds)" << std::endl;
    std::cout << "--Testing complexity of " + std::to_string(n) + " pushes for heap queue--" << std::endl;

    HeapPQ<int> heapPush;
    t1 = std::chrono::steady_clock::now(); // start timer
    for (int i = 0; i < n; i++)
    {
        heapPush.insertItem(rand() % 100);
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile3 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t" << "Time = " << time_span.count() << std::endl;    //gives status update on time every 100,000 pushes
        }
    }
    std::cout << "Total Time: " << time_span.count() << " seconds" << std::endl << std::endl;

    /* Unsorted Queue push and remove */
    ofstream outFile4("UnsortedPQ_full_" + std::to_string(n) + ".csv");
    outFile4 << "n,time(seconds)" << std::endl;
    std::cout << "--Testing complexity of " + std::to_string(n) + " pushes and removes for unsorted queue--" << std::endl;

    UnsortedPQ<int> unsortedFull;
    t1 = std::chrono::steady_clock::now(); // start timer
    std::cout << "Pushing..." << std::endl;
    for (int i = 0; i < n; i++)
    {
        unsortedFull.insertItem(rand() % 100);
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile4 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t" << "Time = " << time_span.count() << std::endl; //gives status update on time every 100,000 pushes
        }
    }
    std::cout << "Done" << std::endl;
    std::cout << "Removing..." << std::endl;
    for (int i = n; i < (2*n); i++)
    {
        unsortedFull.removeMin();
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile4 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t" << "Time = " << time_span.count() << std::endl; //gives status update on time every 100,000 pushes
        }
    }
    std::cout << "Done" << std::endl;
    std::cout << "Total Time: " << time_span.count() << " seconds" << std::endl << std::endl;

    /* Sorted Queue push and remove */
    ofstream outFile5("SortedPQ_full_" + std::to_string(n) + ".csv");
    outFile5 << "n,time(seconds)" << std::endl;
    std::cout << "--Testing complexity of " + std::to_string(n) + " pushes and removes for sorted queue--" << std::endl;

    SortedPQ<int> sortedFull;
    t1 = std::chrono::steady_clock::now(); // start timer
    std::cout << "Pushing..." << std::endl;
    for (int i = 0; i < n; i++)
    {
        sortedFull.insertItem(rand() % 100);
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile5 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t"
            //               << "Time = " << time_span.count() << std::endl; //gives status update on time every 100,000 pushes
        }
    }
    std::cout << "Done" << std::endl;
    std::cout << "Removing..." << std::endl;
    for (int i = n; i < (2*n); i++)
    {
        sortedFull.removeMin();
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile5 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t" << "Time = " << time_span.count() << std::endl; //gives status update on time every 100,000 removes
        }
    }
    std::cout << "Done" << std::endl;
    std::cout << "Total Time: " << time_span.count() << " seconds" << std::endl << std::endl;

    /* Heap Queue push and remove */
    ofstream outFile6("HeapPQ_full_" + std::to_string(n) + ".csv");
    outFile6 << "n,time(seconds)" << std::endl;
    std::cout << "--Testing complexity of " + std::to_string(n) + " pushes and removes for heap queue--" << std::endl;

    HeapPQ<int> heapFull;
    t1 = std::chrono::steady_clock::now(); // start timer
    std::cout << "Pushing..." << std::endl;
    for (int i = 0; i < n; i++)
    {
        heapFull.insertItem(rand() % 100);
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile6 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t"
            //               << "Time = " << time_span.count() << std::endl; //gives status update on time every 100,000 removes
        }
    }
    std::cout << "Done" << std::endl;
    std::cout << "Removing..." << std::endl;
    for (int i = n; i < (2*n); i++)
    {
        heapFull.removeMin();
        if ((i > 0) && (i % 100 == 0))
        {
            t2 = std::chrono::steady_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            outFile6 << i << "," << time_span.count() << std::endl;
            // if (i % 100000 == 0)
            //     std::cout << "i = " << i << "\t"
            //               << "Time = " << time_span.count() << std::endl; //gives status update on time every 100,000 removes
        }
    }
    std::cout << "Done" << std::endl;
    std::cout << "Total Time: " << time_span.count() << " seconds" << std::endl << std::endl;
    std::cout << "End Program" << std::endl;
}