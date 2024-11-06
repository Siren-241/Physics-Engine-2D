#include "SceneUtils.h"

void CollisionHandler::HandleCollisions(std::vector<Rigidbody*> _objects)
{
    //TODO: Implement Sdf collisions
}

void RenderHandler::Render(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, std::vector<Rigidbody*> _objects)
{

    if(surface == NULL)
    {
        std::cout << "Error Rendering to Screen...\n" << SDL_GetError() << '\n';
        return;
    }
    // if (_objects.empty())
    // {
    //     return;
    // }
    
    SDL_LockSurface(surface);
    ColourAtPixelCoords info;
    uint8_t* pixelArray = (uint8_t*) surface->pixels;
    for (int y = 0; y < surface->h; y++)
    {
        for (int x = 0; x < surface->w; x++)
        {
            info = FindColourAtPixel(x, y, _objects);

            pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 0] = info.r;
            pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 1] = info.g;
            pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 2] = info.b;
        }
        
    }
    

    SDL_UnlockSurface(surface);
    SDL_UpdateWindowSurface(window);




    /*
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (!_objects.empty())
            {
    //             float minDist = _objects.at(0)->signedDistFunc(Vec2(x, y));
    //             for(auto& obj : _objects)
    //             {
    //                 float dist = obj->signedDistFunc(Vec2(x, y));
    //                 if (dist < minDist)
    //                 {
    //                     minDist = dist;
    //                 }
    //             }
    //             if(minDist < 1)
    //             {
    //                 SDL_RenderDrawPoint(renderer, x, y);
    //             }
            }
            
        }
        
    }*/
    //std::cout << "Rendering To be Implemented\n";
    
}

ColourAtPixelCoords FindColourAtPixel(int x, int y, std::vector<Rigidbody*> _objects)
{
    if(_objects.empty())return{MAXFLOAT, 0, 0, 0};
    ColourAtPixelCoords info;
    info.dist = _objects.at(0)->signedDistFunc(Vec2(x,y));
    for(auto& obj : _objects)
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
