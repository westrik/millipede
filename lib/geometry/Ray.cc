#include "Ray.h"

namespace Millipede {

Vector Ray::origin() const {
    return orig;
}
Vector Ray::direction() const {
    return dir;
}
Vector Ray::point(double distance) const {
    return orig + distance * dir;
}

}