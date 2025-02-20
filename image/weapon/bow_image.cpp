#include "arrow_image.hpp"

// 활 이미지
vector<string> bow_left_txt = {
    "<{-"
};

vector<string> bow_right_txt = {
    "-}>"
};

vector<string> bow_up_txt = {
    "/|\\"
};

vector<string> bow_down_txt = {
    "(-)"
};

// 활 이미지 클래스 생성
Image bow_left_image(bow_left_txt, COLOR_YELLOW);
Image bow_right_image(bow_right_txt, COLOR_YELLOW);
Image bow_up_image(bow_up_txt, COLOR_WHITE);
Image bow_down_image(bow_down_txt, COLOR_YELLOW);