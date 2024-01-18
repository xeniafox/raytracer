#pragma once

#include "math.hh"

namespace render {

/**
 * A tracing ray.
 */
class ray {
private:
  math::point _orig;
  math::vec _dir;

public:
  /**
   * Create an unitialized ray.
   *
   * @return An empty tracing ray.
   */
  ray() {}

  /**
   * Create a new tracing ray with defined origin and direction.
   *
   * @param origin Origin where the ray comes from in an arbitrary-dimensional
   * space.
   * @param direction Direction where the ray goes towards.
   *
   * @return A tracing ray.
   */
  ray(const math::point &origin, const math::vec &direction) noexcept
      : _orig(origin), _dir(direction) {}

  /**
   * Get the origin component of a ray.
   *
   * @return Ray's origin.
   */
  math::point origin() const;

  /**
   * Set the origin component of a ray to a new value.
   *
   * @param val New value for ray's origin.
   */
  void origin(const math::point &val) noexcept;

  /**
   * Get the direction component of a ray.
   *
   * @return Ray's direction.
   */
  math::vec direction() const;

  /**
   * Set the direction component of a ray to a new value.
   *
   * @param val New value for ray's direction.
   */
  void direction(const math::vec &val) noexcept;

  /**
   * Get the coordinates of a point at $t$ distance from ray's origin on ray's
   * direction line.
   *
   * @param t Distance from ray's origin.
   *
   * @return A point at $t$ distance from ray's origin on the same direction
   * line as the ray.
   */
  math::point at(const double t) const;
};

} // namespace render
