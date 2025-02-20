#include "bow_image.hpp"

// 화살 이미지
vector<string> arrow_left_txt = {
    "<"
};

vector<string> arrow_right_txt = {
    ">"
};

vector<string> arrow_up_txt = {
    "^"
};

vector<string> arrow_down_txt = {
    "v"
};

// 화살 이미지 클래스 생성
Image arrow_left_image(arrow_left_txt, COLOR_YELLOW);
Image arrow_right_image(arrow_right_txt, COLOR_YELLOW);
Image arrow_up_image(arrow_up_txt, COLOR_YELLOW);
Image arrow_down_image(arrow_down_txt, COLOR_YELLOW);