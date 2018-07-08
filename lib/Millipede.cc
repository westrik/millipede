#include "Millipede.h"

#include <iostream>
#include <vector>

#include "geometry/Vector.h"
#include "geometry/Ray.h"
#include "colour/Colour.h"
#include "geometry/ShapeList.h"
#include "geometry/Sphere.h"
#include "camera/Camera.h"
#include "output/Output.h"

namespace Millipede {

Vector random_in_unit_sphere() {
    Vector p;
    do {
        p = 2 * Vector(drand48(), drand48(), drand48()) - Vector(1, 1, 1);
    } while (p.squared_length() >= 1);
    return p;
}

Colour get_colour(const Ray& ray, ShapeList &world) {
    struct hit_record record;
    if (world.hit(ray, 0.001, std::numeric_limits<double>::max(), record)) {
        Vector target = record.p + record.normal + random_in_unit_sphere();
        return 0.5 * get_colour(Ray(record.p, target - record.p), world);
    } else {
        Vector unit_direction = unit_vector(ray.direction());
        double t = 0.5 * unit_direction.y() + 1;
        return (1 - t) * Colour(1, 1, 1) + t * Colour(0.5, 0.7, 1);
    }
}

void render() {
    int width = 200;
    int height = 100;
    int iterations = 100;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    Camera camera;

    std::vector<std::shared_ptr<Shape > > shape_list;
    std::shared_ptr<Shape > small (new Sphere(Vector(0, 0, -1), 0.5));
    shape_list.push_back(small);
    std::shared_ptr<Shape > globe (new Sphere(Vector(0, -100.5, -1), 100));
    shape_list.push_back(globe);
    ShapeList world (shape_list);

    for (auto j = height - 1; j >= 0; j--) {
        for (auto i = 0; i < width; i++) {
            Colour colour = Colour(0, 0, 0);

            for (auto iter = 0; iter < iterations; iter++) {
                double u = double(i + drand48()) / double(width);
                double v = double(j + drand48()) / double(height);

                Ray r = camera.get_ray(u, v);
                colour += get_colour(r, world);
            }
            colour /= iterations;

            // Gamma adjustment
            colour = Colour(sqrt(colour.r()), sqrt(colour.g()), sqrt(colour.b()));

            int ir = int(255.99 * colour.r());
            int ig = int(255.99 * colour.g());
            int ib = int(255.99 * colour.b());
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}

}
