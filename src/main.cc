#include <iostream>
#include <memory>

#include "camera.hh"
#include "color.hh"
#include "dielectric.hh"
#include "hittable_list.hh"
#include "lambertian.hh"
#include "math.hh"
#include "metal.hh"
#include "sphere.hh"

int main() noexcept {
  const auto aspect_ratio = 16.0 / 9.0;

  const int image_width = 1280;
  const int image_height = static_cast<int>(image_width / aspect_ratio);

  const int samples_per_pixel = 100;
  const int max_depth = 50;

  render::hittable_list world;

  auto material_ground =
      std::make_shared<gfx::lambertian>(gfx::color(0.8, 0.8, 0.0));
  world.add(std::make_shared<render::sphere>(math::point(0.0, -100.5, -1.0),
                                             100.0, material_ground));

  auto material_center =
      std::make_shared<gfx::lambertian>(gfx::color(0.1, 0.2, 0.5));
  world.add(std::make_shared<render::sphere>(math::point(0.0, 0.0, -1.0), 0.5,
                                             material_center));

  auto material_left = std::make_shared<gfx::dielectric>(1.5);
  world.add(std::make_shared<render::sphere>(math::point(-1.0, 0.0, -1.0), 0.5,
                                             material_left));

  auto material_right =
      std::make_shared<gfx::metal>(gfx::color(0.8, 0.6, 0.2), 0.0);
  world.add(std::make_shared<render::sphere>(math::point(1.0, 0.0, -1.0), 0.5,
                                             material_right));

  render::camera cam(math::point(-2, 2, 1), math::point(0, 0, -1),
                     math::vec(0, 1, 0), 90, aspect_ratio);

  const auto viewport_height = 1.0;
  const auto viewport_width = aspect_ratio * viewport_height;
  const auto focal_length = 1.0;

  const auto orig = math::point(0, 0, 0);
  const auto horizontal = math::vec(viewport_width, 0, 0);
  const auto vertical = math::vec(0, viewport_height, 0);
  const auto lower_left_corner =
      orig - horizontal / 2 - vertical / 2 - math::vec(0, 0, focal_length);

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  int i, j;
  for (j = image_height - 1; j >= 0; --j) {
    std::cerr << "\nScalines remaining: " << j << ' ' << std::flush;

    for (i = 0; i < image_width; ++i) {
      gfx::color pixel(0, 0, 0);
      for (int s = 0; s < samples_per_pixel; ++s) {
        const auto u = (i + math::random_double()) / (image_width - 1);
        const auto v = (j + math::random_double()) / (image_height - 1);

        render::ray r = cam.get_ray(u, v);
        pixel += gfx::ray_color(r, world, max_depth);
      }

      gfx::write_color(std::cout, pixel, samples_per_pixel);
    }
  }

  std::cerr << "\nDone.\n";

  return 0;
}
