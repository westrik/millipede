#pragma once

#include <memory>

#include "../geometry/Vector.h"
#include "../geometry/Ray.h"
#include "../material/Material.h"

namespace Millipede {

class Material; // Forward declaration.
class HitRecord {
public:
    HitRecord() {}
    ~HitRecord() {}
    double t;
    Vector p;
    Vector normal;
    std::shared_ptr<Material> material;
};

class Shape {
public:
    virtual ~Shape() {}
    virtual bool hit(const Ray& r, double t_min, double t_max, 
        std::shared_ptr<HitRecord>& record) const = 0;
};

}