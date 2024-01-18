#include "math.hh"
#include "common.hh"

#include <array>
#include <cmath>
#include <concepts>
#include <cstdlib>

namespace math {

double vdot(const vec &u, const vec &v) noexcept {
  return common::x(u) * common::x(v) + common::y(u) * common::y(v) +
         common::z(u) * common::z(v);
}

vec vcross(const vec &u, const vec &v) noexcept {
  std::array<double, 3> w{};
  common::unroll_loop<3>([&](const unsigned long &i) {
    w[i] = u[(i + 1) % 3] * v[(i + 2) % 3] - u[(i + 2) % 3] * v[(i + 1) % 3];
  });

  // I think it's better to manually compute the sum here than using
  // std::accumulate because std::accumulate comes with some pre-computation
  // steps that can affect performance. This is a very tiny sum so it's probably
  // best to unroll it manually anyway.
  return vec(w[0], w[1], w[2]);
}

vec random_vector() noexcept {
  return vec(random_double(), random_double(), random_double());
}

vec random_vector(const double min, const double max) noexcept {
  vec v{};
  common::unroll_loop<3>(
      [&](const unsigned short &i) { v[i] = random_double(min, max); });

  return v;
}

double random_double() noexcept { return rand() / (RAND_MAX + 1.0); }

double random_double(const double min, const double max) noexcept {
  return min + (max - min) * random_double();
}

vec random_in_unit_sphere() noexcept {
  while (true) {
    const auto p = random_vector(-1, 1);
    if (vsquared(p) >= 1) {
      continue;
    }

    return p;
  }
}

vec random_vunit() noexcept { return vunit(random_in_unit_sphere()); }

const double vsquared(const vec &v) noexcept {
  return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

const double vlen(const vec &v) noexcept { return sqrt(vsquared(v)); }

bool near_zero(const vec &v) noexcept {
  constexpr auto s = 1e-8;
  return (fabs(v[0]) < s) && (fabs(v[1]) < s) && (fabs(v[2]) < s);
}

vec vunit(const vec &v) noexcept { return v / vlen(v); }

double clamp(double x, double min, double max) noexcept {
  if (x < min) {
    return min;
  }
  if (x > max) {
    return max;
  }

  return x;
}

double degrees_to_radians(const double degrees) noexcept {
  return degrees * common::pi / 180.0;
}

} // namespace math
