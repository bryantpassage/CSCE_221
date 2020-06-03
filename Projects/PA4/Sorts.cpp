#include <iostream>
#include <vector>
#include <utility>
#include "Sorts.h"
#include "Heap.h"
#include <exception>

void bubbleSort(int* l, int n)
{
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        int j = 0;
        while(j < n - i - 1)
        {
            if (l[j] > l[j + 1])
            {
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
            j++;
        }
    }
}

void heapSort(int* l, int n)
{
    Heap<int> hlist(l, n);
    for(int i = 0; i < n; i++)
    {
        l[i] = hlist.removeMin();
    }
}

void mergeSort(int* l, int start, int end)
{
    if(end > start)
    {
        int mid = (end + start) / 2;
        mergeSort(l, start, mid);
        mergeSort(l, mid+1, end);
        merge(l, start, mid, end);
    }
}

void merge(int* l, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    int* tempList = new int[end - start + 1];
    while(i <= mid && j <= end)
    {
        if(l[i] <= l[j])
        {
            tempList[k] = l[i];
            i++;
        }
        else
        {
            tempList[k] = l[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        tempList[k] = l[i];
        i++;
        k++;
    }
    while(j <= end)
    {
        tempList[k] = l[j];
        j++;
        k++;
    }
    for(int a = 0; a < k; a++)
    {
        l[a + start] = tempList[a];
    }
    delete[] tempList;
}

void quickSort(int* list, int l, int r)
{
    if(l < r)
    {
        // int pivot = (r + l) / 2;
        int pivot = r;
        int pIndex = partition(list, pivot, l, r);
        quickSort(list, l, pIndex - 1);
        quickSort(list, pIndex + 1, r);
    }
}

int partition(int* list, int p, int l, int r)
{
    std::vector<int> less;
    std::vector<int> greater;
    int pVal = list[p];
    for(int i = 0; i <= r-l; i++)
    {
        if(i + l != p)
        {
            if(list[i + l] <= pVal)
                less.push_back(list[i + l]);
            else
                greater.push_back(list[i + l]);
        }
    }
    int k = 0;
    for(int i = 0; i < less.size(); i++)
    {
        list[k + l] = less.at(i);
        k++;
    }
    int pivotIndex = k + l;
    list[pivotIndex] = pVal;
    k++;
    for(int i = 0; i < greater.size(); i++)
    {
        list[k + l] = greater.at(i);
        k++;
    }
    return pivotIndex;
}

// int partition(int* list, int p, int l, int r)
// {
//     int* less = new int[r-l];
//     int lSize = 0;
//     int* greater = new int[r-l];
//     int rSize = 0;
//     int pVal = list[p];
//     for(int i = 0; i <= r-l; i++)
//     {
//         if(i + l == p)
//             continue;
//         if(list[i + l] <= pVal)
//         {
//             less[lSize] = list[i + l];
//             lSize++;
//         }
//         else
//         {
//             greater[rSize] = list[i + l];
//             rSize++;
//         }
//     }
//     int k = 0;
//     for(int i = 0; i < lSize; i++)      //append less than array
//     {
//         list[k + l] = less[i];
//         k++;
//     }
//     int pivotIndex = k + l;
//     list[k + l] = pVal;                 //append pivot value -- also the pivot index
//     k++;
//     for(int i = 0; i < rSize; i++)      //append greater than array
//     {
//         list[k + l] = greater[i];
//         k++;
//     }
//     delete[] less;
//     delete[] greater;
//     return pivotIndex;
// }

int getMax(int* list, int n)
{
    int max = list[0];
    for(int i = 1; i < n; i++)
    {
        if(list[i] > max)
        {
            max = list[i];
        }
    }
    return max;
}

void countingSort(int* list, int n, int place)
{
    int countingArray[10] = {0};
    int* auxArray = new int[n];
    // auxArray = {};

    for(int i = 0; i < n; i++)
    {
        countingArray[(list[i] / place) % 10]++;
    }

    for(int i = 0; i < 9; i++)
    {
        countingArray[i+1] += countingArray[i];
    }

    for(int i = n - 1; i >= 0; i--)
    {
        auxArray[countingArray[(list[i] / place) % 10] - 1] = list[i];
        countingArray[(list[i] / place) % 10]--;
    }

    for(int i = 0; i < n; i++)
    {
        list[i] = auxArray[i];
    }
    delete[] auxArray;
}

void radixSort(int* list, int n)
{
    int max = getMax(list, n);

    for(int digit = 1; max/digit > 0; digit *= 10)
    {
        countingSort(list, n, digit);
    }
}