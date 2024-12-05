#include "block.hpp"

Block::Block(int _x, int _y, int _height) {
    x = _x;
    y = _y;
    height = _height;
}

void Block::draw() {
    //x, y to row, column
    int r = HEIGHT - y - height;
    int c = x;

    if ((x + height < 0 || x >= WIDTH) && (y + height < 0 || y >= HEIGHT)) {
        return;
    }

    //draw in display
    for (int row = std::max(r, 0); row < std::min(r + height, HEIGHT - 1); row++) {
        for (int col = std::max(c, 0); col < std::min(c + 2 * height, WIDTH - 1); col++) {
            mvaddch(row, col, ACS_CKBOARD);
        }
    }
}

bool Block::isOverlap(int cx, int cy) {
    if (x <= cx + 2 && cx <= x + height * 2 - 1 && y <= cy + 2 && cy <= y + height - 1) {
        return true;
    } else {
        return false;
    }
}