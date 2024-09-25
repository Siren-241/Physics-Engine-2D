#ifndef MATH2D_H
#define MATH2D_H

#include <cmath>

#define PI 3.141592653589793

class Vec2
{   
    private:
        float x, y;
    
    public:
        Vec2();
        Vec2(float);
        Vec2(float, float);

        Vec2 operator+(Vec2);
        Vec2 operator-(Vec2);
        Vec2 operator*(float);
        Vec2 operator/(float);


        float mag();
        float getX();
        float getY();
        Vec2 getPos();
        void normalise();
        void setTo(Vec2);

};

Vec2 abs(Vec2);
Vec2 rotmat2x2(Vec2, float);
float max(float, float);
float min(float, float);


#endif