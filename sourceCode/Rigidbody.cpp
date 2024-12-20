#include "Rigidbody.h"

Vec2 Rigidbody::getPos()
{
    return this->pos;
}
void Rigidbody::setPos(Vec2 v)
{
    this->pos.setTo(v);
}
float Rigidbody::getX()
{
    return this->pos.getX();
}
float Rigidbody::getY()
{
    return this->pos.getY();
}


float Rigidbody::getAngle()
{
    return this->angle;
}
void Rigidbody::setAngle(float th)
{
    this->angle = th;
}

void Rigidbody::rotateByRad(float th)
{
    this->angle = this->angle + th;
}
void Rigidbody::rotateByDeg(float th)
{
    float R_th = th * PI / 180;
    this->angle = this->angle + R_th;
}


void Rigidbody::setCol(int _col)
{
    this->col = _col;
}
int Rigidbody::getCol()
{
    return this->col;
}

void Rigidbody::Move(Vec2 s)
{
    if(!this->isStatic)
    {
        this->pos.setTo(this->pos + s);
    }
    else
    {
        std::cout<<"attempting to move static obj";
    }
}

