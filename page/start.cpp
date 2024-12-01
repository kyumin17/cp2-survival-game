#include <ncurses.h>
#include <unistd.h>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30
#define ms 1000


int startPage() {
    char ch;
    while (1) {
        ch = getch();

        for (int x = 0; x < WIDTH; x++) {
            mvprintw(0, x, "-");
            mvprintw( HEIGHT - 1, x, "-");
        }
        for(int y = 0; y < HEIGHT; y++) {
            mvprintw(y, 0, "|");
            mvprintw(y, WIDTH - 1, "|");
        }
        
        mvprintw(7, 29, "  ________                          _________ __                 __   ");
        mvprintw(8, 29, " /  _____/_____    _____   ____    /   _____//  |______ ________/  |_ ");
        mvprintw(9, 29, "/   \\  ___\\__  \\  /     \\_/ __ \\   \\_____  \\   __\\__  \\_  __ \\   __\\");
        mvprintw(10, 29, "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/   /        \\|  |  / __ \\|  | \\/|  |  ");
        mvprintw(11, 29, " \\______  (____  /__|_|  /\\___  > /_______  /|__| (____  /__|   |__|  ");
        mvprintw(12, 29, "        \\/     \\/      \\/     \\/          \\/           \\/             ");

        mvprintw(15, 49, "> Press Enter to start");
        mvprintw(17, 49, "> Press q to quit");

        mvprintw(22, 50, "W: jump        S: down");
        mvprintw(23, 50, "A: left        D: right");
        
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

        mvprintw(17, 90, "        ~+");
        mvprintw(18, 90, "                 *       +");
        mvprintw(19, 90, "           '                  |");
        mvprintw(20, 90, "       ()    .-.,=\"''\"=.    - o -");
        mvprintw(21, 90, "             '=/_       \\     |");
        mvprintw(22, 90, "          *   |  '=._    |");
        mvprintw(23, 90, "               \\     `=./`,        '");
        mvprintw(24, 90, "            .   '=.__.=' `='      *");
        mvprintw(25, 90, "    +                         +");
        mvprintw(26, 90, "        O      *        '       .");

        mvprintw(26, 37, "  o  \\ o / _ o       __|   \\ /    |__      o _ \\ o /  o");
        mvprintw(27, 37, " /|\\   |    /\\  ___\\o  \\o   |   o/   o/__  /\\    |   /|\\");
        mvprintw(28, 37, " / \\  / \\  | \\ /)  |   ( \\ /o\\ / )   |  (\\ / |  / \\  / \\");

        refresh();

        if (ch == '\n') {
            return 1; //play game
        } else if (ch == 'q') {
            if (checkQuitPage()) {
                return 0; //end game
            } else {
                return 1; //back to game
            }
        }
    }
}