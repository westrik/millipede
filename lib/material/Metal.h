#pragma once

#include "Material.h"

namespace Millipede {

class Metal : public Material {
    Colour albedo;
public:
    Metal(const Colour& albedo) : albedo(albedo) {}
    ~Metal() {}
    virtual bool scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const;
};

}
