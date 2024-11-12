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
    this->objects_array.clear();
}

void SceneManager::AddRigidbody(Rigidbody* obj)
{
    this->objects_array.push_back(obj);
}

void SceneManager::Update()
{
    if (!objects_array.empty())
    {
        objects_array.at(0)->Move(Vec2(0.05, 0));
    }

}
/**
 * TODO: Refactor this function
 */
void SceneManager::Render(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderClear(renderer);

    if (objects_array.empty())
    {
        SDL_RenderPresent(renderer);
        return;
    }
    
    for(const auto& obj : objects_array)
    {
        obj->draw(renderer);
    }
    
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderPresent(renderer);
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
 * \param xpos x position of obj
 * \param ypos y position of obj
 * \param width width of Rect
 * \param height height of Rect
*/
void SceneManager::AddRect(int xpos, int ypos, float width, float height)
{
    objects::Rect *r = new objects::Rect(xpos, ypos, width, height);
    AddRigidbody(r);
 
}

/**
 * \param xpos x position of obj
 * \param ypos y position of obj
 * \param radius radius of circle
*/
void SceneManager::AddCircle(int xpos, int ypos, float radius)
{
    objects::Circle* c = new objects::Circle(xpos, ypos, radius);
    AddRigidbody(c);
}