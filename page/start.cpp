#include "page.hpp"
#include "../manage/ui.hpp"

int startPage() {
    /*
    게임 시작 화면
    start 선택 시 PLAY 반환, quit 선택 시 QUIT 반환
    */
    
    int ch;
    int option = 1; //start, quit 옵션

    while (1) {
        ch = getch();

        // 테두리 출력
        drawBorder();

        // 키 입력에 따라 옵션 변경
        switch (ch) {
            case KEY_UP:
            case 'w': // 위로 이동
                if(option != 1) {
                    option--;
                }
                break;
            case KEY_DOWN:
            case 's': // 아래로 이동
                if(option != 2) {
                    option++;
                }
                break;
        }

        // 선택 옵션에 따라 디스플레이 변경
        switch (option) {
            case 1: // 게임 시작 선택
                attron(COLOR_PAIR(COLOR_CYAN));
                mvprintw(17, 56, "> Start Game");
                attroff(COLOR_PAIR(COLOR_CYAN));
                mvprintw(19, 56, "  Quit");
                break;
            case 2: // 게임 종료 선택
                mvprintw(17, 56, "  Start Game");
                attron(COLOR_PAIR(COLOR_RED));
                mvprintw(19, 56, "> Quit");
                attroff(COLOR_PAIR(COLOR_RED));
                break;
        }
        
        // 시작 화면
        drawTitle();

        // 엔터 누를 시 옵션 선택
        if (ch == '\n') {
            if (option == 1) {
                return PLAY; // 게임 시작
            } else if (option == 2) {
                clear();
                if (checkQuitGamePage()) {
                    return QUIT; // 게임 종료
                }
                clear();
            }
        }

        refresh();
    }
}