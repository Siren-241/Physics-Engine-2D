#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL2/SDL.h>

#include "objects.h"

namespace SceneRenderer
{

    struct ColourAtPixelCoords
    {
        float dist;
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };

    void Render(SDL_Window* window, SDL_Renderer* renderer, std::vector<Rigidbody*>* _objects);

    ColourAtPixelCoords FindColourAtPixel(const int x, const int y, const std::vector<Rigidbody*>* _objsArrayPointer);
    
} // namespace SceneRenderer

#endif //RENDERER_H