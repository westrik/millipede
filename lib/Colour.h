#pragma once

// Right now this duplicates a lot of the code in Vector, but I'm planning that Colour will eventually diverge (spectra, etc.)

namespace Millipede {
class Colour {
    double vec[3];

public:
    Colour() {}
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

    inline Colour operator+=(const Colour &addend);
    inline Colour operator-=(const Colour &subtrahend);
    inline Colour operator*=(const Colour &multiplier);
    inline Colour operator/=(const Colour &divisor);

    inline Colour operator*=(const double &multiplier);
    inline Colour operator/=(const double &divisor);
};
}
