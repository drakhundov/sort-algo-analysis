#include "sorting.h"

/*
 ! Divide and Conqier Algorithm.
 * Time Complexity:
 *   Best Case: O(nlogn)
 *   Worst Cast O(n^2) [unbalanced partitions due to the pivot]
 * Space Complexity:
 *   Best Case: O(logn) [if the partitions divide the array perfectly]
 *   Worst Case: O(n)
 ! Adaptive: No
 ! Stable: No
 * Applications:
 *   General-purpose sorting.
 *   Large datasets.
 */

void quickSortUnixImpl(std::vector<int>& v, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  int last = left;
  std::swap(v[left], v[mid]);
  for (int i = left + 1; i <= right; i++) {
    if (v[i] < v[left]) {
      std::swap(v[++last], v[i]);
    }
  }
  std::swap(v[left], v[last]);
  quickSortUnixImpl(v, left, last - 1);
  quickSortUnixImpl(v, last + 1, right);
}

void quickSortTwoPointers(std::vector<int>& v, int left, int right) {
  if (left < right) {
    int pivot = v[left], pivotIndex;

    int l = left + 1, r = right;
    bool done = false;
    while (!done) {
      while (l <= r && v[l] <= pivot) {
        l++;
      }
      while (v[r] >= pivot && r >= l) {
        r--;
      }

      if (r < l) {
        done = true;
      } else {
        std::swap(v[l], v[r]);
      }
    }
    std::swap(v[left], v[r]);
    pivotIndex = r;
    quickSortTwoPointers(v, left, pivotIndex - 1);
    quickSortTwoPointers(v, pivotIndex + 1, right);
  }
}
