#include "Metal.h"

#include "../Millipede.h"

namespace Millipede {

bool Metal::scatter(const Ray& ray_in, const HitRecord& hit_record, Colour& attenuation, 
        Ray& scattered) const {
    Vector reflected = reflect(unit_vector(ray_in.direction()), hit_record.normal);
    scattered = Ray(hit_record.p, reflected + fuzziness * random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.direction(), hit_record.normal) > 0);
}

}