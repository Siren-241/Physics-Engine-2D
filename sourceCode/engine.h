#ifndef _MY_ENGINE
#define _MY_ENGINE

#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>
#include <SDL2/SDL.h>

#include "Math2D.h"
#include "Rigidbody.h"
#include "objects.h"
#include "utils.h"
#include "SceneManager.h"

class Engine
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* surface;
        bool running;

        SceneManager scene;
        
    public:
        Engine();
        ~Engine();

        void Init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
        void Populate();
        void HandleEvents();
        void Update();
        void Render(float targetFramerate);
        inline bool isRunning() { return running; }
        void Kill();
};



#endif // _MY_ENGINE