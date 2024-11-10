#ifndef _SCENEUTILS_H
#define _SCENEUTILS_H

#include <vector>
#include <SDL2/SDL.h>

#include "objects.h"


namespace CollisionHandler
{
    void HandleCollisions(std::vector<Rigidbody*>* objects);
}; // namespace CollisionHandler

namespace RenderHandler
{    
    void Render(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, std::vector<Rigidbody*>* _objects);
}; // namespace RenderHandler


struct ColourAtPixelCoords
{
    float dist;
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

ColourAtPixelCoords FindColourAtPixel(int x, int y, std::vector<Rigidbody*>* _objects);

#endif//_SCENEUTILS_H