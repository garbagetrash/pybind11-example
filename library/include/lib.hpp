#pragma once

#include <random>
#include <vector>

namespace lib {
  double mean(const std::vector<double> &v);

  template <typename InputIterator = std::vector<double>::iterator, typename T = double>
  T iter_sum(InputIterator start, InputIterator stop)
  {
    return std::accumulate(start, stop, 0.0);
  }

  class BitGen {
    public:
      BitGen();
      char yield();

    private:
      std::default_random_engine m_gen;
      std::uniform_int_distribution m_dist;
  };
}
