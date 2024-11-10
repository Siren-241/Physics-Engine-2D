#include "SceneManager.h"

SceneManager::SceneManager()
{
}
SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
    objects_array.clear();
}

// void SceneManager::AddRigidbody(Rigidbody* obj)
// {
//     objects_array.push_back(obj);
// }

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



/**
 *  ! DONT USE YET!
 * \param xpos x position of obj
 * \param ypos y position of obj
 * \param width width of Rect
 * \param height height of Rect
*/
void SceneManager::Rect(int xpos, int ypos, float width, float height)
{
    // PROBLEM : r is going out of scope and garbage values are being read
    objects::Rect r(xpos, ypos, width, height);
    // this->objects_array.push_back(&r);
}

/**
 * ! DONT USE YET!
 * \param xpos x position of obj
 * \param ypos y position of obj
 * \param radius radius of circle
*/
void SceneManager::Circle(SceneManager* scene, int xpos, int ypos, float radius)
{
    objects::Circle* c;
    *c = objects::Circle(xpos, ypos, radius);
    // scene->AddRigidbody(c);
}