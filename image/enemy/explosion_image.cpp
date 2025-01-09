#include "explosion_image.hpp"

// 상황에 따른 폭발하는 적 이미지
vector<string> explosionTxt = {
    "(!)",
    "/|\\",
    "/ \\"
}; // 기본형

vector<string> explosionDeadTxt = {
    "      |      ",
    "    \\   /    ",
    "   -     -   ",
    "    /   \\    ",
    "      |      "
}; // 죽을 때

// 폭발하는 적 이미지 클래스 생성
Image explosionImage(explosionTxt, COLOR_GREEN);
Image explosionDeadImage(explosionDeadTxt, COLOR_GREEN);