#include "Material.h"

namespace Millipede {

Vector Material::reflect(const Vector& v, const Vector& n) {
    return v - 2 * dot(v, n) * n;
}

bool Material::refract(const Vector& v, const Vector& n, double ni_over_nt, Vector& refracted) {
    Vector uv = unit_vector(v);
    double dt = dot(uv, n);
    double discriminant = 1 - ni_over_nt * ni_over_nt * (1 - dt * dt);
    if (discriminant > 0) {
        refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
        return true;
    }
    return false;
}

}