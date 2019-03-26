#pragma once

class Vec3 {
    public:
        float x;
        float y;
        float z;
        
        Vec3();
        Vec3(float, float, float);

        Vec3 operator+(const Vec3) const; 
        Vec3 operator-(const Vec3) const;
        Vec3 operator*(const float) const;
        Vec3 operator/(const float) const;
        Vec3 operator-() const;
};

Vec3 operator*(const float, const Vec3);
float dot(const Vec3, const Vec3);
Vec3 cross(const Vec3, const Vec3);