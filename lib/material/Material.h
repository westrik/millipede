#pragma once

#include "../geometry/Ray.h"
#include "../colour/Colour.h"
#include "../geometry/Shape.h"

namespace Millipede {

class HitRecord; // Forward declaration.
class Material {
public:
    virtual ~Material() = 0;
    virtual bool scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const = 0;
    static Vector reflect(const Vector& v, const Vector& n);
    static bool refract(const Vector& v, const Vector& n, double ni_over_nt, Vector& refracted);
};

}
