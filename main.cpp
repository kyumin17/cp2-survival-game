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

    int stage;
    if (startPage()) {
        clear();
        stage = selectStagePage();
    }

    clear();
    switch (stage) {
        case 1:
            stage1Page();
            break;
        case 2:
            stage2Page();
            break;
        case 3:
            stage3Page();
            break;
    }

    endwin();
}