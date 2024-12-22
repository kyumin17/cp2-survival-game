#pragma once
#include <ncurses.h>
#include <unistd.h>
#define WIDTH 130
#define HEIGHT 30

enum Page { START, PLAY, END, QUIT }; // 페이지 종류

int startPage();

int playPage(int& score);

int endPage(int score, int& maxScore);

bool checkQuitGamePage();

bool checkQuitStagePage();