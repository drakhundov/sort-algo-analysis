#include "sorting.h"

/*
 ! Not used in practice.
 * Time Complexity:
 *   Best Case: O(n)
 *   Worst Case: O(n^2)
 * Space Complexity: O(1)
 ! Adaptive: Yes
 ! Stable: Yes
 ! In-place: Yes
 * Disadvantages:
 *   Too many comparisons: not practical for large datasets.
 *   Time complexity: not good compared to quick sort or merge sort [O(nlogn)].
 * Applications:
 *   Small datasets.
 *   When the list is almost sorted - time complexity O(n).
 */

void bubbleSort(std::vector<int> &v) {
  bool isSorted = false;
  for (int i = 0, n = v.size(); i < n; i++) {
    isSorted = true;
    for (int j = 0; j < n - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        std::swap(v[j], v[j + 1]);
        isSorted = false;
      }
    }
    if (isSorted) {
      return;
    }
  }
}
