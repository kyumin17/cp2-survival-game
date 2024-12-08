#include <vector>
#include <algorithm>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30

using namespace std;

int endPage(int score) {
    /*
    retry라면 1을, quit이라면 0을 반환한다.
    */

    char ch;
    int endingPage = 1;
    vector<int> v;

    while (score != 0) {
        v.push_back(score % 10);
        score /= 10;
    }

    reverse(v.begin(), v.end());

    char number[10][3][3];

    char one[3][4] = {
        " _ ",
        " | ",
        " | "
    };

    char two[3][4] = {
        " _ ",
        " _|",
        "|_ "
    };

    char three[3][4] = {
        " _ ",
        " _|",
        " _|"
    };

    char four[3][4] = {
        "  _",
        "|_|",
        "  |"
    };

    char five[3][4] = {
        " _ ",
        "|_ ",
        " _|"
    };

    char six[3][4] = {
        " _ ",
        "|_ ",
        "|_|"
    };

    char seven[3][4] = {
        " _ ",
        "  |",
        "  |"
    };

    char eight[3][4] = {
        " _ ",
        "|_|",
        "|_|"
    };

    char nine[3][4] = {
        " _ ",
        "|_|",
        " _|"
    };

    char zero[3][4] = {
        " _ ",
        "| |",
        "|_|"
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            number[0][i][j] = zero[i][j];
            number[1][i][j] = one[i][j];
            number[2][i][j] = two[i][j];
            number[3][i][j] = three[i][j];
            number[4][i][j] = four[i][j];
            number[5][i][j] = five[i][j];
            number[6][i][j] = six[i][j];
            number[7][i][j] = seven[i][j];
            number[8][i][j] = eight[i][j];
            number[9][i][j] = nine[i][j];
        }
    }

    char scoreTxt[3][40];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 40; j++) {
            scoreTxt[i][j] = ' ';
        }
    }

    for (size_t i = 0; i < v.size(); i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scoreTxt[j][4 * i + k] = number[v[i]][j][k];
            }
        }
    }
    
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

        mvprintw(5, 36, "   ____    _    __  __ _____    _____     _______ ____  ");
        mvprintw(6, 36, "  / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ ");
        mvprintw(7, 36, " | |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |");
        mvprintw(8, 36, " | |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ < ");
        mvprintw(9, 36, "  \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\");
        
        mvprintw(12, 43, "__  __ __  __  __");
        mvprintw(13, 43, "|_  |  | | |_| |_  '");
        mvprintw(14, 43, "__| |_ |_| | | |_  '");

        move(12, 65);
        for (int i = 0; i < 40; i++) {
            printw("%c", scoreTxt[0][i]);
        }
        printw("\n");

        move(13, 65);
        for (int i = 0; i < 40; i++) {
            printw("%c", scoreTxt[1][i]);
        }

        move(14, 65);
        for (int i = 0; i < 40; i++) {
            printw("%c", scoreTxt[2][i]);
        }

        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);

        switch (ch) {
            case 'w':
                if (endingPage != 1) {
                    endingPage--;
                } 
                break;
            case 's':
                if (endingPage != 2) {
                    endingPage++;
                }
                break;
        }

        switch (endingPage) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(20, 60, "> Restart");
                attroff(COLOR_PAIR(1));
                mvprintw(22, 60, "  Home");
                break;
            case 2:
                mvprintw(20, 60, "  Restart");
                attron(COLOR_PAIR(2));
                mvprintw(22, 60, "> Home");
                attroff(COLOR_PAIR(2));
                break;
        }

        if (ch == '\n') {
            if (endingPage == 1) {
                return PLAY; //재도전
            } else if (endingPage == 2) {
                return START; //시작페이지
            }
        }

        usleep(10000);
    }
}