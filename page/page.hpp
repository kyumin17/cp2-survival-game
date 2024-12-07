#pragma once
#include <ncurses.h>
#include <unistd.h>

int startPage();

int playPage();

int selectWeaponPage();

int endPage(int score);

int checkQuitStart();

int checkQuitStage();