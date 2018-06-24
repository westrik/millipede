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

    inline Vector& operator+=(const Vector &addend);
    inline Vector& operator-=(const Vector &subtrahend);
    inline Vector& operator*=(const Vector &multiplier);
    inline Vector& operator/=(const Vector &divisor);

    inline Vector& operator*=(const double &multiplier);
    inline Vector& operator/=(const double &divisor);

    inline double squared_length() const {
        return vec[0] * vec[0]
            +  vec[1] * vec[1]
            +  vec[2] * vec[2];
    }
    inline double length() const {
        return sqrt(squared_length());
    }
    inline void unit_vector();
    inline double dot(const Vector &a, const Vector &b);
    inline Vector cross(const Vector &a, const Vector &b);
};

}