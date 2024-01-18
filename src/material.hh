#pragma once

#include "color.hh"
#include "hit_record.hh"
#include "math.hh"
#include "ray.hh"

namespace render {

// Forward declaration
struct hit_record;

} // namespace render

namespace gfx {

using color = math::vec;

class material {
public:
  virtual bool scatter(const render::ray &r_in, const render::hit_record &rec,
                       color &attenuation, render::ray &scattered) const = 0;
};

} // namespace gfx
