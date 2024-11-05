#ifndef _SCENEUTILS_H
#define _SCENEUTILS_H

#include <vector>
#include <SDL2/SDL.h>

#include "objects.h"

namespace CollisionHandler
{
    void HandleCollisions(std::vector<Rigidbody*> objects);
}; // namespace CollisionHandler

namespace RenderHandler
{
    void Render(SDL_Window* window, SDL_Renderer* renderer, std::vector<Rigidbody*>);
}; // namespace RenderHandler


#endif//_SCENEUTILS_H