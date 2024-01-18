#pragma once

#include "hit_record.hh"
#include "hittable.hh"
#include "material.hh"
#include "math.hh"
#include "ray.hh"

#include <memory>

namespace render {

class sphere : public hittable {
private:
  math::point _center;
  double _radius;
  std::shared_ptr<gfx::material> _mat_ptr;

public:
  sphere() {}
  sphere(math::point cen, const double r, std::shared_ptr<gfx::material> m)
      : _center(cen), _radius(r), _mat_ptr(m) {}

  virtual bool hit(const ray &r, const double t_min, const double t_max,
                   hit_record &rec) const override;
};

} // namespace render
