#pragma once

struct Color
{
public:
    float red;
    float green;
    float blue;

    Color() {};
    Color(float red, float green, float blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }
};
