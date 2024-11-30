#pragma once
#include "component.hpp"

enum State { LEFT, RIGHT, BACK, FRONT, ATTACK };

class Player: public Component {
    public:
        int hp;
        Cell** image;
        bool state[5];
        int stateDuration[5];
        Player(int _hp, int _x, int _y, int _width, int _height, Cell** _character);
};