#pragma once

#include <vector>

namespace lib {
  double mean(const std::vector<double> &v);

  template <typename InputIterator = std::vector<double>::iterator, typename T = double>
  T iter_sum(InputIterator start, InputIterator stop)
  {
    return std::accumulate(start, stop, 0.0);
  }
}
