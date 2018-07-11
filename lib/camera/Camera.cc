#include "Camera.h"

namespace Millipede {

/**
 * vertical_fov: top to bottom in degrees
 */
Camera::Camera(Vector from, Vector to, Vector vup, double vertical_fov, double aspect) {
    Vector u, v, w;
    double theta = vertical_fov * M_PI / 180;
    double half_height = tan(theta / 2);
    double half_width = aspect * half_height;

    origin = from;
    w = unit_vector(from - to);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    lower_left_corner = origin - half_width * u - half_height * v - w;
    horizontal = Vector(2*half_width, 0, 0);
    horizontal = 2 * half_width * u;
    vertical = 2 * half_height * v;
}

Ray Camera::get_ray(double s, double t) {
    return Ray(origin, lower_left_corner + s * horizontal + t * vertical - origin);
}

}