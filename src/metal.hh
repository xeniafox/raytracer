#pragma once

#include "color.hh"
#include "hit_record.hh"
#include "material.hh"
#include "ray.hh"

namespace gfx {

class metal : public material {
private:
  color _albedo;
  double _fuzz;

public:
  metal(const color &a, const double f) : _albedo(a), _fuzz(f < 1 ? f : 1) {}

  virtual bool scatter(const render::ray &r_in, const render::hit_record &rec,
                       color &attenuation,
                       render::ray &scattered) const override;
};

} // namespace gfx
