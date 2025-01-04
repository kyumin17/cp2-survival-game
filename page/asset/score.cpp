#include "score.hpp"

vector<int> getScoreDigitList(int score) {
    vector<int> score_digit_list;

    while (score) {
        score_digit_list.push_back(score % 10);
        score /= 10;
    }

    reverse(score_digit_list.begin(), score_digit_list.end());

    return score_digit_list;
}

vector<string> getScoreShapeList(vector<int> score_digit_list) {
    string s(40, ' ');
    vector<string> score_shape_list(3, s);

    for (size_t i = 0; i < score_digit_list.size(); i++) {
        int number = score_digit_list[i];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                score_shape_list[j][4 * i + k] = number_shape_list[number][j][k];
            }
        }
    }

    return score_shape_list;
}

void drawScore(vector<string> score_shape_list) {
    for (int i = 0; i < 3; i++) {
        move(12 + i, 65);
        for (int j = 0; j < 40; j++) {
            printw("%c", score_shape_list[i][j]);
        }
    }
}