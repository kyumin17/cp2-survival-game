#include "option.hpp"

int getOption(int ch, int option) {
    if (ch == KEY_UP || ch == 'w') {
        return 1;
    } else if (ch == KEY_DOWN || ch == 's') {
        return 2;
    }
    
    return option;
}

void drawOptionDisplay(int option, string str1, string str2, int y_coord) {
    if (option == 1) {
        attron(COLOR_PAIR(COLOR_CYAN));
        mvprintw(14 + y_coord, 56, ("> " + str1).c_str());
        attroff(COLOR_PAIR(COLOR_CYAN));
        mvprintw(16 + y_coord, 56, ("  " + str2).c_str());
    } else {
        mvprintw(14 + y_coord, 56, ("  " + str1).c_str());
        attron(COLOR_PAIR(COLOR_RED));
        mvprintw(16 + y_coord, 56, ("> " + str2).c_str());
        attroff(COLOR_PAIR(COLOR_RED));
    }
}