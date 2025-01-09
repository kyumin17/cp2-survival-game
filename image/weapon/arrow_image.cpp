#include "bow_image.hpp"

// 화살 이미지
vector<string> arrowLeftTxt = {
    "<"
};

vector<string> arrowRightTxt = {
    ">"
};

vector<string> arrowUpTxt = {
    "^"
};

vector<string> arrowDownTxt = {
    "v"
};

// 화살 이미지 클래스 생성
Image arrowLeftImage(arrowLeftTxt, COLOR_YELLOW);
Image arrowRightImage(arrowRightTxt, COLOR_YELLOW);
Image arrowUpImage(arrowUpTxt, COLOR_YELLOW);
Image arrowDownImage(arrowDownTxt, COLOR_YELLOW);