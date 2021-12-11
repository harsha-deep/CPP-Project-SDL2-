#ifndef OBSTACLES
#define OBSTACLES
#include <vector>
#include "game_object.h"
#include "game.h"
class Obstacle : public game_object
{

private:
    static double delta_time;
    int angle;

public:
    Obstacle(const char *textureSheet, SDL_Renderer *ren, int x, int y) : game_object(textureSheet, ren, x, y)
    {
        object_Tex = TextureManager::LoadTexture(textureSheet, ren);
        xpos = x;
        ypos = Obstacle::generateRandomNumber(0, 335);
        angle = Obstacle::generateRandomNumber(-90, 90);
        src_rec.h = 272;
        src_rec.w = 101;
        src_rec.x = 0;
        src_rec.y = 0;

        des_rec.x = xpos;
        des_rec.y = ypos;
        des_rec.w = src_rec.w;
        des_rec.h = src_rec.h;
    }
    static int generateRandomNumber(int, int);
    void addObstacle(Obstacle *);
    void update(double, double);
    void render();
};
#endif // OBSTACLES