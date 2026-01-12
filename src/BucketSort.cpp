#include <climits>
#include <functional>
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

void bucketSort(std::vector<int>& v, int max,
                const std::function<int(int)>& calc_nbuckets) {
  if (v.empty()) return;
  int nbuckets = static_cast<int>(calc_nbuckets(v.size()));
  if (nbuckets < 1) {
    throw std::invalid_argument("[bucketSort]: nbuckets < 1");
  } else if (v.size() == 1 || nbuckets == 1) {
    return;
  }

  if (nbuckets > static_cast<int>(v.size()))
    nbuckets = static_cast<int>(v.size() / 2);
  if (nbuckets < 2) nbuckets = 2;

  std::vector<std::vector<int>> buckets(nbuckets);
  std::vector<int> bucket_max(nbuckets, INT_MIN);
  std::vector<int> bucket_min(nbuckets, INT_MAX);
  int bucket_idx;
  for (auto& el : v) {
    if (el == max) {
      bucket_idx = nbuckets - 1;
    } else {
      long long num = 1LL * el * nbuckets;
      bucket_idx = static_cast<int>(num / max);
    }
    buckets[bucket_idx].push_back(el);
    bucket_max[bucket_idx] = std::max(bucket_max[bucket_idx], el);
    bucket_min[bucket_idx] = std::min(bucket_min[bucket_idx], el);
  }
  size_t i = 0;
  for (auto& bv : buckets) {
    if (bucket_max[i] != bucket_min[i]) {
      if (bv.size() == v.size()) {
        countingSort(bv, bucket_max[i]);
      } else {
        bucketSort(bv, std::max(1, bucket_max[i]), calc_nbuckets);
      }
    }
    i++;
  }

  // Concatenate buckets into a sorted array.
  v.clear();
  for (auto& bv : buckets) {
    v.insert(v.end(), bv.begin(), bv.end());
  }
}
