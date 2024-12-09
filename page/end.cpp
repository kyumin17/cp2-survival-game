#include <vector>
#include <algorithm>
#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30

using namespace std;

int endPage(int score, int& maxScore) {
    /*
    게임 종료 화면
    retry 선택 시 게임 재시작, home 클릭 시 start page로 이동
    */

    int ch;
    int option = 1;
    bool isMaxScore = false;

    /*최대 점수 갱신*/
    if (maxScore < score) {
        maxScore = score;
        isMaxScore = true;
    }

    /*점수의 각 자릿수를 저장*/
    vector<int> scoreList;

    while (score != 0) {
        scoreList.push_back(score % 10);
        score /= 10;
    }

    reverse(scoreList.begin(), scoreList.end());

    /*각 숫자 모양 배열*/
    char numberShapeList[10][3][3];

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

    /*배열에 숫자 모양 집어넣음*/
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            numberShapeList[0][i][j] = zero[i][j];
            numberShapeList[1][i][j] = one[i][j];
            numberShapeList[2][i][j] = two[i][j];
            numberShapeList[3][i][j] = three[i][j];
            numberShapeList[4][i][j] = four[i][j];
            numberShapeList[5][i][j] = five[i][j];
            numberShapeList[6][i][j] = six[i][j];
            numberShapeList[7][i][j] = seven[i][j];
            numberShapeList[8][i][j] = eight[i][j];
            numberShapeList[9][i][j] = nine[i][j];
        }
    }

    /*스코어의 숫자 모양 배열에 저장*/
    char scoreShapeList[3][40];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 40; j++) {
            scoreShapeList[i][j] = ' ';
        }
    }

    for (size_t i = 0; i < scoreList.size(); i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scoreShapeList[j][4 * i + k] = numberShapeList[scoreList[i]][j][k];
            }
        }
    }
    
    while(1) {
        ch = getch();

        /*테두리 그림*/
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

        /*화면 출력*/
        mvprintw(5, 36, "   ____    _    __  __ _____    _____     _______ ____  ");
        mvprintw(6, 36, "  / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ ");
        mvprintw(7, 36, " | |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |");
        mvprintw(8, 36, " | |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ < ");
        mvprintw(9, 36, "  \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\");
        
        mvprintw(12, 43, "__  __ __  __  __");
        mvprintw(13, 43, "|_  |  | | |_| |_  '");
        mvprintw(14, 43, "__| |_ |_| | | |_  '");

        if (isMaxScore) {
            mvprintw(16, 43, "NEW RECORD!");
        }

        /*스코어 출력*/
        move(12, 65);
        for (int i = 0; i < 40; i++) {
            printw("%c", scoreShapeList[0][i]);
        }
        printw("\n");

        move(13, 65);
        for (int i = 0; i < 40; i++) {
            printw("%c", scoreShapeList[1][i]);
        }

        move(14, 65);
        for (int i = 0; i < 40; i++) {
            printw("%c", scoreShapeList[2][i]);
        }

        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);

        /*입력에 따라 옵션 변경*/
        switch (ch) {
            case KEY_UP:
            case 'w':
                if (option != 1) {
                    option--;
                } 
                break;
            case KEY_DOWN:
            case 's':
                if (option != 2) {
                    option++;
                }
                break;
        }

        /*입력에 따라 옵션 focus*/
        switch (option) {
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

        /*엔터 누를 시 옵션 선택*/
        if (ch == '\n') {
            if (option == 1) {
                return PLAY; //재도전
            } else if (option == 2) {
                return START; //시작페이지
            }
        }

        usleep(10000);
    }
}