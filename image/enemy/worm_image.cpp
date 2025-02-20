#include "worm_image.hpp"

// 지렁이 적 이미지
vector<string> worm_left_txt = {
    "@~~~"
};

vector<string> worm_right_txt = {
    "~~~@"
};

// 지렁이 적 이미지 클래스 생성
Image worm_left_image(worm_left_txt, COLOR_GREEN);
Image worm_right_image(worm_right_txt, COLOR_GREEN);