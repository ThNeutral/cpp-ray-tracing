#pragma "once"

#include "vec3.h"

class ray {
private: 
    point3 origin;
    vec3 direction;
public:
    ray() {}

    ray(const point3& orig, const vec3& dir) : origin(orig), direction(dir) {}

    const point3& origin() const {return origin;}
    const point3& direction() const {return direction;}

    point3 at(double t) {
        return origin + t * direction;
    }
};