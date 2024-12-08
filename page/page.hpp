#pragma once
#include <ncurses.h>
#include <unistd.h>

enum Page { START, PLAY, END, QUIT };

int startPage();

int playPage(int& score);

int endPage(int score);

int checkQuitStart();

int checkQuitStage();