#include "block.hpp"

Block::Block(int _x, int _y, int _height, bool _is_attack) {
    x = _x;
    y = _y;
    height = _height;
    is_attack = _is_attack;
}

void Block::draw() {
    /*
    블럭 출력
    플레이어가 닿으면 죽는 블럭의 경우 초록색으로 표시하고, 그렇지 않은 경우 흰색으로 표시
    */

    int r = HEIGHT - y - height;
    int c = x;

    /*화면 밖 넘어갈 경우 출력 X*/
    if ((x + height < 0 || x >= WIDTH) && (y + height < 0 || y >= HEIGHT)) {
        return;
    }

    /*화면 안의 블럭 영역만 출력*/
    if (is_attack) attron(COLOR_PAIR(10)); //피해 입힐 시 초록색
    for (int row = std::max(r, 0); row < std::min(r + height, HEIGHT); row++) {
        for (int col = std::max(c, 0); col < std::min(c + 2 * height, WIDTH); col++) {
            mvaddch(row, col, ACS_CKBOARD);
        }
    }
    if (is_attack) attroff(COLOR_PAIR(10));
}

bool Block::isOverlap(int cx, int cy, int cw, int ch) {
    /*
    다른 컴포넌트와 겹치는지 확인
    */

    if (x <= cx + cw - 1 && cx <= x + height * 2 - 1 && y <= cy + ch - 1 && cy <= y + height - 1) {
        return true;
    } else {
        return false;
    }
}