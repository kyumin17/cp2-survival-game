#pragma once
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include "number_shape.hpp"

using namespace std;

vector<int> getScoreDigitList(int score);

vector<string> getScoreShapeList(vector<int> score_digit_list);

void drawScore(vector<string> score_shape_list);