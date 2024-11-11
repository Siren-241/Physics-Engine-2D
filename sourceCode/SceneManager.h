#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SDL2/SDL.h>
#include <memory>

#include "Math2D.h"
#include "objects.h"
#include "SceneUtils.h"

class SceneManager
{
    private:
        std::vector<Rigidbody*> objects_array{};
        // std::vector<std::unique_ptr<Rigidbody>> smartObjPointerArray;        
        void AddRigidbody(Rigidbody* obj);
    public:
        SceneManager();
        ~SceneManager();
        void Init();
        void Update();
        void Render(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface);
        void clear();
        // float sceneSDF(Vec2);
        // Add objects to scene
        void Rect(int xpos, int ypos, float width, float height);
        void Circle(int xpos, int ypos, float radius);
};

#endif// SCENE_H