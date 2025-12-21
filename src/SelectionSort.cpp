#include <limits>

#include "sorting.h"

/*
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 ! Adaptive: No
 ! Stable: No
 * Applications:
 *   When memory access cost is high, because
 *   selection sort uses less swapping.
 */

void selectionSort(std::vector<int> &v) {
  int findMinIdxInVector(std::vector<int> &v, int startPos);
  for (int i = 0, n = v.size(); i < n; i++) {
    int minIdx = findMinIdxInVector(v, i);
    std::swap(v[i], v[minIdx]);
  }
}

int findMinIdxInVector(std::vector<int> &v, int startPos) {
  int idx = -1, val = std::numeric_limits<int>::max();
  for (int i = startPos, n = v.size(); i < n; i++) {
    if (v[i] < val) {
      idx = i;
      val = v[i];
    }
  }
  return idx;
}