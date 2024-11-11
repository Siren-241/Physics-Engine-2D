#include "engine.h"


Engine::Engine()
{
}

Engine::~Engine()
{
}
  

void Engine::Init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL_Init Successful...\n";

        int flags = fullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window != NULL)
        {
            std::cout << "Window created Successfully...\n";
        }
        else
        {
            std::cout << "Window creation Failed...\n" << SDL_GetError() << '\n';
        }
   
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer != NULL)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            std::cout << "Renderer created Successfully...\n";
        }
        else
        {
            std::cout << "Rendered creation Failed...\n" << SDL_GetError() << '\n';
        }
        
        surface = SDL_GetWindowSurface(window);
        if (surface != NULL)
        {
            std::cout << "Surface created Successfully...\n";
        }
        else
        {
            std::cout << "Surface creation Failed...\n" << SDL_GetError() << '\n';
        }
        
        scene.Init();
        running = true;
    }
    else
    {
        std::cout << "Init Failed...\n" << SDL_GetError() << '\n';
        running = false;
    }
    
}

void Engine::Populate()
{
    scene.Rect(400,300,100,100);
    scene.Circle(50, 300, 100.0);
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
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    Kill();
                    break;
                case SDLK_c:
                    scene.clear();
                    break;
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
    scene.Render(window, renderer, surface);
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
