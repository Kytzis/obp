#include "point.h"

Point::Point(uint16_t x, uint16_t y, Color color)
{
    this->x = x;
    this->y = y;
    this->color = color;
}

void Point::display()
{
    glColor3f(color.red, color.green, color.blue);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
