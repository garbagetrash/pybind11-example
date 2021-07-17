#pragma once

#include <vector>

namespace lib {
  double mean(const std::vector<double> &v);

  double iter_sum(typename std::vector<double>::iterator start,
                  typename std::vector<double>::iterator stop)
  {
    return std::accumulate(start, stop, 0.0);
  }
}
