#include <numeric>
#include <vector>
#include <iostream>

#include "lib.hpp"

namespace lib {
  double mean(const std::vector<double> &v) {
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << sum << std::endl;

    std::cout << sum / v.size() << std::endl;
    return sum / v.size();
  }

}
