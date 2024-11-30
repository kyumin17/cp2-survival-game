#pragma once
#include "component.hpp"
#include "player.hpp"

class Bullet: public Component {
    public:
        int str;
        int direction;
        Bullet(int _str, int _direction, int _x, int _y, int _width, int _height, Cell** _shape);
        void move();
        void attack();
        bool isTouched();
};