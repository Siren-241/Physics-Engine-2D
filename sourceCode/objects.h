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
            float width, height;

        public:

            //sdf 
            float signedDistFunc(Vec2 p);
            
            //draw Funcs
            void draw(SDL_Renderer* renderer);

            //constructors
            Rect(int _x, int _y, float _w, float _h);

            //getters and setters
            inline int getW(){return this->width;}
            inline int getH(){return this->height;}
            inline void setW(int _w){this->width = _w;}
            inline void setH(int _h){this->height = _h;}

    };

    class Circle : public Rigidbody
    {
        //Parameters
        private:
            float r;
            void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius);

        public:
            //sdf
            float signedDistFunc(Vec2 p);

            //draw Funcs
            void draw(SDL_Renderer* renderer);

            //constructors
            Circle(int _x, int _y, float _r);

            // Getters and Setters
            inline void setRadius(float _r){ this->r = _r; }
            inline float getRadius(){ return r; }
    };



} // namespace objects


#endif// OBJECTS_H