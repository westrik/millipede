#include "Camera.h"

namespace Millipede {

Camera::Camera() {
    lower_left_corner = Vector(-2, -1, -1);
    horizontal = Vector(4, 0, 0);
    vertical = Vector(0, 2, 0);
    origin = Vector(0, 0, 0);
}

Ray Camera::get_ray(double u, double v) {
    return Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
}

}