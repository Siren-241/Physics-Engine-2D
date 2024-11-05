#include "SceneUtils.h"

void CollisionHandler::HandleCollisions(std::vector<Rigidbody*> _objects)
{
    //TODO: Implement Sdf collisions
}

void RenderHandler::Render(SDL_Window* window, SDL_Renderer* renderer, std::vector<Rigidbody*> _objects)
{
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    //std::cout << width << " and " << height <<'\n';
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
    //         if (!_objects.empty())
    //         {
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
    //         }
            
        }
        
    }
    
}