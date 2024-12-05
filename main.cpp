#include "./page/page.hpp"
#include <ncurses.h>

int main() {
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	cbreak();
	start_color();
    init_color(9, 100, 100, 100); //dark grey

    while (startPage()) {
        do {
            clear();
            playPage(); //게임 플레이
            clear();
        } while(endPage());
    }

    clear();

    endwin();
}