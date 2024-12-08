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

    int page = START;
    int score;
    while (page != QUIT) {
        switch (page) {
            case START:
                page = startPage(); //시작화면
                break;
            case PLAY:
                page = playPage(score); //게임 플레이 화면
                break;
            case END:
                page = endPage(score); //종료 화면
                break;
        }
        clear();
    }

    clear();
    endwin();
}