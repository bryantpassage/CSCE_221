#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include <chrono>
#include <algorithm>
#include <assert.h>
#include "Sorts.h"

void printList(int* l, int n)       //print list for debugging
{
    for(int i = 0; i < n; i++)
    {
        std::cout << l[i] << " ";
    }
    std::cout << std::endl;
}

bool checkSorted(int* l1, int* l2, int* l3, int* l4, int* l5, int n)
{
    return (!std::is_sorted(l1, l1 + n) || !std::is_sorted(l2, l2 + n) || !std::is_sorted(l3, l3 + n) || !std::is_sorted(l4, l4 + n) || !std::is_sorted(l5, l5 + n));
}

int main()
{
    srand(time(NULL));
    /* test files given */
    std::ifstream inFile("numbers.txt");
    if(inFile.is_open())
    {
        int sortv, length;
        inFile >> sortv >> length;                  // get sort type and length of array
        int* numList = new int[length];
        int data;

        for (int i = 0; i < length; i++)            // retrieve all data elements from file
        {
            inFile >> data;
            numList[i] = data;
        }

        if(sortv == 1)                              // bubble sort
        {
            printList(numList, length);
            bubbleSort(numList, length);
            printList(numList, length);
        }

        else if(sortv == 2)                         // heap sort
        {
            printList(numList, length);
            heapSort(numList, length);
            printList(numList, length);
        }

        else if(sortv == 3)
        {
            printList(numList, length);
            mergeSort(numList, 0, length - 1);      // merge sort
            printList(numList, length);
        }

        else if (sortv == 4)
        {
            printList(numList, length);
            quickSort(numList, 0, length - 1);      // quicksort
            printList(numList, length);
        }

        else if (sortv == 5)
        {
            printList(numList, length);
            radixSort(numList, length);             // radix sort
            printList(numList, length);
        }

        else
        {
            std::cout << "Invalid file format!" << std::endl;
        }
        
        delete[] numList;
    }
    else
    {
        std::cout << "File \"numbers.txt\" could not be opened." << std::endl;
    }

    /* instantiate clock variables */
    std::chrono::steady_clock::time_point t1; // initialize timer
    std::chrono::steady_clock::time_point t2;
    std::chrono::duration<double> time_span;

    std::stringstream ss;

    /* test random sorting */
    // std::ofstream outFile("AlgorithmTimeRandom.csv");
    // outFile << "n, bubble, merge, heap, quick, radix" << std::endl;

    int n = 100;
    int range = 100000;
    for(int i = 0; i < 100; i++)
    {
        int* bubbleList = new int[n];
        int* mergeList = new int[n];
        int* heapList = new int[n];
        int* quickList = new int[n];
        int* radixList = new int[n];
        for(int j = 0; j < n; j++)
        {
            int randNum = rand() % range;
            bubbleList[j] = randNum;
            mergeList[j] = randNum;
            heapList[j] = randNum;
            quickList[j] = randNum;
            radixList[j] = randNum;
        }

        // std::cout << "Creating arrays" << std::endl;
        
        std::cout << "Starting test for n=" << n << std::endl;
        t1 = std::chrono::steady_clock::now();
        bubbleSort(bubbleList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << n << "," << time_span.count() << ",";
        // std::cout << "Finished bubble sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        mergeSort(mergeList, 0, n - 1);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished merge sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        heapSort(heapList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished heap sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        quickSort(quickList, 0, n - 1);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished quick sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        radixSort(radixList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished radix sort for n=" << n << std::endl;

        // outFile << ss.str() << std::endl;
        ss.str(std::string());
        n += 100;

        assert(checkSorted(bubbleList, mergeList, heapList, quickList, radixList, n));  //check if list are sorted; if not, exit out

        delete[] bubbleList;
        delete[] mergeList;
        delete[] heapList;
        delete[] quickList;
        delete[] radixList;
    }

    /* test already sorted lists */
    // std::ofstream outFile2("AlgorithmTimeSorted.csv");
    // outFile2 << "n, bubble, merge, heap, quick, radix" << std::endl;

    n = 100;
    range = 100000;
    for (int i = 0; i < 100; i++)
    {
        int *bubbleList = new int[n];
        int *mergeList = new int[n];
        int *heapList = new int[n];
        int *quickList = new int[n];
        int *radixList = new int[n];
        for (int j = 0; j < n; j++)
        {
            // int randNum = rand() % range;
            bubbleList[j] = j;
            mergeList[j] = j;
            heapList[j] = j;
            quickList[j] = j;
            radixList[j] = j;
        }

        // std::cout << "Creating arrays" << std::endl;

        std::cout << "Starting test for n=" << n << std::endl;
        t1 = std::chrono::steady_clock::now();
        bubbleSort(bubbleList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << n << "," << time_span.count() << ",";
        // std::cout << "Finished bubble sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        mergeSort(mergeList, 0, n - 1);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished merge sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        heapSort(heapList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished heap sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        quickSort(quickList, 0, n - 1);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished quick sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        radixSort(radixList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished radix sort for n=" << n << std::endl;

        // outFile2 << ss.str() << std::endl;
        ss.str(std::string());
        n += 100;

        assert(checkSorted(bubbleList, mergeList, heapList, quickList, radixList, n)); //check if list are sorted; if not, exit out

        delete[] bubbleList;
        delete[] mergeList;
        delete[] heapList;
        delete[] quickList;
        delete[] radixList;
    }

    /* test random sorting */
    // std::ofstream outFile3("AlgorithmTimeReverseSorted.csv");
    // outFile3 << "n, bubble, merge, heap, quick, radix" << std::endl;

    n = 100;
    range = 100000;
    for (int i = 0; i < 100; i++)
    {
        int *bubbleList = new int[n];
        int *mergeList = new int[n];
        int *heapList = new int[n];
        int *quickList = new int[n];
        int *radixList = new int[n];
        for (int j = 0; j < n; j++)
        {
            // int randNum = rand() % range;
            bubbleList[j] = n - j - 1;
            mergeList[j] = n - j - 1;
            heapList[j] = n - j - 1;
            quickList[j] = n - j - 1;
            radixList[j] = n - j - 1;
        }

        // std::cout << "Creating arrays" << std::endl;

        std::cout << "Starting test for n=" << n << std::endl;
        t1 = std::chrono::steady_clock::now();
        bubbleSort(bubbleList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << n << "," << time_span.count() << ",";
        // std::cout << "Finished bubble sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        mergeSort(mergeList, 0, n - 1);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished merge sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        heapSort(heapList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished heap sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        quickSort(quickList, 0, n - 1);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished quick sort for n=" << n << std::endl;

        t1 = std::chrono::steady_clock::now();
        radixSort(radixList, n);
        t2 = std::chrono::steady_clock::now();
        time_span = t2 - t1;
        ss << time_span.count() << ",";
        // std::cout << "Finished radix sort for n=" << n << std::endl;

        // outFile3 << ss.str() << std::endl;
        ss.str(std::string());
        n += 100;

        assert(checkSorted(bubbleList, mergeList, heapList, quickList, radixList, n)); //check if list are sorted; if not, exit out

        delete[] bubbleList;
        delete[] mergeList;
        delete[] heapList;
        delete[] quickList;
        delete[] radixList;
    }
}