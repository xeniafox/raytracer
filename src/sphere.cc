#include "sphere.hh"

#include "math.hh"

namespace render {

bool sphere::hit(const ray &r, const double t_min, const double t_max,
                 hit_record &rec) const {
  const math::vec oc = r.origin() - this->_center;

  const auto a = math::vsquared(r.direction());
  const auto half_b = math::vdot(oc, r.direction());
  const auto c = math::vsquared(oc) - this->_radius * this->_radius;

  const auto delta = half_b * half_b - a * c;
  if (delta < 0) {
    return false;
  }

  const auto sqrtd = sqrt(delta);

  auto root = (-half_b - sqrtd) / a;
  if (root < t_min || t_max < root) {
    root = (-half_b + sqrtd) / a;
    if (root < t_min || t_max < root) {
      return false;
    }
  }

  rec.t = root;
  rec.p = r.at(rec.t);

  const math::vec outward_normal = (rec.p - this->_center) / this->_radius;

  rec.set_face_normal(r, outward_normal);
  rec.mat_ptr = this->_mat_ptr;

  return true;
}

} // namespace render
