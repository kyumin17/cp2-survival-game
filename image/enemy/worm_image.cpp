#include "worm_image.hpp"

// 지렁이 적 이미지
vector<string> wormLeftTxt = {
    "@~~~"
};

vector<string> wormRightTxt = {
    "~~~@"
};

// 지렁이 적 이미지 클래스 생성
Image wormLeftImage(wormLeftTxt, COLOR_GREEN);
Image wormRightImage(wormRightTxt, COLOR_GREEN);