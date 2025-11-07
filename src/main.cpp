#include <iostream>
#include <vector>
#include <random>
#include <unistd.h>
#include <fcntl.h>

#include "sorting.h"

#define NSORTS 7

enum Sorts {
  SELECTION = 0,
  INSERTION = 1,
  MERGE = 2,
  QUICK = 3,
  HEAP = 4,
  COUNTING = 5,
  RADIX = 6
};

std::vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

void create_g_sets(std::vector<int> sizes);

int **g_sets;
std::vector<int> exec_tm;

// Run each sorting algorithm for various inputs
// and measure their execution time.
int main() {
  create_g_sets(sizes);
  return 0;
}

void create_g_sets(std::vector<int> sizes) {
  // Randomly generate datasets of various sizes.
  // ! Uses global variable 'g_sets'
  // ! Uses global macro NSORTS
  int nsizes = sizeof(sizes) / sizeof(sizes[0]);
  quickSort(sizes, 0, nsizes - 1);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distr(0, sizes[nsizes - 1]);
  g_sets = new int *[nsizes];
  for (int i = 0; i < nsizes; i++) {
    g_sets[i] = new int[sizes[i]];
    for (int j = 0; j < sizes[i]; j++) {
      g_sets[i][j] = distr(gen);
    }
  }
}
