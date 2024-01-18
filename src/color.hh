#pragma once

#include "hittable.hh"
#include "math.hh"
#include "ray.hh"

#include <iostream>

namespace render {

// Forward declaration
class hittable;

} // namespace render

namespace gfx {

/**
 * RGB color information.
 */
using color = math::vec;

/**
 * Compute the color of a tracing ray.
 *
 * @param r The tracing ray.
 * @param world The hittable world.
 * @param depth How deep is the point on the ray.
 *
 * @return Color of point on tracing ray.
 */
color ray_color(const render::ray &r, render::hittable &world,
                const int depth) noexcept;

void write_color(std::ostream &out, const color &pixel,
                 const int samples_per_pixel) noexcept;

} // namespace gfx
