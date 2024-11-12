#include "Renderer.h"


void SceneRenderer::Render(SDL_Window* window, SDL_Renderer* renderer, std::vector<Rigidbody*>* objsArrayPointer)
{
    /**
     * Extremely Laggy rendering
     */
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if(surface == NULL)
    {
        std::cout << "Error Rendering to Screen...\n" << SDL_GetError() << '\n';
        return;
    }

    
    SDL_LockSurface(surface);
    ColourAtPixelCoords info;
    Uint8* pixelArray = (Uint8*) surface->pixels;
    for (int y = 0; y < surface->h; y++)
    {
        for (int x = 0; x < surface->w; x++)
        {
            info = FindColourAtPixel(x, y, objsArrayPointer);

            pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 0] = info.r;
            pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 1] = info.g;
            pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 2] = info.b;
        }
        
    }
    

    SDL_UnlockSurface(surface);
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);

    
}

SceneRenderer::ColourAtPixelCoords SceneRenderer::FindColourAtPixel(const int x, const int y, const std::vector<Rigidbody*>* _objsArrayPointer)
{
    ColourAtPixelCoords info;
    if(_objsArrayPointer->empty())
    {
        info = {MAXFLOAT, 0, 0, 0};
        return info;
    }
    
    info.dist = _objsArrayPointer->at(0)->signedDistFunc(Vec2(x,y));
    for(auto& obj : *_objsArrayPointer)
    {
        float dist = obj->signedDistFunc(Vec2(x,y));
        if (info.dist > dist)
        {
            info.dist = dist;
        }
    }
    if(info.dist<1)
    {
        info.r = 255;
        info.g = 255;
        info.b = 255;
    }
    else
    {
        info.r = 0;
        info.g = 0;
        info.b = 0;
    }
    return info;
}
