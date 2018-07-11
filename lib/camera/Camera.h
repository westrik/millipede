#pragma once

#include "../geometry/Vector.h"
#include "../geometry/Ray.h"

namespace Millipede {

class Camera {
    Vector origin;
    Vector lower_left_corner;
    Vector horizontal;
    Vector vertical;
    Vector u, v, w;
    double lens_radius;
public:
    Camera(Vector from, Vector to, Vector vup, double vertical_fov, double aspect, double aperture, 
        double focus_distance);
    Ray get_ray(double s, double t);
};

}