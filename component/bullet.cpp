#include "bullet.hpp"

Bullet::Bullet(int _str, int _direction, int _x, int _y, int _width, int _height, Cell** _shape)
: Component(_x, _y, _width, _height, _shape) {
    str = _str;
    direction = _direction;
}

void Bullet::move() {
    while (x < WIDTH - 1) x++;
}

void Bullet::attack() {

}

bool Bullet::isTouched() {
    return false;
}