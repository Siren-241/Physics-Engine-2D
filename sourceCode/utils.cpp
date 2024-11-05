#include "utils.h"


Vec2 abs(Vec2 v)
{
    Vec2 temp = v;
    if(temp.getX()<0)
        temp.setTo(Vec2(temp.getX()*-1, temp.getY()* 1));

    if(temp.getY()<0)
        temp.setTo(Vec2(temp.getX()* 1, temp.getY()*-1));
        
    return temp;
}

Vec2 rotmat2x2(Vec2 p, float th)
{
    return Vec2(p.getX()*cos(th) - p.getY()*sin(th),
                p.getX()*sin(th) + p.getY()*cos(th));
}


float max(float a, float b)
{
    if(a>b)return a;
    else if(b>a)return b;
    else return a;
}
float min(float a, float b)
{
    if(a<b)return a;
    else if(b<a)return b;
    else return a;
}

int getmaxx(GLFWwindow* window)
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    return width;
}

int getmaxy(GLFWwindow* window)
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    return height;
}

int mousex(GLFWwindow* window)
{
    double xpos, ypos;
    //getting cursor position
    glfwGetCursorPos(window, &xpos, &ypos);

    return (int)xpos;
}

int mousey(GLFWwindow* window)
{
    double xpos, ypos;
    //getting cursor position
    glfwGetCursorPos(window, &xpos, &ypos);

    return (int)ypos;
}

void drawLine(GLFWwindow* window, Vec2 p1, Vec2 p2)
{

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    float x1 = 2 * (p1.getX()/ width )  -1;
    float y1 = 2 * (p1.getY()/ height)  -1;
    float x2 = 2 * (p2.getX()/ width )  -1;
    float y2 = 2 * (p2.getY()/ height)  -1;

    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_LINES);
    printf("drawing lines!!!!!!!!!!!\n");
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

//rough aprroximation: Redo required
/* void findNormal(Rigidbody *r1, Rigidbody *r2, Vec2 *normal, float *dist)
{
    *normal = r2->getPos() - r1->getPos();
    *dist = (r2->signedDistFunc(r1->getPos())+r1->signedDistFunc(r2->getPos())-normal->mag());
    normal->normalise();
    
}
 */
