#include "objects.h"

//sdfs
float objects::Rect::signedDistFunc(Vec2 p)
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

float objects::Circle::signedDistFunc(Vec2 p)
{
    return ((p - this->getPos()).mag())-this->r;
}

//constructors
objects::Rect::Rect(int _x = 200, int _y=200, float _w = 50, float _h = 50)
{
    this->width = _w;
    this->height = _h;

    this->setPos(Vec2(_x, _y));
}

objects::Circle::Circle(int _x, int _y, float _r)
{
    this->setPos(Vec2(_x, _y));
    this->r = _r;
}

//Draw Functions
void objects::Rect::draw(SDL_Renderer* renderer)
{
    SDL_Rect t_rect;
    t_rect.x = this->getX();
    t_rect.y = this->getY();
    t_rect.w = this->getW();
    t_rect.h = this->getH();


    SDL_SetRenderDrawColor(renderer, 255,255,255, 255);

    SDL_RenderDrawRect(renderer, &t_rect);

}


void objects::Circle::draw(SDL_Renderer* renderer)
{
    DrawCircle(renderer, (int32_t)this->getX(), (int32_t)this->getY(), (int32_t)this->r);
}


//Misc


void objects::Circle::DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        // Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }

    }
}
