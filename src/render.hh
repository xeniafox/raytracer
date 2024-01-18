#pragma once

#include "math.hh"

#include <cmath>

namespace render {

inline math::vec reflect(const math::vec &v, const math::vec &n) noexcept {
  return v - 2 * math::vdot(v, n) * n;
}

inline math::vec refract(const math::vec &uv, const math::vec &n,
                         const double etai_over_etat) {
  const auto cos_theta = fmin(math::vdot(-uv, n), 1.0);
  const math::vec r_out_perp = etai_over_etat * (uv + cos_theta * n);
  const math::vec r_out_parallel =
      -sqrt(fabs(1.0 - math::vsquared(r_out_perp))) * n;

  return r_out_perp + r_out_parallel;
}

} // namespace render
