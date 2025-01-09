#pragma "once"

#include <iostream>

#include "color.h"

class PPM {
private:
    int width;
    int height;
public:
    PPM() : width(256), height(256) {};
    PPM(int w, int h) : width(w), height(w) {};

    void serialize() {
        std::cout << "P3\n" << width << " " << height << "\n255\n";

        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                std::clog << "\rScanlines remaining: " << (height - j) << ' ' << std::flush;

                auto pixel_color = color(double(i)/(width-1), double(j)/(height-1), 0.0);
                write_color(std::cout, pixel_color);
            }
        }

        std::clog << "\rDone.                              \n" << std::flush;
    };
};