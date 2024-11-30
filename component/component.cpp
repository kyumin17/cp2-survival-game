#include "component.hpp"

Component::Component(int _x, int _y, int _width, int _height, Cell** _character) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;

    //memory allocation
    character = new Cell*[height];
    for (int row = 0; row < height; row++) {
        character[row] = new Cell[width];
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            character[row][col] = _character[row][col];
        }
    }
}

void Component::changeCharacter(Cell** newCharacter) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            character[row][col] = newCharacter[row][col];
        }
    }
}

void Component::draw(Display* display) {
    //x, y to row, column
    int r = HEIGHT - y - height;
    int c = x;

    //draw in display
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (character[row][col].value == ' ') continue;
            display -> screen[row + r][col + c].value = character[row][col].value;
            display -> screen[row + r][col + c].color = character[row][col].color;
        }
    }
}

bool Component::isEndOfDisplay() {
    if (x <= 0 || x >= HEIGHT - 1 || y <= 3 || y >= 20) {
        return 1;
    } else {
        return 0;
    }
} 