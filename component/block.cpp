#include "block.hpp"

Block::Block(int _x, int _y, int _width, int _height) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
}

void Block::draw() {
    //x, y to row, column
    int r = HEIGHT - y - height;
    int c = x;

    //draw in display
    for (int row = 0; row < std::min(height, HEIGHT - r); row++) {
        move(r + row, std::max(c, 0));
        for (int col = std::max(c, 0); col < std::min(width + c, WIDTH); col++) {
            addch(ACS_CKBOARD);
        }
    }
}