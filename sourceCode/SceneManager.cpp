#include "SceneManager.h"

void SceneManager::AddRigidbody(Rigidbody* obj)
{
    objects_array.push_back(obj);
}

void SceneManager::Update()
{
    CollisionHandler::HandleCollisions(objects_array);
}

void SceneManager::Render(SDL_Window* window, SDL_Renderer* renderer)
{
    //SDL_RenderDrawPointF(renderer);
    RenderHandler::Render(window, renderer, objects_array);
}



/**
* \param scene The scene in which obj has to be added
* \param xpos x position of obj
* \param ypos y position of obj
* \param width width of Rect
* \param height height of Rect
*/
void AddObject::Rect(SceneManager scene, int xpos, int ypos, int width, int height)
{
    objects::Rect* r;
    r = new objects::Rect(xpos, ypos, width, height);
    scene.AddRigidbody(r);
}

/**
* \param scene The scene in which obj has to be added
* \param xpos x position of obj
* \param ypos y position of obj
* \param radius radius of circle
*/
void AddObject::Circle(SceneManager scene, int xpos, int ypos, int radius)
{
    objects::Circle* c;
    c = new objects::Circle(xpos, ypos, radius);
    scene.AddRigidbody(c);
}