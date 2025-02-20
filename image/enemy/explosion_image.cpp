#include "explosion_image.hpp"

// 상황에 따른 폭발하는 적 이미지
vector<string> explosion_txt = {
    "(!)",
    "/|\\",
    "/ \\"
}; // 기본형

vector<string> explosion_dead_txt = {
    "      |      ",
    "    \\   /    ",
    "   -     -   ",
    "    /   \\    ",
    "      |      "
}; // 죽을 때

// 폭발하는 적 이미지 클래스 생성
Image explosion_image(explosion_txt, COLOR_GREEN);
Image explosion_dead_image(explosion_dead_txt, COLOR_GREEN);