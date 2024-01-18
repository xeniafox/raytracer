#include "metal.hh"

#include "math.hh"
#include "render.hh"

namespace gfx {

bool metal::scatter(const render::ray &r_in, const render::hit_record &rec,
                    color &attenuation, render::ray &scattered) const {
  math::vec reflected =
      render::reflect(math::vunit(r_in.direction()), rec.normal);

  scattered = render::ray(rec.p, reflected = this->_fuzz *
                                             math::random_in_unit_sphere());
  attenuation = math::vec(this->_albedo);

  return (math::vdot(scattered.direction(), rec.normal) > 0);
}

} // namespace gfx
