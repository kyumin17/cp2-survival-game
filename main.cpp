#include "./page/page.hpp"
#include <ncurses.h>

int main() {
    // 초기 세팅
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	cbreak();
	start_color();
    init_color(9, 100, 100, 100); //dark grey
    init_color(10, 82, 741, 192); //green
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(10, 10, 9);
    init_pair(11, COLOR_WHITE, 9);

    int page = START; // 페이지 종류
    int score; // 점수
    int maxScore = 0; // 최대 점수
    while (page != QUIT) {
        switch (page) {
            case START:
                page = startPage(); //시작화면
                break;
            case PLAY:
                page = playPage(score); //게임 플레이 화면
                break;
            case END:
                page = endPage(score, maxScore); //종료 화면
                break;
        }
        clear();
    }

    clear();
    endwin();
}