#include "bullet.hpp"

Bullet::Bullet(int _str, int _direction, int _x, int _y, int _width, int _height, Cell** _shape)
: Component(_x, _y, _width, _height, _shape) {
    str = _str;
    direction = _direction;
}

void Bullet::move() {
    x++;
}

void Bullet::attack() {

}

bool Bullet::isTouched() {

}

bool Bullet::isEndOfDisplay() {
    if (x <= 0 || x >= HEIGHT - 1 || y <= 0 || y >= WIDTH - 1) {
        return 1;
    } else {
        return 0;
    }
} 