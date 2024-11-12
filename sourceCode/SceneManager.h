#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <vector>

#include "Math2D.h"
#include "objects.h"
#include "Renderer.h"
#include "Collision.h"

class SceneManager
{
    private:
        std::vector<Rigidbody*> objects_array{};
        void AddRigidbody(Rigidbody* obj);
    public:
        SceneManager();
        ~SceneManager();

        void Init();
        void Update();
        void Render(SDL_Window* window, SDL_Renderer* renderer);
        void clear();
        // float sceneSDF(Vec2);
        
        // Add objects to scene
        void AddRect(int xpos, int ypos, float width, float height);
        void AddCircle(int xpos, int ypos, float radius);
};

#endif// SCENE_H