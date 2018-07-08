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
    Camera();
    Ray get_ray(double u, double v);
};

}