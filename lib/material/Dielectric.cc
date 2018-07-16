#include "Dielectric.h"

#include <iostream>

namespace Millipede {

double schlick(double cosine, double refraction_index) {
    double r0 = (1 - refraction_index) / (1 + refraction_index);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

bool Dielectric::scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const {
    Vector outward_normal;
    Vector reflected = reflect(ray_in.direction(), hit_record.normal);
    double ni_over_nt;
    attenuation = Colour(1, 1, 1);
    Vector refracted;
    double reflect_prob;
    double cosine;

    if (dot(ray_in.direction(), hit_record.normal) > 0) {
        outward_normal = -hit_record.normal;
        ni_over_nt = refraction_index;
        cosine = refraction_index * dot(ray_in.direction(), hit_record.normal) 
            / ray_in.direction().length();
    } else {
        outward_normal = hit_record.normal;
        ni_over_nt = 1 / refraction_index;
        cosine = -dot(ray_in.direction(), hit_record.normal) 
            / ray_in.direction().length();
    }

    if (refract(ray_in.direction(), outward_normal, ni_over_nt, refracted)) {
        reflect_prob = schlick(cosine, refraction_index);
    } else {
        reflect_prob = 1;
    }

    if (drand48() < reflect_prob) {
        scattered = Ray(hit_record.p, reflected);
    } else {
        scattered = Ray(hit_record.p, refracted);
    }

    return true;
}

}