#include "enemy.hpp"

Enemy::Enemy(int _type, int _x, int _y, int _width, int _height, Cell** _character)
: Component(_x, _y, _width, _height, _character) {
    type = _type;
    direction = -1;
    survive_time = 0;
}

void Enemy::moveX(int player_x, int player_y, vector<Block*>& block_arr) {
    /*
    적이 플레이어 방향으로 움직임
    */
   
    dx = 0;
    if (x < player_x) {
        direction = RIGHT;
        dx = 1;
    } else if (x > player_x) {
        direction = LEFT;
        dx = -1;
    }

    x += dx;
}

void Enemy::moveY(int player_x, int player_y, vector<Block*>& block_arr) {
    /*
    적이 플레이어 방향으로 움직임
    */

    dy = 0;
    if (y < player_y) {
        direction = BACK;
        dy = 1;
    } else if (y > player_y) {
        direction = FRONT;
        dy = -1;
    }

    y += dy;
}

bool Enemy::isBlock(vector<Block*>& block_arr) {
    /*
    적과 block이 만날 때에 true 반환
    */

    for (size_t i = 0; i < block_arr.size(); i++) {
        int bx = block_arr[i] -> x;
        int by = block_arr[i] -> y;
        int bh = block_arr[i] -> height;
        int bw = bh * 2;
        
        if (y <= by + bh - 1 && by <= y + height - 1 && x <= bx + bw - 1 && bx <= x + width - 1) {
            return true;
        }
    }
    
    return false;
}