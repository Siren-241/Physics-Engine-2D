#include "sourceCode/engine.h"

Vec2 readWASDInputs();

Vec2 findNormal(Vec2);
float findDistance(Rigidbody*, Rigidbody*);
void drawNormals(Vec2);
int _ManageWindow(GLFWwindow*);


int main()
{
    int width = 800, height = 600;
    Engine* engine;
    engine->Init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);
    engine->Populate();
    
    //GameLoop
    while (engine->isRunning())
    {
        engine->HandleEvents();
        engine->Update();
        engine->Render();
    }
       
    
    return 0;
}

// int _ManageWindow(GLFWwindow* window)
// {
    
//     //start of non-OpenGL code



//     std::chrono::time_point<std::chrono::system_clock> startTime;
//     std::chrono::duration<double> deltaTime;


//     //unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
//     //std::minstd_rand0 generator(seed);
    

//     Vec2 mousePos;
    



//     while(!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
//     {
//         startTime = std::chrono::high_resolution_clock::now();
//         mousePos.setTo( Vec2(mousex(window), mousey(window)));

//         //clear screen
//         //clearviewport();

//         //draw


//         int speed = 5;
//         //Vec2 dir = readWASDInputs(window);


//         //debug mouse sdf
//         /*
//         if(GetKeyState(VK_LBUTTON) & 0x8000)
//         {
//             float min_dist = sampleScene.sceneSDF(mousePos);
//             circle(mousePos.getX(), mousePos.getY(), min_dist);
//             circle(mousePos.getX(), mousePos.getY(), 2);
//         }*/
//        //drawLine(window, Vec2(0), Vec2(10));
       
//        std::cout<<"CURRENT :: engine : debug mouse sdf yet to be implemented...\n";
       

//         #if false
//             for (int i = 0; i < sampleScene.unique_objects_array.size() - 1; i++)
//             {
//                 for (int j = i + 1; j < sampleScene.unique_objects_array.size(); j++)
//                 {
//                     Vec2 normal = findNormal(sampleScene.unique_objects_array.at(j)->getPos());
//                     float dist = sampleScene.sceneSDF(sampleScene.unique_objects_array.at(j)->getPos());
//                     drawNormals(sampleScene.unique_objects_array.at(j)->getPos());

//                     if(dist > 0)
//                     {
//                         break;
//                     }

//                     if(!sampleScene.unique_objects_array.at(i)->isStatic && !sampleScene.unique_objects_array.at(j)->isStatic)
//                     {
//                         sampleScene.unique_objects_array.at(j)->Move(normal*abs(dist) * 0.5);
//                         sampleScene.unique_objects_array.at(i)->Move(normal*abs(dist) * -0.5);
//                     }
//                     else if(sampleScene.unique_objects_array.at(i)->isStatic && !sampleScene.unique_objects_array.at(j)->isStatic)
//                     {
//                         sampleScene.unique_objects_array.at(j)->Move(normal*abs(dist) *  1);
//                     }
//                     else if(!sampleScene.unique_objects_array.at(i)->isStatic && sampleScene.unique_objects_array.at(j)->isStatic)
//                     {
//                         sampleScene.unique_objects_array.at(i)->Move(normal*abs(dist) * -1);
//                     }
                    
//                 }
                
//             }
//         #endif


//         #if false
//         for (int i = 0; i < sampleScene.unique_objects_array.size(); i++)
//         {
//             for (int j = 0; j < sampleScene.unique_objects_array.size()-1; j++)
//             {
//                 Vec2 normal = findNormal(sampleScene.unique_objects_array.at(i)->getPos());
//                 float dist = findDistance(
//                     sampleScene.unique_objects_array.at(i),
//                     sampleScene.unique_objects_array.at(j));
            
//                 if(dist > 0)
//                 {
//                     break;
//                 }

