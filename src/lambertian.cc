#include "lambertian.hh"

#include "math.hh"

namespace gfx {

bool lambertian::scatter(const render::ray &r_in, const render::hit_record &rec,
                         color &attenuation, render::ray &scattered) const {
  math::vec scatter_direction = rec.normal + math::random_vunit();
  if (math::near_zero(scatter_direction)) {
    scatter_direction = math::vec(rec.normal);
  }

  scattered = render::ray(rec.p, scatter_direction);
  attenuation = math::vec(this->_albedo);

  return true;
}

} // namespace gfx
