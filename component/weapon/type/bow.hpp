#pragma once
#include "../weapon.hpp"
#include "arrow.hpp"
#include "../../../image/weapon/bow_image.hpp"
#include "../../../image/weapon/arrow_image.hpp"
#include "../../../image/enemy/explosion_image.hpp"
#include "../../../image/enemy/slime_image.hpp"

class Bow: public Weapon {
    public:
        vector<Arrow*> arrowArr; //화살 리스트
        Bow(int _x, int _y, Cell** _character);
        void attack(int direction);
        void drawArrows(Display* display);
        void moveArrows();
        void changeBowDirection(int direction, int playerX, int playerY);
        void checkCollision(vector<Enemy*>& enemyArr, vector<Block*>& blockArr);
};