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
        bool isAttack; //true일 경우 닿으면 플레이어가 죽음
        Block(int _x, int _y, int _height, bool _isAttack);
        void draw();
        bool isOverlap(int cx, int cy, int cw, int ch);
};