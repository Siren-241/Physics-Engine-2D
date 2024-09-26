#include <graphics.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <random>

#include "sourceCode/Math2D.h"
#include "sourceCode/Rigidbody.h"
#include "sourceCode/objects.h"
#include "Scene.h"

static void gameLoop();
const COLORREF bgcol = 0x0f0f10;


int main()
{
    //window declaration
    int gd=DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    
    setbkcolor(bgcol);


    //contains actual loop and declarations of objs
    gameLoop();


    closegraph();
    return 0;
}




static void gameLoop()
{
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::duration<double> deltaTime;
    char fps[50];

    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::minstd_rand0 generator(seed);

    Rigidbody *objects[2];
    int len = sizeof(objects)/sizeof(objects[0]);

    Ball b(400, 200, 50);
    Rect r(200, 200, 75, 75);

    objects[0] = &b;
    objects[1] = &r;

    objects[0]->isStatic = false;
    objects[1]->isStatic = false;
    Vec2 mousePos;


    //The Loop:
    for(int frame = 0; frame>=0; frame++)
    {
        startTime = std::chrono::high_resolution_clock::now();
        mousePos.setTo( Vec2(mousex(), mousey()) );
        //clear screen
        clearviewport();

        //draw
        setlinestyle(0,0,2);

        for (int i = 0; i < len; i++)
        {
            objects[i]->draw();
            char tempI[5];
            sprintf(tempI, "%d", i);
            outtextxy(objects[i]->getX(),objects[i]->getY(), (char *)tempI);
        }

        int speed = 3;
        Vec2 dir;

        if(GetAsyncKeyState(VK_UP))
        {
            dir = dir + Vec2(0,-1);
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            dir = dir + Vec2(0,1);
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            dir = dir + Vec2(1,0);
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            dir = dir + Vec2(-1,0);
        }

        dir.normalise();
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

                if(dist < 0)
                {
                    normal.normalise();

                    if(!objects[i]->isStatic && !objects[j]->isStatic)
                    {
                        objects[j]->Move(normal*abs(dist)*0.5);
                        objects[i]->Move(normal*abs(dist)*-0.5);
                    }
                    else if(objects[i]->isStatic && !objects[j]->isStatic)
                    {
                        objects[j]->Move(normal*abs(dist)*1);
                    }
                    else if(!objects[i]->isStatic && objects[j]->isStatic)
                    {
                        objects[i]->Move(normal*abs(dist)*-1);
                    }
                }
            }
            
        }
            
        
        




        //Print out Fps on the screen
        sprintf(fps, "%d", (int)(1/(double)deltaTime.count()));
        outtextxy(getmaxx()-30, 10, (char *)fps);





        //display correction
        swapbuffers();
        delay(5);

        deltaTime = std::chrono::high_resolution_clock::now() - startTime;



        //loop break
        if(GetAsyncKeyState(0x1b))
        {
            break;
        }

        
    }
}
