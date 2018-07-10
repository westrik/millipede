#include "ShapeList.h"

#include <memory>

namespace Millipede {

bool ShapeList::hit(const Ray& r, double t_min, double t_max, 
        std::shared_ptr<HitRecord>& hit_record) const {
    auto closest_hit = std::shared_ptr<HitRecord>(new HitRecord());
    bool was_hit = false;
    double closest = t_max;

    for (auto const& shape : shape_list) {
        if (shape->hit(r, t_min, closest, closest_hit)) {
            was_hit = true;
            closest = closest_hit->t;
            hit_record = closest_hit;
        }
    }

    return was_hit;
}

}