#ifndef OBSTACLES
#define OBSTACLES
#include <vector>
#include "TextureManager.h"
#include "game_object.h"
#include "game.h"
class Obstacle : public game_object
{

private:
    static double delta_time;
    int angle;

public:
    Obstacle(const char *textureSheet, SDL_Renderer *ren, int x, int y, int img_Width, int img_Height) : game_object(textureSheet, ren, x, y)
    {
        object_Tex = TextureManager::LoadTexture(textureSheet);
        xpos = x;
        ypos = Obstacle::generateRandomNumber(0, 600 - img_Height);
        angle = Obstacle::generateRandomNumber(-90, 90);
        src_rec.w = img_Width;
        src_rec.h = img_Height;
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