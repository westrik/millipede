#pragma once

#include "../geometry/Vector.h"
#include "../geometry/Ray.h"

namespace Millipede {

struct hit_record {
    double t;
    Vector p;
    Vector normal;
};

class Shape {
public:
    virtual ~Shape() = 0;
    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& hit_record) const = 0;
};

}