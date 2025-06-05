#pragma once

// To ensure all child classes also include the necessary gl functions for rendering
#include <GL/glut.h>

struct GameObject
{
public:
    virtual void display() = 0;
};
