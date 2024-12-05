#include "enemy.hpp"

Enemy::Enemy(int _hp, int _str, int _x, int _y, int _width, int _height, Cell** _character)
: Component(_x, _y, _width, _height, _character) {
    hp = _hp;
    str = _str;
    isTracking = false;
}

void Enemy::move(int playerX, int playerY) {
    if (isTracking) {
        if (x < playerX) {
            x++;
        } else if (x > playerX) {
            x--;
        }

        if (y < playerY) {
            y++;
        } else if (y > playerY) {
            y--;
        }
    }
}