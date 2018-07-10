#pragma once

#include "../geometry/Vector.h"
#include "../geometry/Ray.h"
#include "../material/Material.h"
#include "Shape.h"

namespace Millipede {

class Sphere: public Shape {
public:
    Sphere() {}
    ~Sphere() {}
    Sphere(Vector centre, double radius, std::shared_ptr<Material> material) : 
        centre(centre), radius(radius), sphere_material(material) {}

    virtual bool hit(const Ray& ray, double t_min, double t_max, 
        std::shared_ptr<HitRecord>& hit_record) const;
    Vector centre;
    double radius;
    std::shared_ptr<Material> sphere_material;
};

}