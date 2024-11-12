#include "engine.h"


Engine::Engine()
{
}

Engine::~Engine()
{
}
  
/**
 * Initialize the engine
 * @param title The Title of the Window 
 * @param xpos x position of the Window, Put SDL_WINDOWPOS_CENTERED to center
 * @param ypos y position of the Window, Put SDL_WINDOWPOS_CENTERED to center
 * @param width width of Window 
 * @param height height of Window 
 * @param fullScreen put true for fullscreen window, false by default 
 */
void Engine::Init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen = false)
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
   
        
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

/**
 * Populates the Scene with Rigidbodies
 */
void Engine::Populate()
{
    scene.AddRect(400, 300, 100, 100);
    scene.AddCircle(50, 300, 100.0);
}

void Engine::Update()
{
    scene.Update();
}
void Engine::Render(float targetFramerate)
{
    float desiredDelta = 1000.00/targetFramerate;
    Uint64 start = SDL_GetTicks64();


    if(SDL_RenderClear(renderer) < 0)
    {
        std::cout << "Error : " << SDL_GetError() << '\n';
        return;
    }
    scene.Render(window, renderer);
 
    Uint64 delta = SDL_GetTicks64() - start;

    if (desiredDelta > delta)
    {
        SDL_Delay(desiredDelta-delta);
    }
    float currFps = 1000.0/delta;

    // TODO : Display current FPS
    // !Doesnt work
    // std::cout << "FPS : " << currFps << '\n';

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

void Engine::Kill()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << SDL_GetError() << '\n';
    SDL_Quit();
    running = false;

    std::cout << "\nKilled Engine\n";
}
