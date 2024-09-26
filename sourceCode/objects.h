#ifndef OBJECTS_H
#define OBJECTS_H

#include "Rigidbody.h"
#include "Math2D.h"
#include "utils.h"

class Rect : public Rigidbody
{
    //params
    private:
    int p_arr[10];

    public:
    float width, height;

    //sdf 
    float signedDistFunc(Vec2 p);
    
    //draw Funcs
    //void draw();
    void draw();
    void draw(int _col);

    //constructors
    Rect();
    Rect(float _w, float _h);
    Rect(int _x, int _y, float _w, float _h);

};

class Ball : public Rigidbody
{
    public:
    //Parameters
    float r;

    //sdf
    float signedDistFunc(Vec2 p);

    //draw Funcs
    void draw();
    void draw(int _col);

    //constructors
    Ball();
    Ball(int _x, int _y, float _r);
    Ball(int _x, int _y, float _r, int _col);
};



#endif// OBJECTS_H