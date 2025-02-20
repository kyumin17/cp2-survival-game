#include "arrow.hpp"

Arrow::Arrow(int _x, int _y, int _direction, Cell** _character)
: Component(_x, _y, 1, 1, _character) {
    direction = _direction;
}

int Arrow::isHitEnemy(vector<Enemy*>& enemy_arr) {
    /*
    화살과 적이 부딪혔다면 적의 인덱스를 반환
    부딪히지 않았다면 -1 반환
    */
   
    for (size_t i = 0; i < enemy_arr.size(); i++) {
        int ex = enemy_arr[i] -> x;
        int ey = enemy_arr[i] -> y;
        if (ex <= x && x <= ex + 2 && ey <= y && y <= ey + 2) { //overlap 체크
            return i;
        }
    }
    return -1;
}

void Arrow::move() {
    /*
    나가는 방향에 따라 화살 움직임
    */

    switch(direction) {
        case LEFT:
            x -= 2;
            break;
        case RIGHT:
            x += 2;
            break;
        case BACK:
            y++;
            break;
        case FRONT:
            y--;
            break;
    }
}

bool Arrow::isHitBlock(vector<Block*>& block_arr) {
    /*
    블럭과 만났는지 체크
    */

    for (size_t i = 0; i < block_arr.size(); i++) {
        int bx = block_arr[i] -> x;
        int by = block_arr[i] -> y;
        int bh = block_arr[i] -> height;

        for (int r = 0; r < bh; r++) {
            for (int c = 0; c < bh * 2; c++) {
                if (x == c + bx && y == r + by) {
                    return true;
                }
            }
        }
    }

    return false;
}