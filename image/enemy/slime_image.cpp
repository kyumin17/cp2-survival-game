#include "slime_image.hpp"

// 슬라임 적 이미지
vector<string> slimeTxt = {
    " /\\ ",
    "(++)"
};

vector<string> slimeDiv1Txt = {
    "(++)"
};

vector<string> slimeDiv2Txt = {
    "(+)"
};

// 슬라임 적 이미지 클래스 생성
Image slimeImage(slimeTxt, COLOR_GREEN);
Image slimeDiv1Image(slimeDiv1Txt, COLOR_GREEN);
Image slimeDiv2Image(slimeDiv2Txt, COLOR_GREEN);