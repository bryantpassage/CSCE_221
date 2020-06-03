#ifndef SORTS_H
#define SORTS_H

void bubbleSort(int* l, int n);

void mergeSort(int* l, int start, int end);
void merge(int* l, int start, int mid, int end);

void heapSort(int* l, int n);

void quickSort(int* list, int l, int r);
int partition(int* list, int p, int l, int r);

void countingSort(int* list, int n, int place);
void radixSort(int* list, int n);
int getMax(int* list, int n);

#endif