#include "Millipede.h"

#include <iostream>

#include "geometry/Vector.h"
#include "geometry/Ray.h"
#include "colour/Colour.h"
#include "geometry/ShapeList.h"
#include "geometry/Sphere.h"
#include "camera/Camera.h"
#include "output/Output.h"

namespace Millipede {

Colour get_colour(const Ray& ray, ShapeList *world) {
    struct hit_record record;
    if (world->hit(ray, 0.0, std::numeric_limits<long>::max(), record)) {
        return 0.5 * Colour(
            record.normal.x() + 1, 
            record.normal.y() + 1, 
            record.normal.z() + 1
        );
    } else {
        Vector unit_direction = unit_vector(ray.direction());
        double t = 0.5 * unit_direction.y() + 1;
        return (1 - t) * Colour(1, 1, 1) + t * Colour(0.5, 0.7, 1);
    }
}

void render() {
    int width = 200;
    int height = 100;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    Camera camera;

    Shape *list[2];
    list[0] = new Sphere(Vector(0, 0, -1), 0.5);
    list[1] = new Sphere(Vector(0, -100.5, -1), 100);
    ShapeList *world = new ShapeList(list, 2);

    for (auto j = height - 1; j >= 0; j--) {
        for (auto i = 0; i < width; i++) {

            double u = double(i) / double(width);
            double v = double(j) / double(height);

            Ray r = camera.get_ray(u, v);
            Colour colour = get_colour(r, world);

            int ir = int(255.99 * colour.r());
            int ig = int(255.99 * colour.g());
            int ib = int(255.99 * colour.b());
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}

}
