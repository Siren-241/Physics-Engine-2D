#include "utils.h"


Vec2 abs(Vec2 v)
{
    Vec2 temp = v;
    if(temp.getX()<0)
        temp.setTo(Vec2(temp.getX()*-1, temp.getY()* 1));

    if(temp.getY()<0)
        temp.setTo(Vec2(temp.getX()* 1, temp.getY()*-1));
        
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
