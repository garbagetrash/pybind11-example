#include <numeric>
#include <vector>
#include <iostream>

#include "lib.hpp"

double mean(std::vector<double> v) {
  double sum = 0.0;
  std::cout << sum << std::endl;
  std::accumulate(v.begin(), v.end(), sum);
  std::cout << sum << std::endl;

  std::cout << sum / v.size() << std::endl;
  return sum / v.size();
}
