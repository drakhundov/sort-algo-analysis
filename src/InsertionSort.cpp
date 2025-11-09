#include "sorting.h"

/*
 * Time Complexity:
 *   Best Case: O(n)
 *   Worst Case: O(n^2)
 * Space Complexity: O(1)
 * Advantages:
 *   In-place: constant memory usage.
 *   Stable: maintains the relative order of equal elements.
 *   Adaptive: performs better on almost sorted data.
 *   Can sort data as it receives it.
 * Disadvantages:
 *   Quadratic time complexity.
 *   High memory access cost due to the swaps.
 * Applications:
 *   Sorting a stream of data
 *     (e.g. keyboard strokes, bank transactions, web apps).
 *   Small datasets.
 *   Almost sorted data.
 *   Complex sorting algorithms use it for small subarrays.
 *   Stable sorting requirement.
 */

void insertionSort(std::vector<int> &v) {
  int k;
  for (int i = 1, n = v.size(); i < n; i++) {
    if (v[i] > v[i - 1]) {
      continue;
    }
    k = i;
    while (k > 0 && v[k] < v[k - 1]) {
      std::swap(v[k], v[k - 1]);
      k--;
    }
  }
}