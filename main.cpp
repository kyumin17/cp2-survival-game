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
    init_color(10, 82, 741, 192); //orange
    init_pair(10, 10, 9);

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