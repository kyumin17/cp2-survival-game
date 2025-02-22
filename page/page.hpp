#pragma once
#include <ncurses.h>
#include <unistd.h>
#define WIDTH 130
#define HEIGHT 30
#define SLEEP 10000
#include "asset/draw.hpp"
#include "asset/option.hpp"

enum Page { START, PLAY, END, QUIT }; // 페이지 종류

int startPage();

int playPage(int& score);

int endPage(int score, int& max_score);

bool checkQuitGamePage();

bool checkQuitStagePage();