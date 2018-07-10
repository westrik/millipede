#pragma once

#include "Material.h"

namespace Millipede {

class Lambertian : public Material {
    Colour albedo;
public:
    Lambertian(const Colour& albedo) : albedo(albedo) {}
    ~Lambertian() {}
    virtual bool scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const;
};

}