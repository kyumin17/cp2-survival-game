#pragma once
#include <ncurses.h>
#include <string>

using namespace std;

int getOption(int ch, int option);

void drawOptionDisplay(int option, string str1, string str2, int y_coord);