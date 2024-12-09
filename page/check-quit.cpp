#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30

bool checkQuitStart() {
    /*
    시작 화면에서 quit 선택 시 나오는 종료 확인 창
    종료한다면 true를, 아니라면 false 반환
    */

    int ch;
    int option = 1; //cancel, quit 옵션

    while(1) {
        ch = getch();
        
        /*테두리 출력*/
        for (int x = 0; x < WIDTH; x += 2) {
            mvprintw(0, x, "-=");
            mvprintw(HEIGHT - 1, x, "-=");
        }
        for(int y = 0; y < HEIGHT; y += 2) {
            mvprintw(y, 0, "|");
            mvprintw(y, WIDTH - 1, "|");
        }
        for(int y = 0; y < HEIGHT; y += 3) {
            mvprintw(y, 0, ":");
            mvprintw(y, WIDTH - 1, ":");
        }

        /*확인 메세지 출력*/
        mvprintw(5, 39, "    _                                              ");
        mvprintw(6, 39, "   /_\\  _ _ ___   _  _ ___ _  _   ____  _ _ _ ___  ");
        mvprintw(7, 39, "  / _ \\| '_/ -_) | || / _ \\ || | (_-< || | '_/ -_) ");
        mvprintw(8, 39, " /_/ \\_\\_| \\___|  \\_, \\___/\\_,_| /__/\\_,_|_| \\___| ");
        mvprintw(9, 39, "                  |__/                             ");
        mvprintw(10, 39, "                 | |_ ___                          ");
        mvprintw(11, 39, "            _ _  |  _/ _ \\             ___         ");
        mvprintw(12, 39, "  __ _ _  _(_) |_ \\__\\___/_ _ _ __  __|__ \\        ");
        mvprintw(13, 39, " / _` | || | |  _| / _` / _` | '  \\/ -_)/_/        ");
        mvprintw(14, 39, " \\__, |\\_,_|_|\\__| \\__, \\__,_|_|_|_\\___(_)         ");
        mvprintw(15, 39, "    |_|            |___/                           ");

        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);

        /*키 입력에 따라 옵션 조정*/
        switch (ch) {
            case KEY_UP:
            case 'w':
                if (option != 1) {
                    option--;
                } 
                break;
            case KEY_DOWN:
            case 's':
                if (option != 3) {
                    option++;
                }
                break;
        }

        /*키 입력에 따라 옵션 focus*/
        switch (option) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(20, 55, "> Cancel");
                attroff(COLOR_PAIR(1));
                mvprintw(22, 55, "  Quit");
                break;
            case 2:
                mvprintw(20, 55, "  Cancel");
                attron(COLOR_PAIR(2));
                mvprintw(22, 55, "> Quit");
                attroff(COLOR_PAIR(2));
                break;
        }

        /*엔터 누르면 선택*/
        if (ch == '\n') {
            if (option == 1) {
                return false; //돌아감
            } else if (option == 2) {
                return true; //종료
            }
        }

        usleep(10000);
    }
}


bool checkQuitStage() {
    /*
    게임 도중 ESC 클릭 시 나오는 플레이 중단 확인 화면
    중단한다면 true를, 아니라면 false 반환
    */

    int ch;
    int option = 1; //resume, home 옵션

    while(1) {
        ch = getch();

        /*테두리 출력*/
        for (int x = 0; x < WIDTH; x+=2) {
            mvprintw(0, x, "-=");
            mvprintw( HEIGHT - 1, x, "-=");
        }
        for(int y = 0; y < HEIGHT; y+=2) {
            mvprintw(y, 0, "|");
            mvprintw(y, WIDTH - 1, "|");
        }
        for(int y = 0; y < HEIGHT; y+=3) {
            mvprintw(y, 0, ":");
            mvprintw(y, WIDTH - 1, ":");
        }

        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);

        /*키 입력에 따라 옵션 조정*/
        switch (ch) {
            case KEY_UP:
            case 'w':
                if(option != 1) {
                    option--;
                }
                break;
            case KEY_DOWN:
            case 's':
                if(option != 2) {
                    option++;
                }
                break;
        }

        /*옵션 출력*/
        switch (option) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(16, 55, "> Resume");
                attroff(COLOR_PAIR(1));
                mvprintw(18, 55, "  Home");
                break;
            case 2:
                mvprintw(16, 55, "  Resume");
                attron(COLOR_PAIR(2));
                mvprintw(18, 55, "> Home");
                attroff(COLOR_PAIR(2));
                break;
        }

        /*엔터 누르면 선택*/
        if (ch == '\n') {
            if (option == 1) {
                return false; //돌아감
            } else if (option == 2) {
                return true; //종료
            }
        }

        usleep(10000);
    }
}