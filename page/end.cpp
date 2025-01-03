#include <vector>
#include <algorithm>
#include "page.hpp"
#include "../manage/ui.hpp"

using namespace std;

// 숫자 모양 배열
char one[3][4] = {" _ ", " | ", " | "};
char two[3][4] = {" _ ", " _|", "|_ "};
char three[3][4] = {" _ ", " _|", " _|"};
char four[3][4] = {"  _", "|_|", "  |"};
char five[3][4] = {" _ ", "|_ ", " _|"};
char six[3][4] = {" _ ", "|_ ", "|_|"};
char seven[3][4] = {" _ ", "  |", "  |"};
char eight[3][4] = {" _ ", "|_|", "|_|"};
char nine[3][4] = {" _ ", "|_|", " _|"};
char zero[3][4] = {" _ ", "| |", "|_|"};

int endPage(int score, int& maxScore) {
    /*
    게임 종료 화면
    retry 선택 시 PLAY 반환, home 선택 시 START 반환
    */

    int ch;
    int option = 1;
    bool isMaxScore = false;

    // 최대 점수 갱신
    if (maxScore < score) {
        maxScore = score;
        isMaxScore = true;
    }

    vector<int> scoreDigitArr; // 점수의 각 자릿수

    while (score != 0) {
        scoreDigitArr.push_back(score % 10);
        score /= 10;
    }

    reverse(scoreDigitArr.begin(), scoreDigitArr.end());

    char numberShapeList[10][3][3]; // 각 숫자 모양 배열

    // 배열에 숫자 모양 넣음
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

    char scoreShapeList[3][40]; // 스코어 모양

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 40; j++) {
            scoreShapeList[i][j] = ' ';
        }
    }

    for (size_t i = 0; i < scoreDigitArr.size(); i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                // 4칸 단위로 숫자 받아옴
                scoreShapeList[j][4 * i + k] = numberShapeList[scoreDigitArr[i]][j][k];
            }
        }
    }
    
    while(1) {
        ch = getch();

        // 테두리 출력
        drawBorder();

        // 화면 출력
        drawEndText();

        if (isMaxScore) {
            mvprintw(16, 43, "NEW RECORD!");
        }

        // 스코어 출력
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

        // 입력에 따라 옵션 변경
        switch (ch) {
            case KEY_UP:
            case 'w': // 위로 이동
                if (option != 1) {
                    option--;
                } 
                break;
            case KEY_DOWN:
            case 's': // 아래로 이동
                if (option != 2) {
                    option++;
                }
                break;
        }

        // 선택 옵션에 따라 디스플레이 변경
        switch (option) {
            case 1: // 재시작 선택
                attron(COLOR_PAIR(COLOR_CYAN));
                mvprintw(20, 60, "> Restart");
                attroff(COLOR_PAIR(COLOR_CYAN));
                mvprintw(22, 60, "  Home");
                break;
            case 2: // 시작 화면 선택
                mvprintw(20, 60, "  Restart");
                attron(COLOR_PAIR(COLOR_RED));
                mvprintw(22, 60, "> Home");
                attroff(COLOR_PAIR(COLOR_RED));
                break;
        }

        // 엔터 누를 시 옵션 선택
        if (ch == '\n') {
            if (option == 1) {
                return PLAY;
            } else if (option == 2) {
                return START;
            }
        }

        usleep(10000);
    }
}