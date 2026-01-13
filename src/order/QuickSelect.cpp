#include <random>
#include <vector>

#include "order.h"

int quickSelect(const std::vector<int>& v, int left, int right, int k) {
  // Find the k'th value of the sorted 'v'.
  if (left >= right) {
    return -1;
  }
  static std::vector v_cp(v.begin(), v.end());
  int pivot_i = left + rand() % (right - left + 1);
  int last = left;
  std::swap(v_cp[left], v_cp[pivot_i]);
  for (int i = left + 1; i <= right; i++) {
    if (v_cp[i] < v_cp[left]) {
      std::swap(v_cp[++last], v_cp[i]);
    }
  }
  std::swap(v_cp[left], v_cp[last]);
  if (last == k) return v_cp[k];
  if (k > last) {
    return quickSelect(v, last + 1, right, k);
  } else {
    return quickSelect(v, left, last - 1, k);
  }
}
