#include "Application.h"

App::App()
{
    std::cout << "\nApp successfully Initiated\n";
}

App::~App()
{
}

void App::Init(int width, int height, const char* window_name, bool fullscreen = false)
{
    engine.Init(window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fullscreen);
    engine.Populate();
}

void App::Run(float targetFramerate)
{
    while (engine.isRunning())
    {
        engine.HandleEvents();
        engine.Update();
        engine.Render(targetFramerate);
    }
}