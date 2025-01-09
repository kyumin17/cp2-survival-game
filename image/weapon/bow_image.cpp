#include "arrow_image.hpp"

// 활 이미지
vector<string> bowLeftTxt = {
    "<{-"
};

vector<string> bowRightTxt = {
    "-}>"
};

vector<string> bowUpTxt = {
    "/|\\"
};

vector<string> bowDownTxt = {
    "(-)"
};

// 활 이미지 클래스 생성
Image bowLeftImage(bowLeftTxt, COLOR_YELLOW);
Image bowRightImage(bowRightTxt, COLOR_YELLOW);
Image bowUpImage(bowUpTxt, COLOR_WHITE);
Image bowDownImage(bowDownTxt, COLOR_YELLOW);