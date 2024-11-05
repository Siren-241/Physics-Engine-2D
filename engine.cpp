#include <iostream>
//#include <graphics.h>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>

#include "sourceCode/Math2D.h"
#include "sourceCode/Rigidbody.h"
#include "sourceCode/objects.h"
#include "sourceCode/utils.h"
#include "sourceCode/SceneManager.h"

#include "sourceCode/glad/glad.h"
#include <GLFW/glfw3.h>

const int BACK_COL = 0x0f0f10;
static void gameLoop();

Vec2 readWASDInputs(GLFWwindow*);
void displayFPS(char*, std::chrono::duration<double>);
Vec2 findNormal(Vec2);
float findDistance(Rigidbody*, Rigidbody*);
void drawNormals(Vec2);
int _ManageWindow(GLFWwindow*);

char fps[50];
Scene sampleScene;


int main()
{
    //window declaration
    #if false //graphics.h code
    int gd=DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    
    setbkcolor(BACK_COL);

    closegraph();
    #endif
    
    GLFWwindow* window;

    if(_ManageWindow(window) != 0)
    {
        return -1;
    }
    
   
    
    return 0;
}

int _ManageWindow(GLFWwindow* window)
{
    
    if(!glfwInit())return -1;

    window = glfwCreateWindow(640, 480, "Engine", NULL, NULL);

    if(!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout<<"Couldn't load OpenGL"<< std::endl;
        glfwTerminate();
        return -1;
    }
    glClearColor(0.25f, 0.5f, 0.75f, 1);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    //start of non-OpenGL code



    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::duration<double> deltaTime;


    //unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    //std::minstd_rand0 generator(seed);
    Ball b1(getmaxx(window)/2, getmaxy(window) ,50);
    Rect r1(getmaxx(window)/2, getmaxy(window)/2 ,100, 50);
    std::vector<Rigidbody*> objs;
    objs.push_back(&b1);
    objs.push_back(&r1);
    

    Vec2 mousePos;
    sampleScene.SceneInit(&objs);




    while(!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
    {
        startTime = std::chrono::high_resolution_clock::now();
        mousePos.setTo( Vec2(mousex(window), mousey(window)));

        //clear screen
        //clearviewport();

        //draw
        sampleScene.drawScene();


        int speed = 5;
        Vec2 dir = readWASDInputs(window);

        sampleScene.unique_objects_array.at(0)->Move(dir*speed);

        //debug mouse sdf
        /*
        if(GetKeyState(VK_LBUTTON) & 0x8000)
        {
            float min_dist = sampleScene.sceneSDF(mousePos);
            circle(mousePos.getX(), mousePos.getY(), min_dist);
            circle(mousePos.getX(), mousePos.getY(), 2);
        }*/
       //drawLine(window, Vec2(0), Vec2(10));
       
       std::cout<<"CURRENT :: engine : debug mouse sdf yet to be implemented...\n";
       

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



        deltaTime = std::chrono::high_resolution_clock::now() - startTime;





        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    return 0;
}


void displayFPS(char *fps, std::chrono::duration<double> dt)
{
  /*   sprintf(fps, "%d", (int)(1/(double)dt.count()));
    char info[10] =  "FPS: ";
    strcat(info, fps);
    outtextxy(10, 10, (char *)info); */

    
    std::cout<<"engine : diplayFPS func yet to be implemented...\n\n";
    

}
Vec2 readWASDInputs(GLFWwindow* window)
{
/*     Vec2 _dir;
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
 */

    Vec2 _dir;

    int stateW = glfwGetKey(window, GLFW_KEY_W), stateA = glfwGetKey(window, GLFW_KEY_A), stateS = glfwGetKey(window, GLFW_KEY_S), stateD = glfwGetKey(window, GLFW_KEY_D);
    if(stateW == GLFW_PRESS)
        _dir = _dir + Vec2(0,-1);
    if(stateA == GLFW_PRESS)
        _dir = _dir + Vec2(-1,0);
    if(stateS == GLFW_PRESS)
        _dir = _dir + Vec2(0,1);
    if(stateD == GLFW_PRESS)
        _dir = _dir + Vec2(1,0);
    
    _dir.normalise();
    
    
    //std::cout<<"engine : readWASDInputs yet to be implemented...\n";
    

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
{/* 
    float len = sampleScene.sceneSDF(_mPos);
    Vec2 _end = findNormal(_mPos);
    _end.normalise();
    _end.setTo(_end * abs(len));
    line(getmaxx(window)/2,getmaxy(window)/2, getmaxx(window)/2+_end.getX(),getmaxy(window)/2+_end.getY());
*/
     
    std::cout<<"engine : drawNormals yet to be implemented...\n";
    
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
    
    std::cout<<"engine : findDistance yet to be implemented...\n";
    

    return 0;

}