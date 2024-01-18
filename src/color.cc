#include "color.hh"

#include "common.hh"
#include "hit_record.hh"
#include "math.hh"

namespace gfx {

color ray_color(const render::ray &r, render::hittable &world,
                const int depth) noexcept {
  render::hit_record rec;

  if (0 >= depth) {
    return color(0, 0, 0);
  }

  if (world.hit(r, 0.001, common::infinity, rec)) {
    render::ray scattered;
    color attenuation;

    if (rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
      return attenuation * ray_color(scattered, world, depth - 1);
    }

    return color(0, 0, 0);
  }

  math::vec unit_dir = math::vunit(r.direction());
  const auto t = 0.5 * (common::y(unit_dir) + 1.0);

  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

void write_color(std::ostream &out, const color &pixel,
                 const int samples_per_pixel) noexcept {
  const auto scale = 1.0 / samples_per_pixel;

  const auto r = sqrt(scale * common::x(pixel));
  const auto g = sqrt(scale * common::y(pixel));
  const auto b = sqrt(scale * common::z(pixel));

  auto t = [&](const auto val) {
    return static_cast<int>(256 * math::clamp(val, 0.0, 0.999));
  };

  out << t(r) << ' ' << t(g) << ' ' << t(b) << '\n';
}

} // namespace gfx
