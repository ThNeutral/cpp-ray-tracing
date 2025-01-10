#pragma once

#include "hittable.h"
#include "vec3.h"
#include "interval.h"
#include "material.h"

class sphere : public hittable {
    private: 
        point3 center;
        double radius;
        shared_ptr<material> mat;
    public:
        sphere(const point3& center, double radius, shared_ptr<material> mat) : center(center), radius(std::fmax(0, radius)), mat(mat) {}

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
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
            if (!ray_t.surrounds(root)) {
                root = (h + sqrtD) / a;
                if (!ray_t.surrounds(root)) {
                    return false;
                }
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat = mat;

            return true;
        };
};