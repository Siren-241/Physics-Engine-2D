#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SDL2/SDL.h>
#include "Math2D.h"
#include "objects.h"
#include "SceneUtils.h"

class SceneManager
{
    private:
        std::vector<Rigidbody*> objects_array;
    
    public:
        void AddRigidbody(Rigidbody* obj);
        void Update();
        void Render(SDL_Window* window, SDL_Renderer* renderer);
        float sceneSDF(Vec2);
};


namespace AddObject
{
    void Rect(SceneManager scene, int xpos, int ypos, int width, int height);
    void Circle(SceneManager scene, int xpos, int ypos, int radius);
};
#endif// SCENE_H