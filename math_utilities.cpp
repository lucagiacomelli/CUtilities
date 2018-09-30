#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

// To find a median of unsorted array we can use quick sort
// with the pivot selection via the median of medians
double median(vector<int> scores){
  size_t size = scores.size();
  if (size == 0)
    return 0;
  else {
    std::sort(scores.begin(), scores.end());
    if (size % 2 == 0){
      return (scores[size / 2 - 1] + scores[size / 2]) / 2;
    }
    else {
      return scores[size / 2];
    }
  }
}
