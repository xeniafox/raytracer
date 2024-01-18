#pragma once

#include <memory>
#include <vector>

#include "hit_record.hh"
#include "hittable.hh"
#include "ray.hh"

namespace render {

/**
 * A list of hittable objects.
 */
class hittable_list : public hittable {
private:
  std::vector<std::shared_ptr<hittable>> _objs{};

public:
  /**
   * Create an unitialized hittable_list.
   *
   * @return Empty hittable_list.
   */
  hittable_list() {}

  /**
   * Create a hittable_list.
   *
   * @param obj First hittable object of the list.
   *
   * @return A hittable_list with one object added.
   */
  hittable_list(std::shared_ptr<hittable> obj) noexcept;

  /**
   * Clear all the hittable list.
   */
  void clear() noexcept;

  /**
   * Add an object to the hittable list.
   *
   * @param obj Hittable object to be added to the list.
   */
  void add(std::shared_ptr<hittable> obj) noexcept;

  virtual bool hit(const ray &r, const double t_min, const double t_max,
                   hit_record &rec) const override;
};

} // namespace render
