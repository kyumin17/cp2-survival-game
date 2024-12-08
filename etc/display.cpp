#include "display.hpp"

Display::Display() {
    screen = new Cell*[HEIGHT];
    for (int row = 0; row < HEIGHT; row++) {
        screen[row] = new Cell[WIDTH];
    }

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            screen[row][col].value = ' ';
            screen[row][col].color = COLOR_WHITE;
        }
    }
}

void Display::printDisplay() {
    /*
    screen에 입력된 대로 색상과 글자 출력
    */
   
    move(0, 0);
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            Cell cell = screen[row][col];
            init_pair(cell.color, cell.color, 9); //색 설정
            attron(COLOR_PAIR(cell.color));
            printw("%c", cell.value);
            attroff(COLOR_PAIR(cell.color));
        }
        printw("\n");
    }
}

void Display::clearDisplay() {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            screen[row][col].value = ' ';
            screen[row][col].color = COLOR_WHITE;
        }
    }
}