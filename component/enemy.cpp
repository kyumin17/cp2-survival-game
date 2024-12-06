#include "enemy.hpp"
#define pii pair<int,int>

Enemy::Enemy(int _hp, int _str, int _x, int _y, int _width, int _height, Cell** _character)
: Component(_x, _y, _width, _height, _character) {
    hp = _hp;
    str = _str;
    isTracking = false;
    direction = -1;
}

void Enemy::move(int playerX, int playerY, vector<Block*>& blockArr) {
    /*
    적이 플레이어 방향으로 움직임
    */
    dx = 0;
    dy = 0;
    if (isTracking) {
        if (y < playerY) {
            direction = BACK;
            dy = 1;
        } else if (y > playerY) {
            direction = FRONT;
            dy = -1;
        }

        if (x < playerX) {
            direction = RIGHT;
            dx = 1;
        } else if (x > playerX) {
            direction = LEFT;
            dx = -1;
        }

        x += dx;
        y += dy;
    }
}

bool Enemy::isBlock(vector<Block*>& blockArr) {
    /*
    적과 block이 만날 때에 true 반환
    */
    for (size_t i = 0; i < blockArr.size(); i++) {
        int bx = blockArr[i] -> x;
        int by = blockArr[i] -> y;
        int bh = blockArr[i] -> height;
        int bw = bh * 2;
        
        if (y <= by + bh - 1 && by <= y + height - 1 && x <= bx + bw - 1 && bx <= x + width - 1) {
            return true;
        }
    }
    
    return false;
}