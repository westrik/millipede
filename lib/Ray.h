#pragma once

#include "lib/Vector.h"

namespace Millipede {

class Ray {
    Vector o;
    Vector d;

public:
    Ray();
    Ray(const Vector& origin, const Vector& direction);
    Vector origin() const;
    Vector direction() const;
    Vector point(double distance) const;
};

}