#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30

int startPage() {
    /*
    게임 시작 화면
    start 선택 시 게임 시작, quit 선택 시 게임 종료
    */
    
    int ch;
    int option = 1; //start, quit 옵션

    while (1) {
        ch = getch();

        /*테두리 출력*/
        for (int x = 0; x < WIDTH; x += 2) {
            mvprintw(0, x, "-=");
            mvprintw( HEIGHT - 1, x, "-=");
        }
        for(int y = 0; y < HEIGHT; y += 2) {
            mvprintw(y, 0, "|");
            mvprintw(y, WIDTH - 1, "|");
        }
        for(int y = 0; y < HEIGHT; y += 3) {
            mvprintw(y, 0, ":");
            mvprintw(y, WIDTH - 1, ":");
        }

        /*색 설정*/
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);

        /*키 입력에 따라 옵션 변경*/
        switch (ch) {
            case KEY_UP:
                if(option != 1) {
                    option--;
                }
                break;
            case KEY_DOWN:
                if(option != 2) {
                    option++;
                }
                break;
        }

        /*키 입력에 따라 옵션 focus*/
        switch (option) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(17, 56.5, "> Start Game");
                attroff(COLOR_PAIR(1));
                mvprintw(19, 56.5, "  Quit");
                break;
            case 2:
                mvprintw(17, 56.5, "  Start Game");
                attron(COLOR_PAIR(2));
                mvprintw(19, 56.5, "> Quit");
                attroff(COLOR_PAIR(2));
                break;
        }
        
        /*시작 화면 출력*/
        mvprintw(7, 29, "                     _     _                                    ");
        mvprintw(8, 29, "  _______  _ __ ___ | |__ (_) ___    __ _  __ _ _ __ ___   ___  ");
        mvprintw(9, 29, " |_  / _ \\| '_ ` _ \\| '_ \\| |/ _ \\  / _` |/ _` | '_ ` _ \\ / _ \\ ");
        mvprintw(10, 29, "  / / (_) | | | | | | |_) | |  __/ | (_| | (_| | | | | | |  __/ ");
        mvprintw(11, 29, " /___\\___/|_| |_| |_|_.__/|_|\\___|  \\__, |\\__,_|_| |_| |_|\\___| ");
        mvprintw(12, 29, "                                    |___/                       ");

        mvprintw(22, 50, "W: jump        S: down");
        mvprintw(23, 50, "A: left        D: right");
        mvprintw(24, 50, "I: attack      ESC: pause");
        
        mvprintw(2, 1, "                 '");
        mvprintw(3, 1, "            *          .");
        mvprintw(4, 1, "                   *       '");
        mvprintw(5, 1, "              *                *");
        mvprintw(10, 1, "  *   '*");
        mvprintw(11, 1, "          *");
        mvprintw(12, 1, "               *");
        mvprintw(13, 1, "                       *");
        mvprintw(14, 1, "               *");
        mvprintw(15, 1, "                     *");

        mvprintw(26, 37, "  o  \\ o / _ o       __|   \\ /    |__      o _ \\ o /  o");
        mvprintw(27, 37, " /|\\   |    /\\  ___\\o  \\o   |   o/   o/__  /\\    |   /|\\");
        mvprintw(28, 37, " / \\  / \\  | \\ /)  |   ( \\ /o\\ / )   |  (\\ / |  / \\  / \\");

        refresh();

        /*엔터 누르면 옵션 활성화*/
        if (ch == '\n') {
            if (option == 1) {
                return PLAY;
            } else if (option == 2) {
                clear();
                if (checkQuitStart()) {
                    return QUIT;
                }
                clear();
            }
        }
    }
}