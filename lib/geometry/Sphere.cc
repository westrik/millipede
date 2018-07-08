#include "Sphere.h"

namespace Millipede {

bool Sphere::hit(const Ray& ray, double t_min, double t_max, hit_record& record) const {
    Vector oc = ray.origin() - centre;
    double a = dot(ray.direction(), ray.direction());
    double b = dot(oc, ray.direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - a * c;

    if (discriminant > 0) {
        double t = (-b - sqrt(b * b - a * c)) / a;
        if (t < t_max && t > t_min) {
            record.t = t;
            record.p = ray.point(t);
            record.normal = (record.p - centre) / radius;
            return true;
        }
        t = (-b + sqrt(b * b - a * c)) / a;
        if (t < t_max && t > t_min) {
            record.t = t;
            record.p = ray.point(t);
            record.normal = (record.p - centre) / radius;
            return true;
        }
    } 
    return false;
}

}