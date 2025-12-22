#include "order.h"

#include <vector>
#include <algorithm>
#include <ostream>

#include "sorting.h"

int medianOfMedians(const std::vector<int> &v, int k) {
    // 1. Calculate M.
    // 2. Apply quick select with pivot = M.
    // 3. If M is the k'th element, return it.
    // 4. Otherwise, repeat for A[l:M-1] if idx > k or A[M+1:r] if idx < k.
    std::vector<int> v_cp(v.begin(), v.end());
    int findMedian(std::vector<int> &v, int l, int r);
    void partitionWithPivot(std::vector<int> &v, int &l, int &r, int p);
    int M, l, r, l_b, r_b;
    l = 0, r = v.size() - 1;
    while (1) {
        M = findMedian(v_cp, l, r);
        l_b = l, r_b = r;
        partitionWithPivot(v_cp, l_b, r_b, M);
        if (k >= l_b && k <= r_b) {
            return M;
        }
        if (k < l_b) {
            r = l_b;
        } else {
            l = r_b;
        }
    }
}

int findMedian(std::vector<int> &v, int l, int r) {
    int n = r - l + 1;
    if (n <= 5) {
        std::vector cp(v.begin() + l, v.begin() + r);
        bubbleSort(cp);
        return cp[n / 2];
    }
    std::vector<int> medians;
    int end;
    for (int i = l; i <= r; i += 5) {
        end = std::min(r + 1, i + 5);
        std::vector group(v.begin() + i, v.begin() + end);
        bubbleSort(group);
        medians.push_back(group[group.size() / 2]);
    }
    return findMedian(medians, 0, medians.size() - 1);
}

// Divide the array into three parts:
// [{< pivot} | {== pivot} | {> pivot}]
// Modified l and r will represent the boundaries of these parts.
void partitionWithPivot(std::vector<int> &v, int &l, int &r, int p) {
    int mid = l;
    while (mid <= r) {
        if (v[mid] < p) {
            // put in the first block.
            std::swap(v[l++], v[mid++]);
        } else if (v[mid] > p) {
            // put in the last block.
            std::swap(v[r--], v[mid]);
        } else {
            mid++;
        }
    }
}
