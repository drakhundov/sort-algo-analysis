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

void mergeSortInPlace(std::vector<int>& v, int left, int right) {
  void mergeInPlace(std::vector<int>&, int, int, int);
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSortInPlace(v, left, mid);
    mergeSortInPlace(v, mid + 1, right);
    mergeInPlace(v, left, mid, right);
  }
}

void mergeSortWithBuffer(std::vector<int>& v, int left, int right) {
  void mergeWithBuffer(std::vector<int>&, int, int, int);
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSortWithBuffer(v, left, mid);
    mergeSortWithBuffer(v, mid + 1, right);
    mergeWithBuffer(v, left, mid, right);
  }
}

// * Time Complexity: O(n^2)
// * Space Complexity: O(1)
void mergeInPlace(std::vector<int>& v, int left, int mid, int right) {
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

// * Time Complexity: O(n)
// * Space Complexity: O(n)
void mergeWithBuffer(std::vector<int>& v, int left, int mid, int right) {
  std::vector<int> buf;
  int i = left, j = mid + 1;
  while (i <= mid && j <= right) {
    if (v[i] <= v[j]) {
      buf.push_back(v[i++]);
    } else {
      buf.push_back(v[j++]);
    }
  }
  while (i <= mid) buf.push_back(v[i++]);
  while (j <= right) buf.push_back(v[j++]);
  std::copy(buf.begin(), buf.end(), v.begin() + left);
}
