#pragma once

#include <vector>

void countingSort(std::vector<int> &, int);

void radixSort(std::vector<int> &, int = -1);

void mergeSort(std::vector<int> &, int, int);
void merge(std::vector<int> &, int, int, int);

void quickSortUnixImpl(std::vector<int> &, int, int);
void quickSortTwoPointers(std::vector<int> &v, int left, int right);

void selectionSort(std::vector<int> &);

void insertionSort(std::vector<int> &);

void bubbleSort(std::vector<int> &);
