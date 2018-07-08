#include "Output.h"

#include <iostream>

namespace Millipede {

void output_ppm() {
    int width = 2000;
    int height = 1000;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (auto j = height - 1; j >= 0; j--) {
        for (auto i = 0; i < width; i++) {
            float r = float(i) / float(width);
            float g = float(j) / float(height);
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}

}