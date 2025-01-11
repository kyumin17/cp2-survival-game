#include "component.hpp"

Component::Component(int _x, int _y, int _width, int _height, Cell** _character) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;

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

void Component::changeCharacter(Cell** _character, int _width, int _height) {
    /*
    이미지 변경
    */

    width = _width;
    height = _height;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            character[row][col] = _character[row][col];
        }
    }
}

void Component::draw(Display& display) {
    /*
    화면에 컴포넌트 그림
    */

    int r = HEIGHT - y - height;
    int c = x;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (character[row][col].value == ' ') { //빈 칸일 경우 그리지 않음
                continue;
            }

            int nr = row + r;
            int nc = col + c;
            if (0 <= nr && nr < HEIGHT && 0 <= nc && nc < WIDTH) { //화면 밖으로 나갈 시 출력X
                display.screen[row + r][col + c].value = character[row][col].value;
                display.screen[row + r][col + c].color = character[row][col].color;
            }
        }
    }
}