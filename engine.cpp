#include <graphics.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <random>

#include "sourceCode/Math2D.h"
#include "sourceCode/Rigidbody.h"
#include "sourceCode/objects.h"
#include "sourceCode/utils.h"
#include "Scene.h"

const COLORREF BACK_COL = 0x0f0f10;
static void gameLoop();

Vec2 readWASDInputs();
void displayCorrection();
void drawObjects(Rigidbody*[], int);
void displayFPS(char*, std::chrono::duration<double>);

char fps[50];


int main()
{
    //window declaration
    int gd=DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    
    setbkcolor(BACK_COL);

    //just for clean code
    gameLoop();

    closegraph();
    return 0;
}




static void gameLoop()
{
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::duration<double> deltaTime;

    Rigidbody *objects[2];
    int len = sizeof(objects)/sizeof(objects[0]);

    //unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    //std::minstd_rand0 generator(seed);


    Ball b(400, 200, 50);
    Rect r(200, 200, 75, 75);

    objects[0] = &b;
    objects[1] = &r;

    Vec2 mousePos;


    //The Loop:
    for(int frame = 0; frame>=0; frame++)
    {
        startTime = std::chrono::high_resolution_clock::now();
        mousePos.setTo( Vec2(mousex(), mousey()) );

        //clear screen
        clearviewport();

        //draw
        drawObjects(objects, len);

        int speed = 5;
        Vec2 dir = readWASDInputs();

        objects[0]->Move(dir*speed);

        if(GetKeyState(VK_LBUTTON) & 0x8000)
        {
            float min_dist = abs(objects[0]->signedDistFunc(mousePos));
            for(auto obj : objects)
            {
                float dist = abs(obj->signedDistFunc(mousePos));
                if(dist<min_dist)min_dist = dist;
            }
            circle(mousePos.getX(), mousePos.getY(), min_dist);
            circle(mousePos.getX(), mousePos.getY(), 2);
        }

        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                Vec2 normal = Vec2(1);
                float dist = 1;

                findNormal(objects[i], objects[j], &normal, &dist);

                if(dist > 0)
                {
                    break;
                }

                if(!objects[i]->isStatic && !objects[j]->isStatic)
                {
                    objects[j]->Move(normal*abs(dist) * 0.5);
                    objects[i]->Move(normal*abs(dist) * -0.5);
                }
                else if(objects[i]->isStatic && !objects[j]->isStatic)
                {
                    objects[j]->Move(normal*abs(dist) *  1);
                }
                else if(!objects[i]->isStatic && objects[j]->isStatic)
                {
                    objects[i]->Move(normal*abs(dist) * -1);
                }
                
            }
            
        }
            
        

        //Print out Fps on the screen
        displayFPS(fps, deltaTime);

        //display correction
        displayCorrection();


        deltaTime = std::chrono::high_resolution_clock::now() - startTime;



        //loop break
        if(GetAsyncKeyState(0x1b))
        {
            break;
        }

        
    }
}


void displayFPS(char *fps, std::chrono::duration<double> dt)
{
    sprintf(fps, "%d", (int)(1/(double)dt.count()));
    char info[10] =  "FPS: ";
    strcat(info, fps);
    outtextxy(10, 10, (char *)info);

}

void displayCorrection()
{
    swapbuffers();
    delay(5);
}

Vec2 readWASDInputs()
{
    Vec2 _dir;
    if(GetAsyncKeyState(K_W))
    {
        _dir = _dir + Vec2(0,-1);
    }
    if(GetAsyncKeyState(K_S))
    {
        _dir = _dir + Vec2(0,1);
    }
    if(GetAsyncKeyState(K_D))
    {
        _dir = _dir + Vec2(1,0);
    }
    if(GetAsyncKeyState(K_A))
    {
        _dir = _dir + Vec2(-1,0);
    }

    _dir.normalise();
    return _dir;
}

void drawObjects(Rigidbody *_objs[], int _len)
{
    setlinestyle(0,0,2);
    for (int i = 0; i < _len; i++)
    {
        _objs[i]->draw();
        char _tempI[5];
        sprintf(_tempI, "%d", i);
        outtextxy(_objs[i]->getX(),_objs[i]->getY(), (char *)_tempI);
    }
}