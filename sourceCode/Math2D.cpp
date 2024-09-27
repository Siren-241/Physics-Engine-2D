#include "Math2D.h"

Vec2::Vec2()
{
    this->x = 0;
    this->y = 0;
}
Vec2::Vec2(float s)
{
    this->x = s;
    this->y = s;
}
Vec2::Vec2(float _x, float _y)
{
    this->x = _x;
    this->y = _y;
}
Vec2::~Vec2()
{
    /* delete this->x;
    delete this->y; */
}

Vec2 Vec2::operator+(Vec2 v)
{
    return Vec2( this->x + v.getX(), this->y + v.getY());
}
Vec2 Vec2::operator-(Vec2 v)
{
    return Vec2( this->x - v.getX(), this->y - v.getY());
}
Vec2 Vec2::operator*(float s)
{
    return Vec2((this->x) * s, (this->y) * s);
}
Vec2 Vec2::operator/(float s)
{
    return Vec2((this->x) / s, (this->y) / s);
}


float Vec2::mag()
{
    return sqrt( (this->x) * (this->x) + (this->y) * (this->y) ); 
}

void Vec2::normalise()
{
    float tempM = mag();
    if(tempM!=0)
    {
        this->x /= tempM;
        this->y /= tempM;
    }
}
Vec2 Vec2::getPos()
{
    return Vec2(this->x, this->y);
}
float Vec2::getX()
{
    return this->x;
}
float Vec2::getY()
{
    return this->y;
}
void Vec2::setTo(Vec2 temp)
{
    this->x = temp.getX();
    this->y = temp.getY();
}

