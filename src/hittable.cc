#include "hittable.hh"

#include "hit_record.hh"
#include "ray.hh"

namespace render {

bool hittable::hit(const ray &r, const double t_min, const double t_max,
                   hit_record &rec) const = delete;

}
