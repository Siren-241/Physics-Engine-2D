#ifndef UTILS_H
#define UTILS_H

#include "Math2D.h"
#include "Rigidbody.h"

Vec2 abs(Vec2);
float max(float, float);
float min(float, float);

Vec2 rotmat2x2(Vec2, float);

//Rewrite this shat
void findNormal(Rigidbody* , Rigidbody* , Vec2* , float*);


#endif // UTILS_H