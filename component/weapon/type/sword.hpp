#pragma once
#include "../weapon.hpp"
#include "../../../image/weapon/sword_image.hpp"
#include "../../../image/enemy/explosion_image.hpp"
#include "../../../image/enemy/slime_image.hpp"

class Sword: public Weapon {
    public:
        int direction;
        Sword(int _x, int _y, Cell** _character);
        void attack(int direction, int playerX, vector<Enemy*>& enemyArr);
        void changeSwordDirection(int direction, int playerX);
};