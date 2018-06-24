#include <iostream>
#include "lib/Output.h"

namespace Millipede {
void output_ppm() {
    int width = 400;
    int height = 200;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (auto j = height-1; j>=0; j--) {
        for (auto i = 0; i<width; i++) {
            int ir = int(255.99);
            int ig = int(255.99);
            int ib = int(255.99);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}
}