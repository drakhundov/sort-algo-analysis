#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "analysis.h"
#include "exec_tm.h"
#include "sorting.h"

std::vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

void create_g_sets(const std::vector<int>& sizes);
const std::string& get_sort_str(Sorts sort_no);

int** g_sets;
std::vector<int> exec_tm;

// Run each sorting algorithm for various inputs
// and measure their execution time.
int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: sort-algo-analysis <*.csv>" << std::endl;
  }
  char* res_file_path = argv[1];
  std::ofstream ofs(res_file_path);
  if (!ofs) {
    std::cerr
      << "Failed to open output file: "
      << res_file_path
      << std::endl;
    return 1;
  }
  ofs << "Algorithm,DatasetSize,ExecutionTime\n";
  create_g_sets(sizes);
  std::cout << "Sets were created"
            << std::endl;
  int sz, i;
  Sorts sort_no;
  for (int s = 0; s < NSORTS; s++) {
    sort_no = static_cast<Sorts>(s);
    for (i = 0; i < sizes.size(); i++) {
      sz = sizes[i];
      std::cout << "Starting "
                << get_sort_str(sort_no) << " on set size "
                << sz << std::endl;
      // Copy the corresponding dataset.
      std::vector<int> dataset{g_sets[i], g_sets[i] + sz};
      start_measuring_time();
      switch (sort_no) {
        case COUNTING:
          countingSort(dataset, sz);
          break;
        case QUICK:
          quickSort(dataset, 0, dataset.size() - 1);
          break;
        case SELECTION:
          selectionSort(dataset);
          break;
        case INSERTION:
          insertionSort(dataset);
          break;
        case BUBBLE:
          bubbleSort(dataset);
          break;
        case MERGE:
          mergeSort(dataset, 0, dataset.size() - 1);
          break;
        case RADIX:
          radixSort(dataset, sz);
          break;
      }
      stop_measuring_time();
      ofs << get_sort_str(sort_no) << ','
          << sz << ','
          << get_exec_time_ms()
          << std::endl;
      std::cout << "Finished "
                << get_sort_str(sort_no) << " on set size "
                << sz << std::endl;
    }
  }
  for (int i = 0; i < sizes.size(); i++) {
    delete[] g_sets[i];
  }
  delete[] g_sets;
  return 0;
}

void create_g_sets(const std::vector<int>& sizes) {
  // Randomly generate datasets of various sizes.
  // ! Uses global variable 'g_sets'
  // ! Uses global macro NSORTS
  int nsizes = sizes.size();
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distr(0, sizes[nsizes - 1]);
  using param_t = decltype(distr)::param_type;
  g_sets = new int*[nsizes];
  for (int i = 0; i < nsizes; i++) {
    g_sets[i] = new int[sizes[i]];
    for (int j = 0; j < sizes[i]; j++) {
      g_sets[i][j] = distr(gen, param_t(0, sizes[i]));
    }
  }
}

const std::string& get_sort_str(Sorts sort_no) {
  for (const auto &m : sort_str_map) {
    if (m.first == sort_no) {
      return m.second;
    }
  }
  throw std::invalid_argument("get_sort_str: unknown Sorts value");
}
