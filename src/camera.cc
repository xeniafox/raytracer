#include "camera.hh"

#include <cmath>

namespace render {

camera::camera(const math::point &look_from, const math::point &look_at,
               const math::vec vup, const double vfov,
               const double aspect_ratio) noexcept {
  const auto theta = math::degrees_to_radians(vfov);
  const auto h = tan(theta / 2);
  const auto viewport_height = 2.0 * h;
  const auto viewport_width = aspect_ratio * viewport_height;

  const auto w = math::vunit(look_from - look_at);
  const auto u = math::vunit(math::vcross(vup, w));
  const auto v = math::vcross(w, u);

  this->_origin = math::point(look_from);
  this->_horizontal = math::vec(viewport_width * u);
  this->_vertical = math::vec(viewport_height * v);
  this->_lower_left_corner = math::point(this->_origin - this->_horizontal / 2 -
                                         this->_vertical / 2 - w);
}

ray camera::get_ray(const double s, const double t) const {
  return ray(this->_origin, this->_lower_left_corner + s * this->_horizontal +
                                t * this->_vertical - this->_origin);
}

} // namespace render
