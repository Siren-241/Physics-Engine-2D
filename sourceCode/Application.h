#ifndef APPLICATION_H
#define APPLICATION_H

#include "engine.h"

class App
{
    private:
        Engine engine;

    public:
        App();
        ~App();
        void Init(int width, int height, const char* window_name, bool fullscreen);
        void Run(float targetFramerate);
    
};

#endif // APPLICATION_H