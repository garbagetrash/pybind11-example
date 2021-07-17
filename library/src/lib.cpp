#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "lib.hpp"

namespace lib {
  double mean(const std::vector<double> &v) {
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << sum << std::endl;

    std::cout << sum / v.size() << std::endl;
    return sum / v.size();
  }

  BitGen::BitGen() :
    m_gen(std::default_random_engine),
    m_dist(std::uniform_int_distribution<char>(0, 1) {}

  char BitGen::yield() {
    return m_dist(m_gen);
  }
}
