#pragma once
#include <vector>
#include <cmath>
#include "component.hpp"
#include "weapon.hpp"
#include "block.hpp"

using namespace std;

class Player: public Component {
    public:
        int hp;
        int direction;
        Player(int _x, int _y, int _width, int _height, Cell** _character);
        void move(int input, vector<Enemy*>& enemyArr, vector<Block*>& blockArr, vector<Weapon*>& weaponArr, PlayerCharacter playerCharacter);
        void attack(vector<Weapon*>& weaponArr);
        bool isTouch(vector<Enemy*>& enemyArr);
        bool isBlock(vector<Block*>& blockArr, int input);
};