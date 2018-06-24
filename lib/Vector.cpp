#include "lib/Vector.h"

#include <cmath>
#include <iostream>

namespace Millipede {

inline Vector operator+(const Vector &augend, const Vector &addend) {
    return Vector(augend.x() + addend.x(),
        augend.y() + addend.y(),
        augend.z() + addend.z()
    );
}

inline Vector operator-(const Vector &minuend, const Vector &subtrahend) {
    return Vector(minuend.x() - subtrahend.x(),
        minuend.y() - subtrahend.y(),
        minuend.z() - subtrahend.z()
    );
}

inline Vector operator*(const Vector &multiplicand, const Vector &multiplier) {
    return Vector(multiplicand.x() * multiplier.x(),
        multiplicand.y() * multiplier.y(),
        multiplicand.z() * multiplier.z()
    );
}

inline Vector operator/(const Vector &dividend, const Vector &divisor) {
    return Vector(dividend.x() / divisor.x(),
        dividend.y() / divisor.y(),
        dividend.z() / divisor.z()
    );
}

inline Vector operator*(const Vector &multiplicand, const double multiplier) {
    return Vector(multiplicand.x() * multiplier,
        multiplicand.y() * multiplier,
        multiplicand.z() * multiplier
    );
}

inline Vector operator/(const Vector &dividend, const double divisor) {
    return Vector(dividend.x() / divisor,
        dividend.y() / divisor,
        dividend.z() / divisor
    );
}

inline Vector& Vector::operator+=(const Vector &addend) {
    vec[0] += addend.x();
    vec[1] += addend.y();
    vec[2] += addend.z();
    return *this;
}

inline Vector& Vector::operator-=(const Vector &subtrahend) {
    vec[0] -= subtrahend.x();
    vec[1] -= subtrahend.y();
    vec[2] -= subtrahend.z();
    return *this;
}

inline Vector& Vector::operator*=(const Vector &multiplier) {
    vec[0] *= multiplier.x();
    vec[1] *= multiplier.y();
    vec[2] *= multiplier.z();
    return *this;
}

inline Vector& Vector::operator/=(const Vector &divisor) {
    vec[0] /= divisor.x();
    vec[1] /= divisor.y();
    vec[2] /= divisor.z();
    return *this;
}

inline Vector& Vector::operator*=(const double &multiplier) {
    vec[0] *= multiplier;
    vec[1] *= multiplier;
    vec[2] *= multiplier;
    return *this;
}

inline Vector& Vector::operator/=(const double &divisor) {
    vec[0] /= divisor;
    vec[1] /= divisor;
    vec[2] /= divisor;
    return *this;

}

inline double Vector::dot(const Vector &a, const Vector &b) {
    return (*this).squared_length();
}

inline Vector Vector::cross(const Vector &a, const Vector &b) {
    return Vector((a.y() * b.z() - a.z() * b.y()),
        -(a.x() * b.z() - a.z() * b.x()),
        (a.x() * b.y() - a.y() * b.x()));
}

inline Vector unit_vector(Vector v) {
    return v / v.length();
}

inline void Vector::unit_vector() {
    (*this) /= length();
} 

}