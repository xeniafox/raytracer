#include "hittable_list.hh"

#include <algorithm>

namespace render {

bool hittable_list::hit(const ray &r, const double t_min, const double t_max,
                        hit_record &rec) const {
  hit_record temp_rec;

  bool hit_anything = false;
  auto closest_so_far = t_max;

  std::for_each(std::begin(this->_objs), std::end(this->_objs),
                [&](const std::shared_ptr<hittable> &obj) {
                  if (obj->hit(r, t_min, closest_so_far, temp_rec)) {
                    hit_anything = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                  }
                });

  return hit_anything;
}

void hittable_list::add(std::shared_ptr<hittable> obj) noexcept {
  this->_objs.push_back(obj);
}

} // namespace render
