#include "SceneManager.h"

SceneManager::SceneManager()
{
}
SceneManager::~SceneManager()
{
    this->clear();
}

void SceneManager::Init()
{
    this->objects_array.clear();
}

void SceneManager::AddRigidbody(Rigidbody* obj)
{
    this->objects_array.push_back(obj);
}

void SceneManager::Update()
{
    if (!objects_array.empty())
    {
        using std::cout;
        SDL_Event event;
        SDL_PollEvent(&event);
        Vec2 dir(0);
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_w:
                        dir = dir + Vec2(0, -1);
                        // cout<< "W" << '\n';
                        break;
                    
                    case SDLK_a:
                        dir = dir + Vec2(-1, 0);
                        // cout<< "A" << '\n';
                        break;
                        
                    case SDLK_s:
                        dir = dir + Vec2(0,  1);
                        // cout<< "S" << '\n';
                        break;

                    case SDLK_d:
                        dir = dir + Vec2(1,  0);
                        // cout<< "D" << '\n';
                        break;
                
                    default:
                        break;
                }

                break;
            
            default:
                break;
        }

        dir.normalise();
        objects_array.at(0)->Move( dir * 10.0 );
    }

}
/**
 * TODO: Refactor this function
 */
void SceneManager::Render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderClear(renderer);

    if (objects_array.empty())
    {
        SDL_RenderPresent(renderer);
        return;
    }
    
    for(const auto& obj : objects_array)
    {
        obj->draw(renderer);
    }
    
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderPresent(renderer);
}

void SceneManager::clear()
{
    for(auto& objPointer : objects_array)
    {
        delete objPointer;
    }
    objects_array.clear();
}


/**
 * \param xpos x position of obj
 * \param ypos y position of obj
 * \param width width of Rect
 * \param height height of Rect
*/
void SceneManager::AddRect(int xpos, int ypos, float width, float height)
{
    objects::Rect *r = new objects::Rect(xpos, ypos, width, height);
    AddRigidbody(r);
 
}

/**
 * \param xpos x position of obj
 * \param ypos y position of obj
 * \param radius radius of circle
*/
void SceneManager::AddCircle(int xpos, int ypos, float radius)
{
    objects::Circle* c = new objects::Circle(xpos, ypos, radius);
    AddRigidbody(c);
}