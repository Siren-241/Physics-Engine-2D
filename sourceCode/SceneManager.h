#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Math2D.h"
#include "objects.h"

class Scene
{
    public:
    std::vector<Rigidbody*> unique_objects_array;

        void SceneInit(std::vector<Rigidbody*>*);
        void drawScene();
        float sceneSDF(Vec2);
};

#endif// SCENE_H