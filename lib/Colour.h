#pragma once

// Right now this duplicates a lot of the code in Colour, but I'm planning that Colour will eventually diverge (spectra, etc.)

namespace Millipede {

class Colour {
    double vec[3];

public:
    Colour(double r, double g, double b) {
        vec[0] = r;
        vec[1] = g;
        vec[2] = b;
    }

    inline double r() const { 
        return vec[0];
    }
    inline double g() const { 
        return vec[1];
    }
    inline double b() const { 
        return vec[2];
    }

    inline Colour& operator+=(const Colour &addend) {
        vec[0] += addend.r();
        vec[1] += addend.g();
        vec[2] += addend.b();
        return *this;
    }
    inline Colour& operator-=(const Colour &subtrahend) {
        vec[0] -= subtrahend.r();
        vec[1] -= subtrahend.g();
        vec[2] -= subtrahend.b();
        return *this;
    }
    inline Colour& operator*=(const Colour &multiplier) {
        vec[0] *= multiplier.r();
        vec[1] *= multiplier.g();
        vec[2] *= multiplier.b();
        return *this;
    }
    inline Colour& operator/=(const Colour &divisor) {
        vec[0] /= divisor.r();
        vec[1] /= divisor.g();
        vec[2] /= divisor.b();
        return *this;
    }
    inline Colour& operator*=(const double multiplier) {
        vec[0] *= multiplier;
        vec[1] *= multiplier;
        vec[2] *= multiplier;
        return *this;
    }
    inline Colour& operator/=(const double divisor) {
        vec[0] /= divisor;
        vec[1] /= divisor;
        vec[2] /= divisor;
        return *this;
    }
    inline Colour operator+(const Colour &addend) const {
        return Colour((*this).r() + addend.r(),
            (*this).g() + addend.g(),
            (*this).b() + addend.b()
        );
    }
    inline Colour operator-(const Colour &subtrahend) const {
        return Colour((*this).r() - subtrahend.r(),
            (*this).g() - subtrahend.g(),
            (*this).b() - subtrahend.b()
        );
    }
    inline Colour operator*(const Colour &multiplier) const {
        return Colour((*this).r() * multiplier.r(),
            (*this).g() * multiplier.g(),
            (*this).b() * multiplier.b()
        );
    }
    inline Colour operator/(const Colour &divisor) const {
        return Colour((*this).r() / divisor.r(),
            (*this).b() / divisor.b(),
            (*this).g() / divisor.g()
        );
    }
    inline Colour operator*(const double multiplier) const {
        return Colour((*this).r() * multiplier,
            (*this).g() * multiplier,
            (*this).b() * multiplier
        );
    }
    inline Colour operator/(const double divisor) const {
        return Colour((*this).r() / divisor,
            (*this).g() / divisor,
            (*this).b() / divisor
        );
    }
};

inline Colour operator*(const double multiplier, const Colour& multiplicand) {
    return Colour(multiplicand.g() * multiplier,
        multiplicand.g() * multiplier,
        multiplicand.b() * multiplier
    );
}

}