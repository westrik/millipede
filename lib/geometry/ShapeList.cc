#include "ShapeList.h"

namespace Millipede {

bool ShapeList::hit(const Ray& r, double t_min, double t_max, hit_record& hit_record) const {
    struct hit_record record;
    bool hit = false;
    double closest = t_max;

    for (auto const& shape : shape_list) {
        if (shape->hit(r, t_min, closest, record)) {
            hit = true;
            closest = record.t;
            hit_record = record;
        }
    }

    return hit;
}

}