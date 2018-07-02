#include "lib/Millipede.h"

#include <iostream>

#include "lib/Vector.h"
#include "lib/Ray.h"
#include "lib/Colour.h"
#include "lib/Output.h"

namespace Millipede {

double hit_sphere(const Vector& centre, double radius, const Ray& ray) {
    Vector oc = ray.origin() - centre;
    double a = dot(ray.direction(), ray.direction());
    double b = 2.0 * dot(oc, ray.direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt(discriminant)) / (2 * a);
    }
}

Colour get_colour(const Ray& ray) {
    double t = hit_sphere(Vector(0, 0, -1), 0.5, ray); 
    if (t > 0) {
        Vector n = unit_vector(ray.point(t) - Vector(0, 0, -1));
        return 0.5 * Colour(n.x()+1, n.y()+1, n.z()+1);
    }
    Vector unit_direction = unit_vector(ray.direction());
    t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Colour(1, 1, 1) + t * Colour(0.5, 0.7, 1);
}

void render() {
    int width = 200;
    int height = 100;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    Vector lower_left_corner(-2, -1, -1);
    Vector horizontal(4, 0, 0);
    Vector vertical(0, 2, 0);
    Vector origin(0, 0, 0);

    for (auto j = height - 1; j >= 0; j--) {
        for (auto i = 0; i < width; i++) {

            double u = double(i) / double(width);
            double v = double(j) / double(height);

            Ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            Colour colour = get_colour(r);

            int ir = int(255.99*colour.r());
            int ig = int(255.99*colour.g());
            int ib = int(255.99*colour.b());
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}

}
