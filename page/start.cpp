#include "page.hpp"

int startPage() {
    char ch;
    while (1) {
        ch = getch();

        mvprintw(0, 0, "this is start page");
        
        if (ch == '\n') {
            return 1; //play game
        } else if (ch == 'q') {
            if (checkQuitPage()) {
                return 0; //end game
            } else {
                return 1; //back to game
            }
        }
    }
}