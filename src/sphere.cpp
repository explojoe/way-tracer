#include "sphere.hpp"
#include "object.hpp"

Sphere::Sphere(const Mat44 m) : objectToWorld(m), worldToObject(m.inverse()) {}

bool Sphere::intersect(const Vec3 orig, const Vec3 dir, float &t) const {
    float t0, t1; // solutions for t if intersection found.

    Vec3 orig2 = worldToObject.transformPoint(orig);
    Vec3 dir2 = worldToObject.transformVector(dir);

    Vec3 L = -orig2;
    float tca = dot(L, dir2);
    float d2 = dot(L, L) - tca * tca;
    if (d2 > 1) {
        return false;
    }
    float thc = sqrt(1 - d2);
    t0 = tca - thc;
    t1 = tca + thc;

    if (t0 > t1) {
        std::swap(t0, t1);
    }
    if (t0 < 0) {
        t0 = t1; // if t0 is negative use t1 instead
        if (t0 < 0) {
            return false; // both are negative, no intersection
        }
    }
    t = t0;
    return true;
}

void Sphere::getSurfaceInfo(const Vec3 pHit, Vec3 &nHit) const {
    Vec3 pHit2 = worldToObject.transformPoint(pHit);
    nHit = pHit2.normalized();
    nHit = objectToWorld.transformNormal(nHit);
}
