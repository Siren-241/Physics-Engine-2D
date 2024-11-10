#ifndef OBJECTS_H
#define OBJECTS_H

#include "Rigidbody.h"
#include "Math2D.h"
#include "utils.h"

namespace objects
{
    class Rect : public Rigidbody
    {
        //params
        private:
            int p_arr[10];
            float width, height;

        public:

            //sdf 
            float signedDistFunc(Vec2 p);
            
            //draw Funcs
            void draw();
            void draw(int _col);

            //constructors
            //Rect();
            //Rect(float _w, float _h);
            Rect(int _x, int _y, float _w, float _h);

    };

    class Circle : public Rigidbody
    {
        //Parameters
        private:
            float r;

        public:
            //sdf
            float signedDistFunc(Vec2 p);

            //draw Funcs
            void draw();
            void draw(int _col);

            //constructors
            //Circle();
            Circle(int _x, int _y, float _r);
            Circle(int _x, int _y, float _r, int _col);
    };



} // namespace objects


#endif// OBJECTS_H