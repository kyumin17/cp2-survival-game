#pragma once
#include <vector>
#include <cmath>
#include "component.hpp"
#include "block.hpp"
#include "enemy.hpp"

using namespace std;

class Player: public Component {
    public:
        int hp;
        int direction;
        Player(int _x, int _y, int _width, int _height, Cell** _character);
        void move(int input, vector<Enemy*>& enemyArr, vector<Block*>& blockArr, PlayerCharacter playerCharacter);
        bool isTouch(vector<Enemy*>& enemyArr);
        bool isBlock(vector<Block*>& blockArr, int input, bool& end);
};