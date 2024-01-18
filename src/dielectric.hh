#pragma once

#include "color.hh"
#include "hit_record.hh"
#include "material.hh"
#include "ray.hh"

namespace gfx {

class dielectric : public material {
private:
  double _ir;

public:
  dielectric(double index_of_refraction) : _ir(index_of_refraction) {}

  virtual bool scatter(const render::ray &r_in, const render::hit_record &rec,
                       color &attenuation,
                       render::ray &scattered) const override;
};

} // namespace gfx
