#pragma once

#include <cmath>

namespace Millipede {

class Vector {
    double vec[3];

public:
    Vector() {}
    Vector(double x, double y, double z) {
        vec[0] = x;
        vec[1] = y;
        vec[2] = z;
    }

    inline double x() const { 
        return vec[0];
    }
    inline double y() const { 
        return vec[1];
    }
    inline double z() const { 
        return vec[2];
    }

    inline const Vector& operator+() const {
        return *this;
    }
    inline const Vector operator-() const {
        return Vector(-vec[0], -vec[1], -vec[2]);
    }
    inline Vector& operator+=(const Vector &addend) {
        vec[0] += addend.x();
        vec[1] += addend.y();
        vec[2] += addend.z();
        return *this;
    }
    inline Vector& operator-=(const Vector &subtrahend) {
        vec[0] -= subtrahend.x();
        vec[1] -= subtrahend.y();
        vec[2] -= subtrahend.z();
        return *this;
    }
    inline Vector& operator*=(const Vector &multiplier) {
        vec[0] *= multiplier.x();
        vec[1] *= multiplier.y();
        vec[2] *= multiplier.z();
        return *this;
    }
    inline Vector& operator/=(const Vector &divisor) {
        vec[0] /= divisor.x();
        vec[1] /= divisor.y();
        vec[2] /= divisor.z();
        return *this;
    }
    inline Vector& operator*=(const double multiplier) {
        vec[0] *= multiplier;
        vec[1] *= multiplier;
        vec[2] *= multiplier;
        return *this;
    }
    inline Vector& operator/=(const double divisor) {
        vec[0] /= divisor;
        vec[1] /= divisor;
        vec[2] /= divisor;
        return *this;
    }
    inline Vector operator+(const Vector &addend) const {
        return Vector((*this).x() + addend.x(),
            (*this).y() + addend.y(),
            (*this).z() + addend.z()
        );
    }
    inline Vector operator-(const Vector &subtrahend) const {
        return Vector((*this).x() - subtrahend.x(),
            (*this).y() - subtrahend.y(),
            (*this).z() - subtrahend.z()
        );
    }
    inline Vector operator*(const Vector &multiplier) const {
        return Vector((*this).x() * multiplier.x(),
            (*this).y() * multiplier.y(),
            (*this).z() * multiplier.z()
        );
    }
    inline Vector operator/(const Vector &divisor) const {
        return Vector((*this).x() / divisor.x(),
            (*this).y() / divisor.y(),
            (*this).z() / divisor.z()
        );
    }
    inline Vector operator*(const double multiplier) const {
        return Vector((*this).x() * multiplier,
            (*this).y() * multiplier,
            (*this).z() * multiplier
        );
    }
    inline Vector operator/(const double divisor) const {
        return Vector((*this).x() / divisor,
            (*this).y() / divisor,
            (*this).z() / divisor
        );
    }

    inline double squared_length() const {
        return vec[0] * vec[0]
            +  vec[1] * vec[1]
            +  vec[2] * vec[2];
    }
    inline double length() const {
        return sqrt(squared_length());
    }
    inline void to_unit_vector() {
        (*this) /= length();
    }
};

inline Vector unit_vector(Vector v) {
    return v / v.length();
}
inline Vector operator*(const double multiplier, const Vector& multiplicand) {
    return Vector(multiplicand.x() * multiplier,
        multiplicand.y() * multiplier,
        multiplicand.z() * multiplier
    );
}
inline double dot(const Vector &a, const Vector &b) {
    return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}
inline Vector cross(const Vector &a, const Vector &b) {
    return Vector((a.y() * b.z() - a.z() * b.y()),
        -(a.x() * b.z() - a.z() * b.x()),
        (a.x() * b.y() - a.y() * b.x()));
}

}