#pragma once
#include "weapon.hpp"

class Arrow: public Component  {
    public:
        int direction; //화살 나가는 방향
        Arrow(int _x, int _y, int _direction, Cell** _character);
        void move(); //방향에 따라 활 움직임
        int isHitEnemy(vector<Enemy*>& enemyArr); //적에 맞았는지 체크
        bool isHitBlock(vector<Block*>& blockArr); //블럭에 맞았는지 체크
};