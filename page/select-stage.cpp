#include <ncurses.h>
#include <unistd.h>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30
#define ms 1000

int selectStagePage(){
    char ch;
    int selectStage = 1;
    while (1) {
        usleep(10 * ms);
        
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
        
        switch (ch) {
            case 'w':
                if(selectStage != 1) {
                    selectStage--;
                }
                break;
            case 's':
                if(selectStage != 4) {
                    selectStage++;
                }
                break;
        }

        switch (selectStage) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(13, 61, "> Stage 1");
                attroff(COLOR_PAIR(1));
                mvprintw(15, 61, "  Stage 2");
                mvprintw(17, 61, "  Stage 3");
                mvprintw(19, 61, "  Back");
                break;
            case 2:
                mvprintw(13, 61, "  Stage 1");
                attron(COLOR_PAIR(1));
                mvprintw(15, 61, "> Stage 2");
                attroff(COLOR_PAIR(1));
                mvprintw(17, 61, "  Stage 3");
                mvprintw(19, 61, "  Back");
                break;
            case 3:
                mvprintw(13, 61, "  Stage 1");
                mvprintw(15, 61, "  Stage 2");
                attron(COLOR_PAIR(1));
                mvprintw(17, 61, "> Stage 3");
                attroff(COLOR_PAIR(1));
                mvprintw(19, 61, "  Back");
                break;
            case 4:
                mvprintw(13, 61, "  Stage 1");
                mvprintw(15, 61, "  Stage 2");
                mvprintw(17, 61, "  Stage 3");
                attron(COLOR_PAIR(1));
                mvprintw(19, 61, "> Back");
                attroff(COLOR_PAIR(1));

        }
        
        if (ch == '\n') {
            if(selectStage == 1) {
                clear();
                refresh();
                return selectStage;
            } else if(selectStage == 4) {
                clear();
                refresh();
                return startPage();
            } else {
                clear();
                refresh();
                return selectStage; //play game 
            }
            
        }
        //  else if (ch == 'q') {
        //     clear();
        //     refresh();
        //     if (checkQuitPage()) {
        //         return 0; //end game
        //     } else {
        //         return selectStagePage(); //back to game
        //     }
        // }
    }
}