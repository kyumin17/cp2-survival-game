#include "enemy.hpp"

Enemy::Enemy(int _hp, int _str, int _x, int _y, int _width, int _height, Cell** _character)
: Component(_x, _y, _width, _height, _character) {
    hp = _hp;
    str = _str;
}

void Enemy::move(int playerX, int playerY) {
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