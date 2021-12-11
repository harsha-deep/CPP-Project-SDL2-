#ifndef OBSTACLES
#define OBSTACLES
#include <vector>
#include "game_object.h"
#include "game.h"

class Obstacle : public game_object
{

private:
    static double delta_time;

public:
    Obstacle(const char *textureSheet, SDL_Renderer *ren, int x, int y) : game_object(textureSheet, ren, x, y)
    {
        object_Tex = TextureManager::LoadTexture(textureSheet, ren);
        xpos = x;
        ypos = y;
    }
    static int generateRandomNumber(int, int);
    void addObstacle(Obstacle *);
    void update(double, double);
    void render();
};
#endif