#pragma once
#include <vector>
#include <cmath>
#include "component.hpp"
#include "block.hpp"
#include "enemy.hpp"

using namespace std;

class Weapon: public Component {
    public:
        int attackTime; //공격 유지 시간 측정
        int cooldown; //쿨타임
        Weapon(int _x, int _y, int _width, int _height, int _cooldown, Cell** _character);
};

class Arrow: public Component  {
    public:
        int direction; //화살 나가는 방향
        Arrow(int _x, int _y, int _direction, Cell** _character);
        void move();
        int isEnemy(vector<Enemy*>& enemyArr);
        bool isBlock(vector<Block*>& blockArr);
};

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

class Pole: public Weapon {
    public:
        Pole(int _x, int _y, Cell** _character);
};

class Disk: public Weapon {
    public:
        Disk(int _x, int _y, Cell** _character);
};