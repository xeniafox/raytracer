#include "hit_record.hh"

#include "math.hh"

namespace render {

void hit_record::set_face_normal(const ray &r,
                                 const math::vec &outward_normal) noexcept {
  this->front_face = math::vdot(r.direction(), outward_normal) < 0;
  this->normal = front_face ? outward_normal
                            : static_cast<const math::vec>(-outward_normal);
}

hit_record &hit_record::operator=(const hit_record &other) noexcept {
  this->p = math::point(other.p);
  this->normal = math::vec(other.normal);
  this->mat_ptr = other.mat_ptr;
  this->t = other.t;
  this->front_face = other.front_face;

  return *this;
}

} // namespace render
