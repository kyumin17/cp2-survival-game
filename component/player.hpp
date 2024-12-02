#pragma once
#include "component.hpp"
#include "bullet.hpp"
#include "block.hpp"

enum State { LEFT, RIGHT, BACK, FRONT, ATTACK };

class Player: public Component {
    public:
        int hp;
        int state;
        Cell** image;
        Player(int _hp, int _x, int _y, int _width, int _height, Cell** _character);
        void move(int direction, Enemy* enemy[], int& enemyNum, Block* block[], int& blockNum, PlayerCharacter playerCharacter);
        void attack(Bullet* bullet[], int& bulletNum);
        bool isTouch(Enemy* enemy[], int& enemyNum);
        bool isBlock(Block* block[], int& blockNum, int direction);
};