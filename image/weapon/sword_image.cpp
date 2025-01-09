#include "sword_image.hpp"

// 검 이미지
vector<string> swordRight0Txt = {
    "|    ",
    "|    ",
    "T    ",
    "     ",
    "     ",
    "     "
};

vector<string> swordRight1Txt = {
    "  /  ",
    " /   ",
    "/    ",
    "     ",
    "     ",
    "     "
};

vector<string> swordRight2Txt = {
    "     ",
    "     ",
    "- - -",
    "     ",
    "     ",
    "     "
};

vector<string> swordRight3Txt = {
    "     ",
    "     ",
    "     ",
    "\\    ",
    " \\   ",
    "  \\  "
};

vector<string> swordRight4Txt = {
    "     ",
    "     ",
    "     ",
    "|    ",
    "|    ",
    "|    "
};

vector<string> swordLeft0Txt = {
    "    |",
    "    |",
    "    T",
    "     ",
    "     ",
    "     "
};

vector<string> swordLeft1Txt = {
    "  \\  ",
    "   \\ ",
    "    \\",
    "     ",
    "     ",
    "     "
};

vector<string> swordLeft2Txt = {
    "     ",
    "     ",
    "- - -",
    "     ",
    "     ",
    "     "
};

vector<string> swordLeft3Txt = {
    "     ",
    "     ",
    "     ",
    "    /",
    "   / ",
    "  /  "
};

vector<string> swordLeft4Txt = {
    "     ",
    "     ",
    "     ",
    "    |",
    "    |",
    "    |"
};

// 검 이미지 클래스 생성
Image swordRightImageArr[5] = {
    Image(swordRight0Txt, COLOR_YELLOW),
    Image(swordRight1Txt, COLOR_YELLOW),
    Image(swordRight2Txt, COLOR_YELLOW),
    Image(swordRight3Txt, COLOR_YELLOW),
    Image(swordRight4Txt, COLOR_YELLOW),
};

Image swordLeftImageArr[5] = {
    Image(swordLeft0Txt, COLOR_YELLOW),
    Image(swordLeft1Txt, COLOR_YELLOW),
    Image(swordLeft2Txt, COLOR_YELLOW),
    Image(swordLeft3Txt, COLOR_YELLOW),
    Image(swordLeft4Txt, COLOR_YELLOW),
};