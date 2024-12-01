#include <ncurses.h>
#include <unistd.h>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30
#define ms 1000

int selectStagePage() {
    char ch;
    while (1) {
        usleep(10 * ms);
        int selectStage = 1;

        for (int x = 0; x < WIDTH; x++) {
            mvprintw(0, x, "-");
            mvprintw( HEIGHT - 1, x, "-");
        }
        for(int y = 0; y < HEIGHT; y++) {
            mvprintw(y, 0, "|");
            mvprintw(y, WIDTH - 1, "|");
        }

        ch = getch();

        mvprintw(26, 37, "  o  \\ o / _ o       __|   \\ /    |__      o _ \\ o /  o");
        mvprintw(27, 37, " /|\\   |    /\\  ___\\o  \\o   |   o/   o/__  /\\    |   /|\\");
        mvprintw(28, 37, " / \\  / \\  | \\ /)  |   ( \\ /o\\ / )   |  (\\ / |  / \\  / \\");

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

        mvprintw(3, 33, "  ___      _        _     _   _          ___ _                 ");
        mvprintw(4, 33, " / __| ___| |___ __| |_  | |_| |_  ___  / __| |_ __ _ __ _ ___ ");
        mvprintw(5, 33, " \\__ \\/ -_) / -_) _|  _| |  _| ' \\/ -_) \\__ \\  _/ _` / _` / -_)");
        mvprintw(6, 33, " |___/\\___|_\\___\\__|\\__|  \\__|_||_\\___| |___/\\__\\__,_\\__, \\___|");
        mvprintw(7, 33, "                                                    |___/     ");

        mvprintw(25, 102, "            |   _   _");
        mvprintw(26, 102, "      . | . x .|.|-|.|");
        mvprintw(27, 102, "   |\\ ./.\\-/.\\-|.|.|.| ");
        mvprintw(28, 102, "~~~|.|_|.|_|.|.|.|_|.|~~~");

        mvprintw(25, 2, "            |   _   _");
        mvprintw(26, 2, "      . | . x .|.|-|.|");
        mvprintw(27, 2, "   |\\ ./.\\-/.\\-|.|.|.| ");
        mvprintw(28, 2, "~~~|.|_|.|_|.|.|.|_|.|~~~");

        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        
        switch (selectStage) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(13, 61, "> Stage 1");
                attroff(COLOR_PAIR(1));
                mvprintw(15, 61, "  Stage 2");
                mvprintw(17, 61, "  Stage 3");
                break;
            case 2:
                mvprintw(13, 61, "  Stage 1");
                attron(COLOR_PAIR(1));
                mvprintw(15, 61, "> Stage 2");
                attroff(COLOR_PAIR(1));
                mvprintw(17, 61, "  Stage 3");
                break;
            case 3:
                mvprintw(13, 61, "  Stage 1");
                mvprintw(15, 61, "  Stage 2");
                attron(COLOR_PAIR(1));
                mvprintw(17, 61, "> Stage 3");
                attroff(COLOR_PAIR(1));
                break;
        }
        
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