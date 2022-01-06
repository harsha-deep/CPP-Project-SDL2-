#include"Bullet.h"

using namespace std;

int Bullet::getx() {
    return des_rec.x;
}

int Bullet::getwidth() {
    return width;
}

void Bullet::update() {
    // making the bullet travel horizontally
    des_rec.x += velocity;
}

SDL_Rect Bullet::getBulletRect()
{
    return des_rec;
}