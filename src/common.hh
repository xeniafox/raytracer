#pragma once

#include <limits>
#include <numbers>

#include "math.hh"

namespace common {

inline constexpr const double infinity =
    std::numeric_limits<double>::infinity();
inline constexpr const double pi = std::numbers::pi_v<double>;

inline constexpr const double x(const math::vec &v) noexcept { return v[0]; }
inline constexpr const double y(const math::vec &v) noexcept { return v[1]; }
inline constexpr const double z(const math::vec &v) noexcept { return v[2]; }

/**
 * Forced unrolled loop.
 *
 * @param N How many times the loop should repeat.
 * @param f Lambda or function to compute in the loop.
 */
template <std::size_t N, class F, std::size_t START = 0>
inline void unroll_loop(const F &f) noexcept {
  if constexpr (N == 0) {
    return;
  } else {
    f(START);
    unroll_loop<N - 1, F, START + 1>(f);
  }
}

} // namespace common
