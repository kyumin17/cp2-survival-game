#pragma once
#include <vector>
#include <queue>
#include "../component.hpp"
#include "../block/block.hpp"

enum Type { ENEMY1, ENEMY2, ENEMY2EXPLORE, ENEMY3, ENEMY4, ENEMY4DIV1, ENEMY4DIV2 };

using namespace std;

class Enemy: public Component {
    public:
        int direction;
        int type; //적 종류
        int dx;
        int dy;
        int survive_time;
        Enemy(int _type, int _x, int _y, int _width, int _height, Cell** _character);
        void moveX(int player_x, int player_y, vector<Block*>& block_arr);
        void moveY(int player_x, int player_y, vector<Block*>& block_arr);
        bool isBlock(vector<Block*>& block_arr);
};