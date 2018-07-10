#include "Lambertian.h"

#include "../Millipede.h"

namespace Millipede {

bool Lambertian::scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const {
    Vector target = hit_record.p + hit_record.normal + random_in_unit_sphere();
    scattered = Ray(hit_record.p, target - hit_record.p);
    attenuation = albedo;
    return true;
}

}