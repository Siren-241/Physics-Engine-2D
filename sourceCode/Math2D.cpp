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

Vec2 Vec2::operator+(Vec2 v)
{
    Vec2 temp(this->x+v.x,this->y+v.y);
    return temp;
}
Vec2 Vec2::operator-(Vec2 v)
{
    Vec2 temp(this->x-v.x,this->y-v.y);
    return temp;
}
Vec2 Vec2::operator*(float s)
{
    Vec2 temp(x*s,y*s);
    return temp;
}
Vec2 Vec2::operator/(float s)
{
    Vec2 temp(x/s,y/s);
    return temp;
}


float Vec2::mag()
{
    return sqrt(this->x*this->x+this->y*this->y); 
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




Vec2 abs(Vec2 v)
{
    Vec2 temp = v;
    if(temp.getX()<0)temp.setTo(Vec2(temp.getX()*-1, temp.getY()* 1));
    if(temp.getY()<0)temp.setTo(Vec2(temp.getX()* 1, temp.getY()*-1));
    return temp;
}

Vec2 rotmat2x2(Vec2 p, float th)
{
    return Vec2(p.getX()*cos(th) - p.getY()*sin(th),
                p.getX()*sin(th) + p.getY()*cos(th));
}


float max(float a, float b)
{
    if(a>b)return a;
    else if(b>a)return b;
    else return a;
}
float min(float a, float b)
{
    if(a<b)return a;
    else if(b<a)return b;
    else return a;
}