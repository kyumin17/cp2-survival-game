#pragma once
#include <ncurses.h>
#include "../etc/display.hpp"

class Component {
    public:
        int x;
        int y;
        int width;
        int height;
        Cell** character;
        
        Component(int _x, int _y, int _width, int _height, Cell** _character);
        void changeCharacter(Cell** newCharacter); //change character to newCharacter
        void draw(Display* display); //draw image in display
        bool isEndOfDisplay();
};