#include "renderer.h"

Renderer::Renderer(int argc, char** argv, uint8_t layer_count, uint16_t entity_count_per_layer)
{
    this->layer_count = layer_count;
    this->entity_count_per_layer = entity_count_per_layer;
    this->entities = new GameObject*[layer_count * entity_count_per_layer];

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    // giving window size in X- and Y- direction
    //TODO: Needs to be based on actual screen res
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    
    // Giving name to window
    glutCreateWindow("OBP");

    // Default color is a nice grey
    glClearColor(0.2, 0.2, 0.2, 1.0);
    
    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    
    // Set window size
    //TODO: Needs to be based on actual screen res
    gluOrtho2D(0, 1920, 0, 1080);
}

Renderer::~Renderer()
{
    delete[] entities;
}

void Renderer::updateScreen()
{
    //TODO: Clears and redraws entire screen. Yucky.
    glClear(GL_COLOR_BUFFER_BIT);

    for (uint8_t layer = 0; layer < layer_count; layer++)
    {
        for (uint16_t entity = 0; entity < entity_count_per_layer; entity++)
        {
            if (entities[layer*entity_count_per_layer + entity] == nullptr) continue;
            entities[layer*entity_count_per_layer + entity]->display();
        }
    }

    glFlush();
}

void Renderer::addEntity(GameObject* entity, uint8_t layer, uint16_t position)
{
    entities[layer*entity_count_per_layer + position] = entity;
}
