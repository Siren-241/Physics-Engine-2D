#include "SceneManager.h"


void Scene::SceneInit(std::vector<Rigidbody*>* _inList)
{
    for(auto& _obj : *_inList)
    {
        unique_objects_array.push_back(_obj);
    }
    

}

float Scene::sceneSDF(Vec2 pos)
{
    float min_dist = unique_objects_array.at(0)->signedDistFunc(pos);
    for(auto& obj: unique_objects_array)
    {
        float dist = obj->signedDistFunc(pos);

        if (min_dist > dist)
        {
            min_dist = dist;
        }
        
    }

    return min_dist;
}

void Scene::drawScene()
{
    //setlinestyle(0,0,2);
    for (auto& obj : unique_objects_array)
    {
        obj->draw();
        //char _tempI[5];
        //sprintf(_tempI, "%d", i);
        //outtextxy(obj->getX(),obj->getY(), (char *)_tempI);
    }

}

