#pragma once

#include "math.hh"
#include "ray.hh"

namespace render {

class camera {
private:
  math::point _origin;
  math::point _lower_left_corner;
  math::vec _horizontal;
  math::vec _vertical;

public:
  camera(const math::point &look_from, const math::point &look_at,
         const math::vec vup, const double vfov,
         const double aspect_ratio) noexcept;

  ray get_ray(const double s, const double t) const;
};

} // namespace render
