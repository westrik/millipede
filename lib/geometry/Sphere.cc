#include "Sphere.h"

namespace Millipede {

bool Sphere::hit(const Ray& ray, double t_min, double t_max, 
        std::shared_ptr<HitRecord>& hit_record) const {
    Vector oc = ray.origin() - centre;
    double a = dot(ray.direction(), ray.direction());
    double b = dot(oc, ray.direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - a * c;

    if (discriminant > 0) {
        double t = (-b - sqrt(b * b - a * c)) / a;
        if (t < t_max && t > t_min) {
            hit_record->t = t;
            hit_record->p = ray.point(t);
            hit_record->normal = (hit_record->p - centre) / radius;
            hit_record->material = sphere_material;
            return true;
        }
        t = (-b + sqrt(b * b - a * c)) / a;
        if (t < t_max && t > t_min) {
            hit_record->t = t;
            hit_record->p = ray.point(t);
            hit_record->normal = (hit_record->p - centre) / radius;
            hit_record->material = sphere_material;
            return true;
        }
    } 
    return false;
}

}