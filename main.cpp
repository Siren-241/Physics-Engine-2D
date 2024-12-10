#include "sourceCode/engine.h"


Vec2 findNormal(Vec2);
float findDistance(Rigidbody*, Rigidbody*);
void drawNormals(Vec2);


int main()
{
    int width = 1280, height = 720;
    Engine engine;
    engine.Init("Physics 2D Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);
    engine.Populate();
    
    //GameLoop
    while (engine.isRunning())
    {
        engine.HandleEvents();
        engine.Update();
        engine.Render(60.00);
    }
       
    
    return 0;
}

// int _ManageWindow(GLFWwindow* window)
// {

//     while(!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
//     {
//         mousePos.setTo( Vec2(mousex(window), mousey(window)));

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

/**
 * !Following Code is important 
 * Do not delete
 */
// void drawNormals(Vec2 _mPos)
// { 
//     float len = sampleScene.sceneSDF(_mPos);
//     Vec2 _end = findNormal(_mPos);
//     _end.normalise();
//     _end.setTo(_end * abs(len));
//     line(getmaxx(window)/2,getmaxy(window)/2, getmaxx(window)/2+_end.getX(),getmaxy(window)/2+_end.getY());
//      
// }
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