#include "PPM.h"

PPM::PPM() : width(256), height(256) {}
PPM::PPM(int w, int h) : width(w), height(w) {}

void PPM::serialize() {
    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (int j = 0; j < width; j++) {
        for (int i = 0; i < width; i++) {
            double r = double(i) / (width-1);
            double g = double(j) / (height-1);
            double b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}