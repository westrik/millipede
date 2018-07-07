#include "Ray.h"

namespace Millipede {

Ray::Ray() {
}

Ray::Ray(const Vector& origin, const Vector& direction) {
    o = origin;
    d = direction;
}

Vector Ray::origin() const {
    return o;
}
Vector Ray::direction() const {
    return d;
}
Vector Ray::point(double distance) const {
    return o + distance * d;
}

}