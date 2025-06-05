#pragma once

#include <stdint.h>
#include "color.h"
#include "game_object.h"

struct Point : public GameObject
{
public:
    uint16_t x;
    uint16_t y;
    Color color;

    Point() {};
    Point(uint16_t x, uint16_t y, Color color);
    void display() override;
};
