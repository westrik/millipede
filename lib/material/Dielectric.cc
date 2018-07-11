#include "Dielectric.h"

namespace Millipede {

bool Dielectric::scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const {
    Vector outward_normal;
    Vector reflected = reflect(ray_in.direction(), hit_record.normal);
    double ni_over_nt;
    attenuation = Colour(1, 1, 1);
    Vector refracted;

    if (dot(ray_in.direction(), hit_record.normal) > 0) {
        outward_normal = -hit_record.normal;
        ni_over_nt = refraction_index;
    } else {
        outward_normal = hit_record.normal;
        ni_over_nt = 1 / refraction_index;
    }

    if (refract(ray_in.direction(), outward_normal, ni_over_nt, refracted)) {
        scattered = Ray(hit_record.p, refracted);
    } else {
        scattered = Ray(hit_record.p, reflected);
        return false;
    }
    return true;
}

}