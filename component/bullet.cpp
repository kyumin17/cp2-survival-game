#include "bullet.hpp"

Bullet::Bullet(int _str, int _direction, int _x, int _y, int _width, int _height, Cell** _shape)
: Component(_x, _y, _width, _height, _shape) {
    str = _str;
    direction = _direction;
}

void Bullet::move() {
    switch (direction) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case BACK:
            y++;
            break;
        case FRONT:
            y--;
            break;
    }
}

int Bullet::isTouched(vector<Enemy*>& enemy) {
    for (size_t i = 0; i < enemy.size(); i++) {
        int ex = enemy[i] -> x;
        int ey = enemy[i] -> y;
        if (ex <= x && x <= ex + 2 && ey <= y && y <= ey + 2) {
            return i;
        }
    }
    return -1;
}

bool Bullet::isBlock(vector<Block*>& block) {
    for (size_t i = 0; i < block.size(); i++) {
        int bx = block[i] -> x;
        int by = block[i] -> y;
        for (int r = 0; r < block[i] -> height; r++) {
            for (int c = 0; c < block[i] -> width; c++) {
                if (x == c + bx && y == r + by) {
                    return true;
                }
            }
        }
    }

    return false;
}