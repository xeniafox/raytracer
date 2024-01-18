#include "dielectric.hh"

#include "math.hh"
#include "render.hh"

#include <cmath>

namespace gfx {

bool dielectric::scatter(const render::ray &r_in, const render::hit_record &rec,
                         color &attenuation, render::ray &scattered) const {
  attenuation = color(1.0, 1.0, 1.0);
  double refract_ratio = rec.front_face ? (1.0 / this->_ir) : this->_ir;

  math::vec unit_dir = math::vunit(r_in.direction());

  double cos_theta = fmin(math::vdot(-unit_dir, rec.normal), 1.0);
  double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

  auto reflectance = [&](const double cosine, const double ref_idx) {
    auto r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;

    return r0 + (1 - r0) * pow((1 - cosine), 5);
  };

  math::vec direction;
  if (refract_ratio * sin_theta > 1.0 ||
      reflectance(cos_theta, refract_ratio) > math::random_double()) {
    direction = render::reflect(unit_dir, rec.normal);
  } else {
    render::refract(unit_dir, rec.normal, refract_ratio);
  }

  scattered = render::ray(rec.p, direction);

  return true;
}

} // namespace gfx
