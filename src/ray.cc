#include "ray.hh"

#include "math.hh"

namespace render {

math::point ray::origin() const { return this->_orig; }

void ray::origin(const math::point &val) noexcept {
  this->_orig = math::point(val);
}

math::vec ray::direction() const { return this->_dir; }

void ray::direction(const math::vec &val) noexcept {
  this->_dir = math::vec(val);
}

math::point ray::at(const double t) const {
  return this->_orig + t * this->_dir;
}

} // namespace render
