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
    move(0, 0);
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            Cell cell = screen[row][col];
            init_pair(cell.color, cell.color, 9);
            attron(COLOR_PAIR(cell.color));
            printw("%c", cell.value);
            attroff(COLOR_PAIR(cell.color));
        }
        printw("\n");
    }

    printBackgroud();
}

void Display::clearDisplay() {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            screen[row][col].value = ' ';
            screen[row][col].color = COLOR_WHITE;
        }
    }
}

void Display::printBackgroud() {
    move(0, 0);
    for (int row = 0; row < 12; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printw("%c", '#');
        }
        printw("\n");
    }

    move(27, 0);
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printw("%c", '#');
        }
        printw("\n");
    }
}