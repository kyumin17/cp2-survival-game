#pragma once
#include <vector>
#include <queue>
#include "component.hpp"
#include "block.hpp"

using namespace std;

class Enemy: public Component {
    public:
        int hp;
        int str;
        int direction;
        bool isTracking;
        int type;
        int dx;
        int dy;
        Enemy(int _type, int _hp, int _str, int _x, int _y, int _width, int _height, Cell** _character);
        void moveX(int playerX, int playerY, vector<Block*>& blockArr);
        void moveY(int playerX, int playerY, vector<Block*>& blockArr);
        bool isBlock(vector<Block*>& blockArr);
};