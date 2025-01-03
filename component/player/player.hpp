#pragma once
#include <vector>
#include <cmath>
#include "../component.hpp"
#include "../block/block.hpp"
#include "../enemy/enemy.hpp"
#include "../../image/player/player-image.hpp"

using namespace std;

class Player: public Component {
    public:
        int direction;
        Player(int _x, int _y, int _width, int _height, Cell** _character);
        void move(int input, vector<Enemy*>& enemyArr, vector<Block*>& blockArr);
        bool isDamaged(vector<Enemy*>& enemyArr); //적과 닿았는지 판단
        bool isBlock(vector<Block*>& blockArr, int input, bool& end); //장애물이 있는지 판단
};