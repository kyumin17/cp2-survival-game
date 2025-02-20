#pragma once
#include "../weapon.hpp"
#include "arrow.hpp"
#include "../../../image/weapon/bow_image.hpp"
#include "../../../image/weapon/arrow_image.hpp"
#include "../../../image/enemy/explosion_image.hpp"
#include "../../../image/enemy/slime_image.hpp"

class Bow: public Weapon {
    public:
        vector<Arrow*> arrow_arr; //화살 리스트
        Bow(int _x, int _y, Cell** _character);
        void attack(int direction);
        void drawArrows(Display& display);
        void moveArrows();
        void changeBowDirection(int direction, int player_x, int player_y);
        void checkCollision(vector<Enemy*>& enemy_arr, vector<Block*>& block_arr);
};