#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Math2D.h"

class Rigidbody
{
    private:
        Vec2 pos;
        int col = 15;
        float angle = 0;

    public:
    
        bool isStatic = false;
        
        //col operations
        void setCol(int);
        int getCol();

        //Pos operations
        void Move(Vec2);
        Vec2 getPos();
        void setPos(Vec2);
        float getX();
        float getY();

        //angle operations
        float getAngle();
        void setAngle(float);
        // dont use yet
        void rotateByRad(float);
        // dont use yet
        void rotateByDeg(float);

        virtual float signedDistFunc(Vec2)=0;
        virtual void draw(SDL_Renderer* renderer)=0;


};


#endif// RIGIDBODY_H