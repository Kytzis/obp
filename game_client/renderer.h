#pragma once

#include <GL/glut.h>
#include <stdint.h>
#include "game_object.h"

struct Renderer
{
private:
    uint8_t layer_count;
    uint16_t entity_count_per_layer;
    GameObject** entities;

public:
    //TODO: Remove. I hate this empty one, its here because of glut fuckery
    Renderer() {};
    Renderer(int argc, char** argv, uint8_t layer_count, uint16_t entity_count_per_layer);
    ~Renderer();
    void updateScreen();
    void addEntity(GameObject* entity, uint8_t layer, uint16_t position);
};
