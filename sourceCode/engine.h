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
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool running;
public:
    Engine();
    ~Engine();

    void Init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
    void HandleEvents();
    void Update();
    void Render();
    bool isRunning() { return running; }
    void Kill();
};



#endif // _MY_ENGINE