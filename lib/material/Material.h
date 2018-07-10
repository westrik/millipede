#pragma once

#include "../geometry/Ray.h"
#include "../colour/Colour.h"
#include "../geometry/Shape.h"

namespace Millipede {

class HitRecord; // Forward declaration.
class Material {
public:
    virtual bool scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const = 0;
};

}