#include <GL/glut.h>
#include "color.h"
#include "point.h"
#include "renderer.h"

Renderer* renderer_ptr;

void update()
{
    renderer_ptr->updateScreen();
}

int main (int argc, char** argv)
{
    Renderer renderer(argc, argv, (uint8_t)1, (uint16_t)2000);
    renderer_ptr = &renderer;

    glutDisplayFunc(update);

    Point* points = new Point[1920];
    for (int i = 0; i < 1920; i++)
    {
        points[i].x = i;
        points[i].y = 100;
        points[i].color = Color(0.1, 0.2, 0.8);
        renderer.addEntity((GameObject*)&points[i], 0, i);
    }

    glutMainLoop();

    delete[] points;
}
