#pragma once
#include <ncurses.h>
#include <algorithm>
#include <cmath>
#include "component.hpp"

class Block {
    public:
        int x;
        int y;
        int height;
        Block(int _x, int _y, int _height);
        void draw();
        bool isOverlap(int cx, int cy);
};