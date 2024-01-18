#pragma once

#include <memory>

#include "material.hh"
#include "math.hh"
#include "ray.hh"

namespace gfx {

// Forward declaration
class material;

} // namespace gfx

namespace render {

struct hit_record {
  math::point p;
  math::vec normal;
  std::shared_ptr<gfx::material> mat_ptr;
  double t;
  bool front_face;

  void set_face_normal(const ray &r, const math::vec &outward_normal) noexcept;

  hit_record &operator=(const hit_record &other) noexcept;
};

} // namespace render
