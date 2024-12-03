#pragma once
#include <vector>
#include "component.hpp"
#include "bullet.hpp"
#include "block.hpp"

using namespace std;

class Player: public Component {
    public:
        int hp;
        int direction;
        Player(int _x, int _y, int _width, int _height, Cell** _character);
        void move(int input, vector<Enemy*>& enemy, vector<Block*>& block, vector<Bullet*>& bullet, PlayerCharacter playerCharacter);
        void attack(vector<Bullet*>& bullet);
        bool isTouch(vector<Enemy*>& enemy);
        bool isBlock(vector<Block*>& block, int input);
};