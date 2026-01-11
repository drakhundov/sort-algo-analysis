#include <vector>

#include "sorting.h"

/*
 ! Non-comparison-based sorting algorithm.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 ! Adaptive: No
 ! Stable: No
 ! In-place: No
 * Applications:
 *   Known range of values.
 *   Input well-distributed.
 */

void bucketSort(std::vector<int>& v, int max, int nbuckets) {
  if (v.empty()) return;
  if (nbuckets <= 1) {
    throw std::invalid_argument("[bucketSort]: nbuckets <= 1");
  }

  std::vector<std::vector<int>> buckets(nbuckets);
  int bucket_idx;
  for (auto& el : v) {
    bucket_idx = el / max * nbuckets;
    buckets[bucket_idx].push_back(el);
  }
  for (auto& bv : buckets) {
    bucketSort(bv, max, v.size() / nbuckets * bv.size());
  }
  int idx = 0, n;
  for (auto& bv : buckets) {
    n = bv.size();
    v.erase(v.begin() + idx, v.begin() + idx + n);
    v.insert(v.begin() + idx, bv.begin(), bv.end());
    idx += n;
  }
}
