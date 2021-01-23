#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include "io.h"
#include "statistics.h"

template <typename T>
void print_statistics(const T& t) {
  std::cout << "mean: " << mean(t) << std::endl;
  std::cout << "median: " << median(t) << std::endl;
  std::cout << "2nd moment: " << moment(t, 2) << std::endl;
}

int main() {
  auto vec = uniform_distribution(0, 10000, 0.0, 1.0);
  print_statistics(vec);

  std::array<int, 6> int_array = {1, 2, 3, 4, 5, 6};
  print_statistics(int_array);

  std::list<float> float_list;
  std::copy(vec.begin(), vec.end(), std::back_inserter(float_list));
  std::cout << "robust_median: " << robust_median(float_list) << std::endl;

  const std::array<int, 6> int_array2 = {6, 2, 3, 4, 5, 1};
  std::cout << "robust_median2: " << robust_median(int_array2) << std::endl;
  /*for(size_t i = 6; i--;)
    std::cout << int_array2[i] << endl; // as we can see, intarray2 isnt sorted - so we're working on a copy already
  return 0;
  */
}
