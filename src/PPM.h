#pragma "once"

#include <iostream>

class PPM {
private:
    int width;
    int height;
public:
    PPM();
    PPM(int w, int h);

    void serialize();
};