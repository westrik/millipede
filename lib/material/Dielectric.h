#pragma once

#include "Material.h"

namespace Millipede {

class Dielectric : public Material {
    double refraction_index;
public:
    Dielectric(double refraction_index) : refraction_index(refraction_index) {}
    ~Dielectric() {}
    virtual bool scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const;
};

}