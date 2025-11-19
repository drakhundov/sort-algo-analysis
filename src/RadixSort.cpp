#include "sorting.h"

#define digit(val, exp) ((val / exp) % 10)

/*
 ! Non-comparative sorting algorithm
 * Time Complexity: O(d*(n+k))
 * n - size of the dataset
 * d - maximum number of digits
 * k - range of the digits (10 for decimal)
 * Space Complexity:
 *   Best Case:
 *   Worst Case:
 ! Adaptive: No
 ! Stable: Yes
 * Applications:
 *   Large datasets.
 *   Stability requirement.
 */

void radixSort(std::vector<int> &v, int ndigits) {
  if (ndigits == -1) {
    int arrMax = *std::max_element(v.begin(), v.end());
    ndigits = 0;
    while (arrMax > 0) {
      arrMax /= 10;
      ndigits += 1;
    }
  }
  int maxExp = std::pow(10, ndigits - 1);
  for (long exp = 1; exp <= maxExp; exp *= 10) {
    _countingSortWithExp(v, exp);
  }
}

void _countingSortWithExp(std::vector<int> &v, int exp) {
  std::vector<int> sorted(v.size());
  std::vector<int> count(10, 0);
  for (auto &elem : v) {
    count[digit(elem, exp)]++;
  }
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    int _digit = digit(v[i], exp);
    sorted[count[_digit] - 1] = v[i];
    count[_digit]--;
  }
  v = std::move(sorted);
}
