#pragma once
#include <ncurses.h>
#define WIDTH 130
#define HEIGHT 30

typedef struct {
    char value;
    int color;
} Cell;

class Display {
    public:
        Cell** screen;
        Display();
        void printDisplay(); //화면 출력
        void clearDisplay(); //화면 초기화
};