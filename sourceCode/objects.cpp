#include "objects.h"

//sdfs
float Rect::signedDistFunc(Vec2 p)
{
    //adjust p to objects domain
    p = p - this->getPos();
    //cancel out the rotation of the object by counter-rotating the point
    p = rotmat2x2(p, getAngle());
    //adjusting point so as to account for the symmetries
    p = abs(p);

    Vec2 temp = Vec2(max(p.getX()-width/2, 0), max(p.getY()-height/2, 0));
    float d_o = temp.mag();
        //sqrt( max(p.getX()-width/2, 0)*max(p.getX()-width/2, 0) + max(p.getY()-height/2, 0)*max(p.getY()-height/2, 0));
    float d_i = min(max(p.getX()-width/2, p.getY()-height/2),0.0);
    return d_o + d_i;

}
float Ball::signedDistFunc(Vec2 p)
{
    return ((p - this->getPos()).mag())-this->r;
}

//constructors
Rect::Rect()
{
    this->width = 50;
    this->height = 50;

    this->setPos(Vec2(getmaxx()/2, getmaxy()/2));
}
Rect::Rect(float _w, float _h)
{
    this->width = _w;
    this->height = _h;

    this->setPos(Vec2(getmaxx()/2, getmaxy()/2));
}
Rect::Rect(int _x, int _y, float _w, float _h)
{
    this->width = _w;
    this->height = _h;

    this->setPos(Vec2(_x, _y));
}

Ball::Ball()
{
    this->setPos(Vec2(getmaxx()/2, getmaxy()/2));
    this->r = 10;
}
Ball::Ball(int _x, int _y, float _r)
{
    this->setPos(Vec2(_x, _y));
    this->r = _r;
}
Ball::Ball(int _x, int _y, float _r, int _col)
{
    this->setPos(Vec2(_x, _y));
    this->r = _r;
    setCol(_col);
}


/*void Rect::draw()
{
    //Point 1
    p_arr[0] = (int)getPos().getX() + (-width*cos(getAngle()) - height*sin(getAngle()))/2;
    p_arr[1] = (int)getPos().getY() + ( width*sin(getAngle()) - height*cos(getAngle()))/2;

    //Point 2
    p_arr[2] = (int)getPos().getX() + ( width*cos(getAngle()) - height*sin(getAngle()))/2;
    p_arr[3] = (int)getPos().getY() + (-width*sin(getAngle()) - height*cos(getAngle()))/2;


    //Point 3
    p_arr[4] = (int)getPos().getX() + ( width*cos(getAngle()) + height*sin(getAngle()))/2;
    p_arr[5] = (int)getPos().getY() + (-width*sin(getAngle()) + height*cos(getAngle()))/2;

    //Point 4
    p_arr[6] = (int)getPos().getX() + (-width*cos(getAngle()) + height*sin(getAngle()))/2;
    p_arr[7] = (int)getPos().getY() + ( width*sin(getAngle()) + height*cos(getAngle()))/2;

    //Point 1
    p_arr[8] = p_arr[0];
    p_arr[9] = p_arr[1];


    
    //perimeter

    setfillstyle(1,col);
    fillpoly(5, p_arr);
}
*/
void Rect::draw()
{
    for (int i = this->getX() - width; i < this->getX() + width; i++)
    {
        for (int j = this->getY() - height; j < this->getY() + height; j++)
        {
            Vec2 p = Vec2(i,j);
            float d = (this->signedDistFunc(p));
            if (d < 1)
            {
                putpixel(p.getX() ,p.getY(), WHITE);
            }
            
        }
        
    }
    
}
void Rect::draw(int _col) 
{
    //Point 1
    p_arr[0] = (int)getPos().getX() + (-width*cos(getAngle()) - height*sin(getAngle()))/2;
    p_arr[1] = (int)getPos().getY() + ( width*sin(getAngle()) - height*cos(getAngle()))/2;

    //Point 2
    p_arr[2] = (int)getPos().getX() + ( width*cos(getAngle()) - height*sin(getAngle()))/2;
    p_arr[3] = (int)getPos().getY() + (-width*sin(getAngle()) - height*cos(getAngle()))/2;


    //Point 3
    p_arr[4] = (int)getPos().getX() + ( width*cos(getAngle()) + height*sin(getAngle()))/2;
    p_arr[5] = (int)getPos().getY() + (-width*sin(getAngle()) + height*cos(getAngle()))/2;

    //Point 4
    p_arr[6] = (int)getPos().getX() + (-width*cos(getAngle()) + height*sin(getAngle()))/2;
    p_arr[7] = (int)getPos().getY() + ( width*sin(getAngle()) + height*cos(getAngle()))/2;

    //Point 1
    p_arr[8] = p_arr[0];
    p_arr[9] = p_arr[1];


    
    //perimeter

    setfillstyle(1,_col);
    fillpoly(5, p_arr);
}

void Ball::draw()
{
    setfillstyle(1,getCol());
    fillellipse(this->getPos().getX(),this->getPos().getY(),this->r,this->r);
}
void Ball::draw(int _col)
{
    setCol(_col);

    setfillstyle(1,getCol());
    fillellipse(this->getPos().getX(),this->getPos().getY(),this->r,this->r);
}

