#include <algorithm>
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

  BitsGen::BitsGen() :
    m_gen(std::default_random_engine(0)),
    m_bit_dist(std::uniform_int_distribution<uint8_t>(0, 1)),
    m_byte_dist(std::uniform_int_distribution<uint8_t>(0, 255)) {}

  void BitsGen::set_seed(uint32_t seed) {
    m_gen.seed(seed);
  }

  uint8_t BitsGen::yield_bit() {
    return m_bit_dist(m_gen);
  }

  uint8_t BitsGen::yield_byte() {
    return m_byte_dist(m_gen);
  }

  std::vector<uint8_t> BitsGen::yield_n_bits(size_t n) {
    std::vector<uint8_t> output(n, 0);
    for (uint8_t &bit : output) {
      bit = yield_bit();
    }
    return output;
  }

  std::vector<uint8_t> BitsGen::yield_n_bytes(size_t n) {
    std::vector<uint8_t> output(n, 0);
    for (uint8_t &byte : output) {
      byte = yield_byte();
    }
    return output;
  }

  std::vector<std::complex<double>> bpsk_mod(const std::vector<uint8_t> &bits) {
    std::vector<std::complex<double>> output(bits.size(), std::complex<double>(0.0, 0.0));
    for (size_t i = 0; i < bits.size(); i++) {
      output[i] = std::complex<double>(2.0 * bits[i] - 1.0, 0.0);
    }

    return output;
  }
}
