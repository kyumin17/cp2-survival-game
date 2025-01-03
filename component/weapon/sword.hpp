#pragma once
#include "weapon.hpp"
#include "../../image/weapon/sword-image.hpp"
#include "../../image/enemy/explosion-image.hpp"
#include "../../image/enemy/slime-image.hpp"

class Sword: public Weapon {
    public:
        int direction; //left or right
        Sword(int _x, int _y, Cell** _character);
        void attack(int direction, int playerX, vector<Enemy*>& enemyArr);
        void changeSwordDirection(int direction, int playerX);
};