#include "Camera.h"

#include <iostream>

namespace Millipede {

Vector random_in_unit_disk() {
    Vector p;
    do {
        p = 2 * Vector(drand48(), drand48(), 0) - Vector(1, 1, 0);
    } while (dot(p, p) >= 1);
    return p;
}

/**
 * vertical_fov: top to bottom in degrees
 */
Camera::Camera(Vector from, Vector to, Vector vup, double vertical_fov, double aspect, 
        double aperture, double focus_distance) {
    lens_radius = aperture / 2;
    double theta = vertical_fov * M_PI / 180;
    double half_height = tan(theta / 2);
    double half_width = aspect * half_height;

    origin = from;
    w = unit_vector(from - to);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    lower_left_corner = origin - half_width * focus_distance * u 
        - half_height * focus_distance * v - focus_distance * w;
    horizontal = Vector(2*half_width, 0, 0);
    horizontal = 2 * half_width * focus_distance * u;
    vertical = 2 * half_height * focus_distance * v;
}

Ray Camera::get_ray(double s, double t) {
    Vector rd = lens_radius * random_in_unit_disk();
    Vector offset = u * rd.x() + v * rd.y();
    return Ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset);
}

}