#pragma once

#include <complex>
#include <cstdint>
#include <random>
#include <vector>

namespace lib {
  double mean(const std::vector<double> &v);

  template <typename InputIterator = std::vector<double>::iterator, typename T = double>
  T iter_sum(InputIterator start, InputIterator stop)
  {
    return std::accumulate(start, stop, 0.0);
  }

  class BitsGen {
    public:
      BitsGen();
      void set_seed(uint32_t seed);
      uint8_t yield_bit();
      uint8_t yield_byte();
      std::vector<uint8_t> yield_n_bits(size_t n);
      std::vector<uint8_t> yield_n_bytes(size_t n);

    private:
      std::default_random_engine m_gen;
      std::uniform_int_distribution<uint8_t> m_bit_dist;
      std::uniform_int_distribution<uint8_t> m_byte_dist;
  };

  std::vector<std::complex<double>> bpsk_mod(const std::vector<uint8_t> &bits);
}
