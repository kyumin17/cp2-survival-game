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
    for (int row = 0; row < height; row++) {
        move(r + row, c);
        for (int col = 0; col < width; col++) {
            addch(ACS_CKBOARD);
        }
    }
}