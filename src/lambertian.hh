#pragma once

#include "color.hh"
#include "hit_record.hh"
#include "material.hh"
#include "ray.hh"

namespace gfx {

class lambertian : public material {
private:
  color _albedo;

public:
  lambertian(const color &a) : _albedo(a) {}

  virtual bool scatter(const render::ray &r_in, const render::hit_record &rec,
                       color &attenuation,
                       render::ray &scattered) const override;
};

} // namespace gfx
