#include "SceneManager.h"

SceneManager::SceneManager()
{
}
SceneManager::~SceneManager()
{
    this->clear();
    std::cout << "Destructor has been called";
}

void SceneManager::Init()
{
    objects_array.clear();
}

void SceneManager::AddRigidbody(Rigidbody* obj)
{
    this->objects_array.push_back(obj);
}

void SceneManager::Update()
{
    // CollisionHandler::HandleCollisions(&objects_array);
    //std::cout << objects_array.size() << std::endl;

}
/**
 * TODO: Refactor this function
 */
void SceneManager::Render(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface)
{
    RenderHandler::Render(window, renderer, surface, &objects_array);
}

void SceneManager::clear()
{
    for(auto& objPointer : objects_array)
    {
        delete objPointer;
    }
    objects_array.clear();
}


/**
 *  ! DONT USE YET!
 * \param xpos x position of obj
 * \param ypos y position of obj
 * \param width width of Rect
 * \param height height of Rect
*/
void SceneManager::Rect(int xpos, int ypos, float width, float height)
{
    objects::Rect *r = new objects::Rect(xpos, ypos, width, height);
    AddRigidbody(r);
 
}

/**
 * ! DONT USE YET!
 * \param xpos x position of obj
 * \param ypos y position of obj
 * \param radius radius of circle
*/
void SceneManager::Circle(int xpos, int ypos, float radius)
{
    objects::Circle* c = new objects::Circle(xpos, ypos, radius);
    AddRigidbody(c);
}