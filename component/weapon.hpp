#pragma once
#include <vector>
#include <cmath>
#include "component.hpp"
#include "block.hpp"
#include "enemy.hpp"

using namespace std;

class Weapon: public Component {
    public:
        int str;
        int direction;
        Weapon(int _str, int _direction, int _x, int _y, int _width, int _height, Cell** _shape);
        void move();
        int isTouched(vector<Enemy*>& enemyArr);
        bool isBlock(vector<Block*>& blockArr);
};