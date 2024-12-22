#include "page.hpp"
#include "../asset/ui.hpp"

bool checkQuitStagePage() {
    /*
    게임 도중 ESC 클릭 시 나오는 플레이 중단 확인 화면
    중단한다면 true를, 아니라면 false 반환
    */

    int ch;
    int option = 1; //resume, home 옵션

    while(1) {
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
            case 1: // resume 선택
                attron(COLOR_PAIR(COLOR_CYAN));
                mvprintw(16, 55, "> Resume");
                attroff(COLOR_PAIR(COLOR_CYAN));
                mvprintw(18, 55, "  Home");
                break;
            case 2: // 시작 화면 선택
                mvprintw(16, 55, "  Resume");
                attron(COLOR_PAIR(COLOR_RED));
                mvprintw(18, 55, "> Home");
                attroff(COLOR_PAIR(COLOR_RED));
                break;
        }

        // 엔터 누를 시 옵션 선택
        if (ch == '\n') {
            if (option == 1) {
                return false;
            } else if (option == 2) {
                return true; // 종료 (시작 화면)
            }
        }

        usleep(10000);
    }
}