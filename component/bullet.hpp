#pragma once
#include <vector>
#include "component.hpp"
#include "block.hpp"
#include "enemy.hpp"

using namespace std;

class Bullet: public Component {
    public:
        int str;
        int direction;
        Bullet(int _str, int _direction, int _x, int _y, int _width, int _height, Cell** _shape);
        void move();
        int isTouched(vector<Enemy*>& enemy);
        bool isBlock(vector<Block*>& block);
};