//                 if(!sampleScene.unique_objects_array.at(i)->isStatic && !sampleScene.unique_objects_array.at(j)->isStatic)
//                 {
//                     sampleScene.unique_objects_array.at(j)->Move(normal*abs(dist) * 0.5);
//                     sampleScene.unique_objects_array.at(i)->Move(normal*abs(dist) * -0.5);
//                 }
//                 else if(sampleScene.unique_objects_array.at(i)->isStatic && !sampleScene.unique_objects_array.at(j)->isStatic)
//                 {
//                     sampleScene.unique_objects_array.at(j)->Move(normal*abs(dist) *  1);
//                 }
//                 else if(!sampleScene.unique_objects_array.at(i)->isStatic && sampleScene.unique_objects_array.at(j)->isStatic)
//                 {
//                     sampleScene.unique_objects_array.at(i)->Move(normal*abs(dist) * -1);
//                 }
//             }
            
//         }
//         #endif
        
        

//         //Normal testing 
//         drawNormals(mousePos);




//         deltaTime = std::chrono::high_resolution_clock::now() - startTime;




//     }


//     return 0;
// }


// Vec2 readWASDInputs(GLFWwindow* window)
// {
// /*     Vec2 _dir;
//     if(GetAsyncKeyState(K_W))
//     {
//         _dir = _dir + Vec2(0,-1);
//     }
//     if(GetAsyncKeyState(K_S))
//     {
//         _dir = _dir + Vec2(0,1);
//     }
//     if(GetAsyncKeyState(K_D))
//     {
//         _dir = _dir + Vec2(1,0);
//     }
//     if(GetAsyncKeyState(K_A))
//     {
//         _dir = _dir + Vec2(-1,0);
//     }

//     _dir.normalise();
//     return _dir;
//  */

//     Vec2 _dir;

//     int stateW = glfwGetKey(window, GLFW_KEY_W), stateA = glfwGetKey(window, GLFW_KEY_A), stateS = glfwGetKey(window, GLFW_KEY_S), stateD = glfwGetKey(window, GLFW_KEY_D);
//     if(stateW == GLFW_PRESS)
//         _dir = _dir + Vec2(0,-1);
//     if(stateA == GLFW_PRESS)
//         _dir = _dir + Vec2(-1,0);
//     if(stateS == GLFW_PRESS)
//         _dir = _dir + Vec2(0,1);
//     if(stateD == GLFW_PRESS)
//         _dir = _dir + Vec2(1,0);
    
//     _dir.normalise();
    
    
//     //std::cout<<"engine : readWASDInputs yet to be implemented...\n";
    
    
//     return _dir;

// }

// /* void drawObjects(Rigidbody *_objs[], int _len)
// {
//     setlinestyle(0,0,2);
//     for (int i = 0; i < _len; i++)
//     {
//         _objs[i]->draw();
//         char _tempI[5];
//         sprintf(_tempI, "%d", i);
//         outtextxy(_objs[i]->getX(),_objs[i]->getY(), (char *)_tempI);
//     }
// }
//  */
// void drawNormals(Vec2 _mPos)
// {/* 
//     float len = sampleScene.sceneSDF(_mPos);
//     Vec2 _end = findNormal(_mPos);
//     _end.normalise();
//     _end.setTo(_end * abs(len));
//     line(getmaxx(window)/2,getmaxy(window)/2, getmaxx(window)/2+_end.getX(),getmaxy(window)/2+_end.getY());
// */
     
//     std::cout<<"engine : drawNormals yet to be implemented...\n";
    
// }
// /*/
// Vec2 findNormal(Vec2 pos)
// {
//     Vec2 v1 = Vec2(
//         sampleScene.sceneSDF(pos + Vec2(ELIPSON, 0.0)),
//         sampleScene.sceneSDF(pos + Vec2(0.0, ELIPSON))
//     );
//     Vec2 v2 = Vec2(
//         sampleScene.sceneSDF(pos - Vec2(ELIPSON, 0.0)),
//         sampleScene.sceneSDF(pos - Vec2(0.0, ELIPSON))
//     );
//     Vec2 temp = v1-v2;
//     temp.normalise();
//     return temp;
// }
// */
// float findDistance(Rigidbody* r1, Rigidbody* r2)
// {
    
//     std::cout<<"engine : findDistance yet to be implemented...\n";
    

//     return 0;

// }