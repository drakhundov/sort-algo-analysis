#include "sorting.h"

/*
 ! Divide and Conqier Algorithm.
 * Time Complexity: O(nlogn)
 * Space Complexity: O(logn)
 ! Adaptive: No
 ! Stable: Yes
 * Applications:
 *   Stability requirement.
 *   Large datasets (O(nlogn) is guaranteed).
 ! Worse that Quick Sort in practice.
 ! Avoid for in-place sorting (Quick Sort or Heap Sort are better).
 ! Avoid using on small arrays.
 */

void mergeSort(std::vector<int> &v, int left, int right) {
  void merge(std::vector<int> &, int, int, int);
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
  }
}

void merge(std::vector<int> &v, int left, int mid, int right) {
  // Left array: left, mid
  // Right array: mid + 1, right
  int i, j, k, tmp;
  i = left;
  j = mid + 1;
  while (i <= mid && j <= right) {
    if (v[i] <= v[j]) {
      i++;
    } else {
      tmp = v[j];
      k = j;
      while (k != i) {
        v[k] = v[k - 1];
        k--;
      }
      v[i] = tmp;
      i++;
      j++;
      mid++;
    }
  }
}