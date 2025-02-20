#include "slime_image.hpp"

// 슬라임 적 이미지
vector<string> slime_txt = {
    " /\\ ",
    "(++)"
};

vector<string> slime_div1_txt = {
    "(++)"
};

vector<string> slime_div2_txt = {
    "(+)"
};

// 슬라임 적 이미지 클래스 생성
Image slime_image(slime_txt, COLOR_GREEN);
Image slime_div1_image(slime_div1_txt, COLOR_GREEN);
Image slime_div2_image(slime_div2_txt, COLOR_GREEN);