#include "page.hpp"
#include "../asset/ui.hpp"

bool checkQuitGamePage() {
    /*
    시작 화면에서 quit 선택 시 나오는 종료 확인 창
    종료한다면 true를, 아니라면 false 반환
    */

    int ch;
    int option = 1; // cancel, quit 옵션

    while(1) {
        ch = getch();
        
        // 테두리 출력
        drawBorder();

        // 확인 문구 출력
        drawQuitConfirmText();

        // 키 입력에 따라 옵션 변경
        switch (ch) {
            case KEY_UP:
            case 'w': // 위로 이동
                if (option != 1) {
                    option--;
                } 
                break;
            case KEY_DOWN:
            case 's': // 아래로 이동
                if (option != 3) {
                    option++;
                }
                break;
        }

        // 선택 옵션에 따라 디스플레이 변경
        switch (option) {
            case 1: // 취소 선택
                attron(COLOR_PAIR(COLOR_CYAN));
                mvprintw(20, 55, "> Cancel");
                attroff(COLOR_PAIR(COLOR_CYAN));
                mvprintw(22, 55, "  Quit");
                break;
            case 2: // 게임 종료 선택
                mvprintw(20, 55, "  Cancel");
                attron(COLOR_PAIR(COLOR_RED));
                mvprintw(22, 55, "> Quit");
                attroff(COLOR_PAIR(COLOR_RED));
                break;
        }

        // 엔터 누를 시 옵션 선택
        if (ch == '\n') {
            if (option == 1) {
                return false; // 돌아감
            } else if (option == 2) {
                return true; // 종료
            }
        }

        usleep(10000);
    }
}