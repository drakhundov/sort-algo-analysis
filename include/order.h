#pragma once

#include <vector>

// Find k'th element of v.
int medianOfMedians(const std::vector<int> &v, int k);

// pivot == -1 (by default) => select pivot randomly
int quickSelect(const std::vector<int> &v, int left, int right, int k);
