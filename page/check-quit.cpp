#include <ncurses.h>
#include <unistd.h>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30
#define ms 1000

int checkQuitPage() {
    char ch;
    int selectQuit = 1;
    while(1) {
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

        mvprintw(1, 39, "    _                                              ");
        mvprintw(2, 39, "   /_\\  _ _ ___   _  _ ___ _  _   ____  _ _ _ ___  ");
        mvprintw(3, 39, "  / _ \\| '_/ -_) | || / _ \\ || | (_-< || | '_/ -_) ");
        mvprintw(4, 39, " /_/ \\_\\_| \\___|  \\_, \\___/\\_,_| /__/\\_,_|_| \\___| ");
        mvprintw(5, 39, "                  |__/                             ");
        mvprintw(6, 39, "                 | |_ ___                          ");
        mvprintw(7, 39, "            _ _  |  _/ _ \\             ___         ");
        mvprintw(8, 39, "  __ _ _  _(_) |_ \\__\\___/_ _ _ __  __|__ \\        ");
        mvprintw(9, 39, " / _` | || | |  _| / _` / _` | '  \\/ -_)/_/        ");
        mvprintw(10, 39, " \\__, |\\_,_|_|\\__| \\__, \\__,_|_|_|_\\___(_)         ");
        mvprintw(11, 39, "    |_|            |___/                           ");

        mvprintw(26, 37, "  o  \\ o / _ o       __|   \\ /    |__      o _ \\ o /  o");
        mvprintw(27, 37, " /|\\   |    /\\  ___\\o  \\o   |   o/   o/__  /\\    |   /|\\");
        mvprintw(28, 37, " / \\  / \\  | \\ /)  |   ( \\ /o\\ / )   |  (\\ / |  / \\  / \\");


        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);

        switch (ch) {
            case 'w':
                if (selectQuit != 1) {
                    selectQuit--;
                } 
                break;
            case 's':
                if (selectQuit != 3) {
                    selectQuit++;
                }
                break;
        }

        switch (selectQuit) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(16, 55, "> Cancel");
                attroff(COLOR_PAIR(1));
                mvprintw(18, 55, "  Quit");
                break;
            case 2:
                mvprintw(16, 55, "  Cancel");
                attron(COLOR_PAIR(2));
                mvprintw(18, 55, "> Quit");
                attroff(COLOR_PAIR(2));
                break;
        }

        if (ch == '\n') {
            if (selectQuit == 1) {
                return 0; //back to game
            } else if (selectQuit == 2) {
                return 1;
            }
        }
    }
}


int checkQuitStage() {
    char ch;
    int QuitStage = 1;

    keypad(stdscr, TRUE);

    while(1) {
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
                if(QuitStage != 1) {
                    QuitStage--;
                }
                break;
            case 's':
                if(QuitStage != 3) {
                    QuitStage++;
                }
                break;
        }

        switch (QuitStage) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(16, 55, "> Resume Game");
                attroff(COLOR_PAIR(1));
                mvprintw(18, 55, "  Return to Stage Selection");
                break;
            case 2:
                mvprintw(16, 55, "  Resume Game");
                attron(COLOR_PAIR(2));
                mvprintw(18, 55, "> Return to Stage Selection");
                attroff(COLOR_PAIR(2));
                break;
        }

        if (ch == '\n') {
            if (QuitStage == 1) {
                return 0; //back to game
            } else if (QuitStage == 2) {
                return 1;
            }
        }
        usleep(10000);
    }
}

int checkQuitStart() {
    char ch;
    int QuitStart = 1;

    while(1) {
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

        switch (ch) {
            case 'w':
                if(QuitStart != 1) {
                    QuitStart--;
                }
                break;
            case 's':
                if(QuitStart != 2) {
                    QuitStart++;
                }
                break;
        }

        switch (QuitStart) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(16, 55, "> Cancel");
                attroff(COLOR_PAIR(1));
                mvprintw(18, 55, "  Quit");
                break;
            case 2:
                mvprintw(16, 55, "  Cancel");
                attron(COLOR_PAIR(2));
                mvprintw(18, 55, "> Quit");
                attroff(COLOR_PAIR(2));
                break;
        }

        if (ch == '\n') {
            if (QuitStart == 1) {
                clear();
                refresh();
                return startPage(); //back to game
            } else if (QuitStart == 2) {
                return 0;
            }
        }
        usleep(10000);
    }
}