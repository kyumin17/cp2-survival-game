#include "weapon.hpp"

Weapon::Weapon(int _str, int _direction, int _x, int _y, int _width, int _height, Cell** _shape)
: Component(_x, _y, _width, _height, _shape) {
    str = _str;
    direction = _direction;
}

void Weapon::move() {
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

int Weapon::isTouched(vector<Enemy*>& enemyArr) {
    for (size_t i = 0; i < enemyArr.size(); i++) {
        int ex = enemyArr[i] -> x;
        int ey = enemyArr[i] -> y;
        if (ex <= x && x <= ex + 2 && ey <= y && y <= ey + 2) {
            return i;
        }
    }
    return -1;
}

bool Weapon::isBlock(vector<Block*>& blockArr) {
    for (size_t i = 0; i < blockArr.size(); i++) {
        int bx = blockArr[i] -> x;
        int by = blockArr[i] -> y;
        int bh = blockArr[i] -> height;

        for (int r = 0; r < bh; r++) {
            for (int c = 0; c < bh * 2; c++) {
                if (x == c + bx && y == r + by) {
                    return true;
                }
            }
        }
    }

    return false;
}