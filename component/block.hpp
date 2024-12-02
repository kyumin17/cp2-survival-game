#pragma once
#include <ncurses.h>
#include <algorithm>
#include "component.hpp"

class Block {
    public:
        int x;
        int y;
        int width;
        int height;
        Block(int _x, int _y, int _width, int _height);
        void draw();
};