#pragma once
#include <ncurses.h>
#include "display/display.hpp"

enum Direction { LEFT, RIGHT, BACK, FRONT };

class Component {
    public:
        int x;
        int y;
        int width;
        int height;
        Cell** character;
        
        Component(int _x, int _y, int _width, int _height, Cell** _character);
        void changeCharacter(Cell** _character, int _width, int _height); //이미지 변경
        void draw(Display& display); //화면에 그리기
};