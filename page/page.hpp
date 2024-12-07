#pragma once
#include <ncurses.h>
#include <unistd.h>

enum Page { START, PLAY, END, QUIT };

int startPage();

int playPage();

int selectWeaponPage();

int endPage();

int checkQuitStart();

int checkQuitStage();