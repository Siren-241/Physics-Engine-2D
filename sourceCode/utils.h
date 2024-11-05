#ifndef UTILS_H
#define UTILS_H

#include "Math2D.h"
#include "Rigidbody.h"


#include "glad/glad.h"
#include <GLFW/glfw3.h>

#define K_W 0x57
#define K_A 0x41
#define K_S 0x53
#define K_D 0x44


Vec2 abs(Vec2);
float max(float, float);
float min(float, float);

Vec2 rotmat2x2(Vec2, float);

int getmaxx(GLFWwindow* window);
int getmaxy(GLFWwindow* window);

int mousex(GLFWwindow* window);
int mousey(GLFWwindow* window);

void drawLine(GLFWwindow*, Vec2, Vec2);

#endif // UTILS_H