#include "page.hpp"
#include "asset/score.hpp"

using namespace std;

int endPage(int score, int& max_score) {
    int ch;
    int option = 1;
    bool isMaxScore = false;

    if (max_score < score) {
        max_score = score;
        isMaxScore = true;
    }

    vector<int> score_digit_list = getScoreDigitList(score);
    vector<string> score_shape_list = getScoreShapeList(score_digit_list);
    
    while(1) {
        drawEndText();
        drawBorder();
        drawScore(score_shape_list);

        if (isMaxScore) {
            drawNewRecordText();
        }

        ch = getch();
        option = getOption(ch, option);

        drawOptionDisplay(option, "Restart", "Home", 5);
        
        if (ch == '\n') {
            if (option == 1) {
                return PLAY;
            } else if (option == 2) {
                return START;
            }
        }

        usleep(SLEEP);
    }
}