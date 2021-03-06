#pragma once

#include "Material.h"

namespace Millipede {

class Metal : public Material {
    Colour albedo;
    double fuzziness;
public:
    Metal(const Colour& albedo, double fuzziness) : albedo(albedo), fuzziness(fuzziness) {}
    ~Metal() {}
    virtual bool scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const;
};

}
