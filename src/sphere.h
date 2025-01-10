#pragma once

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
    private: 
        point3 center;
        double radius;
    public:
        sphere(const point3& center, double radius) : center(center), radius(std::fmax(0, radius)) {}

        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
            vec3 oc = center - r.origin();
            double a = r.direction().length_squared();
            double h = dot(r.direction(), oc); // Optimization for finding b
            double c = oc.length_squared() - radius * radius;
            
            double D = h * h - a * c;
            if (D < 0) {
                return false;
            }

            auto sqrtD = std::sqrt(D);

            double root = (h - sqrtD) / a;
            if (root <= ray_tmin || ray_tmax <= root) {
                root = (h + sqrtD) / a;
                if (root <= ray_tmin || ray_tmax <= root) {
                    return false;
                }
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        };
};