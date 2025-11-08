#pragma once

#include <map>
#include <string>

enum Sorts {
  SELECTION = 0,
  INSERTION = 1,
  MERGE = 2,
  QUICK = 3,
  BUBBLE = 4,
  COUNTING = 5,
  RADIX = 6
};

inline std::map<Sorts, std::string> sort_str_map = {
  {SELECTION, "SELECTION"},
  {INSERTION, "INSERTION"},
  {MERGE, "MERGE"},
  {QUICK, "QUICK"},
  {BUBBLE, "BUBBLE"},
  {COUNTING, "COUNTING"},
  {RADIX, "RADIX"},
};

// Bubble
// Selection
// Quick
// Merge
// Insertion
// Counting
// Radix
#define NSORTS 7
