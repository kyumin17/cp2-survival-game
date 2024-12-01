#include <ncurses.h>
#include <unistd.h>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30
#define ms 1000

int checkQuitPage() {
    char ch;
    while(1) {
        ch = getch();
        mvprintw(1, 1, "Are you sure to quit game?\n");

        for (int x = 0; x < WIDTH; x++) {
            mvprintw(0, x, "-");
            mvprintw( HEIGHT - 1, x, "-");
        }
        for(int y = 0; y < HEIGHT; y++) {
            mvprintw(y, 0, "|");
            mvprintw(y, WIDTH - 1, "|");
        }
        
        if (ch == '\n') {
            return 0; //back to game
        } else if (ch == 'q') {
            return 1; //quit
        }
    }
}