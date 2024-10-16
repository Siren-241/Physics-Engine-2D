#include <iostream>
//#include <graphics.h>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>
#include <GLFW/glfw3.h>

#include "sourceCode/Math2D.h"
#include "sourceCode/Rigidbody.h"
#include "sourceCode/objects.h"
#include "sourceCode/utils.h"
#include "sourceCode/SceneManager.h"
#include "sourceCode/glad/glad.h"

const int BACK_COL = 0x0f0f10;
static void gameLoop();

Vec2 readWASDInputs();
void displayCorrection();
//void drawObjects(Rigidbody*[], int);
void displayFPS(char*, std::chrono::duration<double>);
Vec2 findNormal(Vec2);
float findDistance(Rigidbody*, Rigidbody*);
void drawNormals(Vec2);


char fps[50];
Scene sampleScene;


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


    //unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    //std::minstd_rand0 generator(seed);
    Ball b1(getmaxx()/2, getmaxy() ,50);
    Rect r1(getmaxx()/2, getmaxy()/2 ,100, 50);
    std::vector<Rigidbody*> objs;
    objs.push_back(&b1);
    objs.push_back(&r1);
    

    Vec2 mousePos;
    sampleScene.SceneInit(&objs);

    //The Loop:
    for(int frame = 0; frame>=0; frame++)
    {
        startTime = std::chrono::high_resolution_clock::now();
        mousePos.setTo( Vec2(mousex(), mousey()) );

        //clear screen
        clearviewport();

        //draw
        sampleScene.drawScene();


        int speed = 5;
        Vec2 dir = readWASDInputs();

        sampleScene.unique_objects_array.at(0)->Move(dir*speed);

        //debug mouse sdf
        if(GetKeyState(VK_LBUTTON) & 0x8000)
        {
            float min_dist = sampleScene.sceneSDF(mousePos);
            circle(mousePos.getX(), mousePos.getY(), min_dist);
            circle(mousePos.getX(), mousePos.getY(), 2);
        }

        #if false
            for (int i = 0; i < sampleScene.unique_objects_array.size() - 1; i++)
            {
                for (int j = i + 1; j < sampleScene.unique_objects_array.size(); j++)
                {
                    Vec2 normal = findNormal(sampleScene.unique_objects_array.at(j)->getPos());
                    float dist = sampleScene.sceneSDF(sampleScene.unique_objects_array.at(j)->getPos());
                    drawNormals(sampleScene.unique_objects_array.at(j)->getPos());

                    if(dist > 0)
                    {
                        break;
                    }

                    if(!sampleScene.unique_objects_array.at(i)->isStatic && !sampleScene.unique_objects_array.at(j)->isStatic)
                    {
                        sampleScene.unique_objects_array.at(j)->Move(normal*abs(dist) * 0.5);
                        sampleScene.unique_objects_array.at(i)->Move(normal*abs(dist) * -0.5);
                    }
                    else if(sampleScene.unique_objects_array.at(i)->isStatic && !sampleScene.unique_objects_array.at(j)->isStatic)
                    {
                        sampleScene.unique_objects_array.at(j)->Move(normal*abs(dist) *  1);
                    }
                    else if(!sampleScene.unique_objects_array.at(i)->isStatic && sampleScene.unique_objects_array.at(j)->isStatic)
                    {
                        sampleScene.unique_objects_array.at(i)->Move(normal*abs(dist) * -1);
                    }
                    
                }
                
            }
        #endif
        #if true
        for (int i = 0; i < sampleScene.unique_objects_array.size(); i++)
        {
            for (int j = 0; j < sampleScene.unique_objects_array.size()-1; j++)
            {
                Vec2 normal = findNormal(sampleScene.unique_objects_array.at(i)->getPos());
                float dist = findDistance(
                    sampleScene.unique_objects_array.at(i),
                    sampleScene.unique_objects_array.at(j));
            
                if(dist > 0)
                {
                    break;
                }

                if(!sampleScene.unique_objects_array.at(i)->isStatic && !sampleScene.unique_objects_array.at(j)->isStatic)
                {
                    sampleScene.unique_objects_array.at(j)->Move(normal*abs(dist) * 0.5);
                    sampleScene.unique_objects_array.at(i)->Move(normal*abs(dist) * -0.5);
                }
                else if(sampleScene.unique_objects_array.at(i)->isStatic && !sampleScene.unique_objects_array.at(j)->isStatic)
                {
                    sampleScene.unique_objects_array.at(j)->Move(normal*abs(dist) *  1);
                }
                else if(!sampleScene.unique_objects_array.at(i)->isStatic && sampleScene.unique_objects_array.at(j)->isStatic)
                {
                    sampleScene.unique_objects_array.at(i)->Move(normal*abs(dist) * -1);
                }
            }
            
        }
        
        #endif

        //Normal testing 
        drawNormals(mousePos);

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

/* void drawObjects(Rigidbody *_objs[], int _len)
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
 */
void drawNormals(Vec2 _mPos)
{
    float len = sampleScene.sceneSDF(_mPos);
    Vec2 _end = findNormal(_mPos);
    _end.normalise();
    _end.setTo(_end * abs(len));
    //printf("%f",_end.mag());
    //printf("\n");
    line(getmaxx()/2,getmaxy()/2, getmaxx()/2+_end.getX(),getmaxy()/2+_end.getY());
}

Vec2 findNormal(Vec2 pos)
{
    Vec2 v1 = Vec2(
        sampleScene.sceneSDF(pos + Vec2(ELIPSON, 0.0)),
        sampleScene.sceneSDF(pos + Vec2(0.0, ELIPSON))
    );
    Vec2 v2 = Vec2(
        sampleScene.sceneSDF(pos - Vec2(ELIPSON, 0.0)),
        sampleScene.sceneSDF(pos - Vec2(0.0, ELIPSON))
    );
    Vec2 temp = v1-v2;
    temp.normalise();
    return temp;
}

float findDistance(Rigidbody* r1, Rigidbody* r2)
{
    
}