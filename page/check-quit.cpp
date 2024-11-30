#include "page.hpp"

int checkQuitPage() {
    char ch;
    while(1) {
        ch = getch();
        mvprintw(0, 0, "Are you sure to quit game?\n");

        if (ch == '\n') {
            return 0; //back to game
        } else if (ch == 'q') {
            return 1; //quit
        }
    }
}