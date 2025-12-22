#pragma once

#include <vector>

// Sort v given that all elements are <= max.
void countingSort(std::vector<int> &v, int max);

// Builds on top of counting sort. Applies counting sort per digit.
// ndigits == -1 => compute automatically
void radixSort(std::vector<int> &v, int ndigits = -1);

void mergeSort(std::vector<int> &v, int left, int right);

void quickSortUnixImpl(std::vector<int> &v, int left, int right);

void quickSortTwoPointers(std::vector<int> &v, int left, int right);

void selectionSort(std::vector<int> &v);

void insertionSort(std::vector<int> &v);

void bubbleSort(std::vector<int> &v);
