#include "engine.h"


Engine::Engine()
{
    
}

Engine::~Engine()
{
    Kill();
}
  

void Engine::Init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{

    int flags = fullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

    //As per current need only video is needed...
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        std::cout << "SDL_Init Successful...\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created Successfully...\n";
        }
        else
        {
            std::cout << "Window creation Failed...\n";
        }
        
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer != NULL)
        {
            SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
            std::cout << "Renderer created Successfully...\n";
        }
        else
        {
            std::cout << "Rendered creation Failed...\n";
        }
        

        running = true;
    }
    else
    {
        running = false;
    }
    
}

void Engine::Populate()
{
    AddObject::Rect(scene, 0,0,100,100);
}

void Engine::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            Kill();
            break;
            
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                Kill();
            }
            break;
            
        default:
            break;
    }
}

void Engine::Update()
{
    scene.Update();
}
void Engine::Render()
{
    SDL_RenderClear(renderer);
    scene.Render(window, renderer);
    SDL_RenderPresent(renderer);
}


void Engine::Kill()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    running = false;

    std::cout << "\nKilled Engine\n";
}
