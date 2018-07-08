#pragma once

#include "Vector.h"

namespace Millipede {

class Ray {
    Vector orig;
    Vector dir;

public:
    Ray() {};
    Ray(const Vector& origin, const Vector& direction) : orig(origin), dir(direction) {};
    Vector origin() const;
    Vector direction() const;
    Vector point(double distance) const;
};

}