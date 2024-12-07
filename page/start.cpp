#include <ncurses.h>
#include <unistd.h>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30
#define ms 1000


int startPage() {
    char ch;
    int start = 1;
    while (1) {
        ch = getch();

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

        switch (ch) {
            case 'w':
                if(start != 1) {
                    start--;
                }
                break;
            case 's':
                if(start != 2) {
                    start++;
                }
                break;
        }

        switch (start) {
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
        
        mvprintw(7, 29, "  ________                          _________ __                 __   ");
        mvprintw(8, 29, " /  _____/_____    _____   ____    /   _____//  |______ ________/  |_ ");
        mvprintw(9, 29, "/   \\  ___\\__  \\  /     \\_/ __ \\   \\_____  \\   __\\__  \\_  __ \\   __\\");
        mvprintw(10, 29, "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/   /        \\|  |  / __ \\|  | \\/|  |  ");
        mvprintw(11, 29, " \\______  (____  /__|_|  /\\___  > /_______  /|__| (____  /__|   |__|  ");
        mvprintw(12, 29, "        \\/     \\/      \\/     \\/          \\/           \\/             ");

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

        mvprintw(25, 102, "            |   _   _");
        mvprintw(26, 102, "      . | . x .|.|-|.|");
        mvprintw(27, 102, "   |\\ ./.\\-/.\\-|.|.|.| ");
        mvprintw(28, 102, "~~~|.|_|.|_|.|.|.|_|.|~~~");

        mvprintw(25, 2, "            |   _   _");
        mvprintw(26, 2, "      . | . x .|.|-|.|");
        mvprintw(27, 2, "   |\\ ./.\\-/.\\-|.|.|.| ");
        mvprintw(28, 2, "~~~|.|_|.|_|.|.|.|_|.|~~~");


        mvprintw(26, 37, "  o  \\ o / _ o       __|   \\ /    |__      o _ \\ o /  o");
        mvprintw(27, 37, " /|\\   |    /\\  ___\\o  \\o   |   o/   o/__  /\\    |   /|\\");
        mvprintw(28, 37, " / \\  / \\  | \\ /)  |   ( \\ /o\\ / )   |  (\\ / |  / \\  / \\");

        refresh();

        if (ch == '\n') {
            if (start == 1) {
                clear();
                refresh();
                return playPage(); //back to game
            } else if (start == 2) {
                clear();
                refresh();
                return checkQuitStart();
            }
        }
    }
}