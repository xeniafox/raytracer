#pragma once

#include <concepts>
#include <kfr/all.hpp>

namespace math {

/**
 * An 3-dimensional vector.
 */
using vec = kfr::univector<double, 3>;

/**
 * A point in an 3-dimensional space.
 */
using point = kfr::univector<double, 3>;

/**
 * Compute the dot product between two 3-dimensional vectors.
 *
 * @param u Left vector of dot product.
 * @param v Right vector of dot product.
 *
 * @return Dot product between both vectors.
 */
double vdot(const vec &u, const vec &v) noexcept;

/**
 * Compute the cross product between two 3-dimensional vectors.
 *
 * @param u Left vector of cross product.
 * @param v Right vector of cross product.
 *
 * @return Cross product between both vectors.
 */
vec vcross(const vec &u, const vec &v) noexcept;

/**
 * Generate a random 3-dimensional vector.
 *
 * @return Randomly-generated 3D vector.
 */
vec random_vector() noexcept;

double random_double() noexcept;
double random_double(const double min, const double max) noexcept;

/**
 * Generate a random 3-dimensional vector within a defined range.
 *
 * @param min Lowest value in the range the vector will be generated from.
 * @param max Greatest value in the rnage the vector will be generated from.
 *
 * @return Randomly-generated 3D vector.
 */
vec random_vector(const double min, const double max) noexcept;

vec random_in_unit_sphere() noexcept;
vec random_vunit() noexcept;

const double vsquared(const vec &v) noexcept;
const double vlen(const vec &v) noexcept;

vec vunit(const vec &v) noexcept;

double clamp(double x, double min, double max) noexcept;

double degrees_to_radians(double degrees) noexcept;
bool near_zero(const vec &v) noexcept;

} // namespace math
