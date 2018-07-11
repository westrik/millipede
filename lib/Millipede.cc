#include "Millipede.h"

#include <iostream>
#include <vector>
#include <memory>
#include <limits>

#include "geometry/Vector.h"
#include "geometry/Ray.h"
#include "colour/Colour.h"
#include "geometry/ShapeList.h"
#include "geometry/Sphere.h"
#include "material/Lambertian.h"
#include "material/Metal.h"
#include "material/Dielectric.h"
#include "camera/Camera.h"
#include "output/Output.h"

namespace Millipede {

const int MAX_DEPTH = 60;
const int ITERATIONS = 100;

Vector random_in_unit_sphere() {
    Vector p;
    do {
        p = 2 * Vector(drand48(), drand48(), drand48()) - Vector(1, 1, 1);
    } while (p.squared_length() >= 1);
    return p;
}

Colour get_colour(const Ray& ray, const ShapeList &world, int depth) {
    auto hit_record = std::shared_ptr<HitRecord>();
    if (world.hit(ray, 0.001, std::numeric_limits<double>::max(), hit_record)) {
        Ray scattered;
        Colour attenuation;
        if (depth < MAX_DEPTH 
                && hit_record->material->scatter(ray, *hit_record, attenuation, scattered)) {
            return attenuation * get_colour(scattered, world, depth + 1);
        } else {
            return Colour(0, 0, 0);
        }
    } else {
        Vector unit_direction = unit_vector(ray.direction());
        double t = 0.5 * unit_direction.y() + 1;
        return (1 - t) * Colour(1, 1, 1) + t * Colour(0.5, 0.7, 1);
    }
}

std::shared_ptr<ShapeList> random_scene() {
    std::vector<std::shared_ptr<Shape> > shape_list;

    std::shared_ptr<Shape> globe (new Sphere(Vector(0, -1000, 0), 1000,
        std::shared_ptr<Lambertian>(new Lambertian(Colour(0.5, 0.5, 0.5)))));
    shape_list.push_back(globe);

    for (auto a = -11; a < 11; a++) {
        for (auto b = -11; b < 11; b++) {
            double choose_material = drand48();
            Vector centre(a + 0.9 * drand48(), 0.2, b + 0.9 * drand48());
            if ((centre - Vector(4, 0.2, 0)).length() > 0.9) {
                if (choose_material < 0.8) { 
                    // Diffuse
                    std::shared_ptr<Shape> diffuse_ball (new Sphere(centre, 0.2,
                        std::shared_ptr<Lambertian>(new Lambertian(Colour(drand48()*drand48(), 
                        drand48()*drand48(), drand48()*drand48())))));
                    shape_list.push_back(diffuse_ball);
                } else if (choose_material < 0.95) { 
                    // Metal
                    std::shared_ptr<Shape> metal_ball (new Sphere(centre, 0.2,
                        std::shared_ptr<Metal>(new Metal(
                            Colour(0.5*(1+drand48()), 0.5*(1+drand48()), 0.5*(1+drand48())), 
                            0.5*drand48()))));
                    shape_list.push_back(metal_ball);
                } else { 
                    // Glass
                    std::shared_ptr<Shape> glass_ball (new Sphere(centre, 0.2,
                        std::shared_ptr<Dielectric>(new Dielectric(1.5))));
                    shape_list.push_back(glass_ball);
                }
            }
        }
    }

    std::shared_ptr<Shape> big_glass_ball (new Sphere(Vector(0, 1, 0), 1,
        std::shared_ptr<Dielectric>(new Dielectric(1.5))));
    shape_list.push_back(big_glass_ball);

    std::shared_ptr<Shape> big_diffuse_ball (new Sphere(Vector(-4, 1, 0), 1,
        std::shared_ptr<Lambertian>(new Lambertian(Colour(0.4, 0.2, 0.1)))));
    shape_list.push_back(big_diffuse_ball);

    std::shared_ptr<Shape> big_metal_ball (new Sphere(Vector(4, 1, 0), 1,
        std::shared_ptr<Metal>(new Metal(Colour(0.7, 0.6, 0.5), 0))));
    shape_list.push_back(big_metal_ball);

    return std::make_shared<ShapeList> (shape_list);
}

void render() {
    int width = 2000;
    int height = 1500;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    Vector from (13, 2, 3);
    Vector to (0, 0, 0);
    double distance_to_focus = 10;//(from - to).length();
    double aperture = 0.1;

    Camera camera (from, to, Vector(0, 1, 0), 20, double(width) / double(height), aperture, 
        distance_to_focus);

    std::shared_ptr<ShapeList> world = random_scene();

    for (auto j = height - 1; j >= 0; j--) {
        for (auto i = 0; i < width; i++) {
            Colour colour = Colour(0, 0, 0);

            for (auto iter = 0; iter < ITERATIONS; iter++) {
                double u = double(i + drand48()) / double(width);
                double v = double(j + drand48()) / double(height);

                Ray r = camera.get_ray(u, v);
                colour += get_colour(r, *world, 0);
            }
            colour /= ITERATIONS;

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
