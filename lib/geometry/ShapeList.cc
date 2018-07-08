#include "ShapeList.h"

namespace Millipede {

bool ShapeList::hit(const Ray& r, double t_min, double t_max, hit_record& hit_record) const {
    struct hit_record record;
    bool hit = false;
    double closest = t_max;

    for (int i = 0; i < size; i++) {
        if (list[i]->hit(r, t_min, closest, record)) {
            hit = true;
            closest = record.t;
            hit_record = record;
        }
    }

    return hit;
}

}