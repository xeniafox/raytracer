#pragma once

#include "hit_record.hh"
#include "ray.hh"

namespace render {

// Forward declaration
struct hit_record;

class hittable {
public:
  virtual bool hit(const ray &r, const double t_min, const double t_max,
                   hit_record &rec) const;
};

} // namespace render
