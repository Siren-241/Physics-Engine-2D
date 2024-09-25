#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <iostream>
#include <graphics.h>

#include "Math2D.h"

class Rigidbody
{
    private:
        Vec2 pos;
        int col = rand()%16;
        float angle = 0;

    public:
    
        boolean isStatic = false;
        
        //col operations
        void setCol(int);
        int getCol();

        //Pos operations
        void Move(Vec2);
        void MoveTo(Vec2);
        Vec2 getPos();
        void setPos(Vec2);
        float getX();
        float getY();

        //angle operations
        float getAngle();
        void setAngle(float);
        void rotateByRad(float);
        void rotateByDeg(float);

        virtual float signedDistFunc(Vec2)=0;
        virtual void draw()=0;


};

//needs to be rewritten
void findNormal(Rigidbody*, Rigidbody*, Vec2*, float*);


#endif