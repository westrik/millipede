#include "lib/Millipede.h"

#include <iostream>

#include "lib/Vector.h"
#include "lib/Ray.h"
#include "lib/Colour.h"
#include "lib/Output.h"

namespace Millipede {

Colour get_colour(const Ray& ray) {
    Vector unit_direction = unit_vector(ray.direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
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
