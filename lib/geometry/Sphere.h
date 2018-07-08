#pragma once

#include "../geometry/Vector.h"
#include "../geometry/Ray.h"
#include "Shape.h"

namespace Millipede {

class Sphere: public Shape {
public:
    Sphere() {}
    ~Sphere() {}
    Sphere(Vector centre, double radius) : centre(centre), radius(radius) {};
    virtual bool hit(const Ray& ray, double t_min, double t_max, hit_record& record) const;
    Vector centre;
    double radius;
};

}