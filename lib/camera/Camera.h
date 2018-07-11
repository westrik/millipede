#pragma once

#include "../geometry/Vector.h"
#include "../geometry/Ray.h"

namespace Millipede {

class Camera {
    Vector origin;
    Vector lower_left_corner;
    Vector horizontal;
    Vector vertical;
public:
    Camera(Vector from, Vector to, Vector vup, double vertical_fov, double aspect);
    Ray get_ray(double s, double t);
};

}