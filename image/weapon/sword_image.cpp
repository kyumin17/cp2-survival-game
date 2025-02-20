#include "sword_image.hpp"

// 검 이미지
vector<string> sword_right0_txt = {
    "|    ",
    "|    ",
    "T    ",
    "     ",
    "     ",
    "     "
};

vector<string> sword_right1_txt = {
    "  /  ",
    " /   ",
    "/    ",
    "     ",
    "     ",
    "     "
};

vector<string> sword_right2_txt = {
    "     ",
    "     ",
    "- - -",
    "     ",
    "     ",
    "     "
};

vector<string> sword_right3_txt = {
    "     ",
    "     ",
    "     ",
    "\\    ",
    " \\   ",
    "  \\  "
};

vector<string> sword_right4_txt = {
    "     ",
    "     ",
    "     ",
    "|    ",
    "|    ",
    "|    "
};

vector<string> sword_left0_txt = {
    "    |",
    "    |",
    "    T",
    "     ",
    "     ",
    "     "
};

vector<string> sword_left1_txt = {
    "  \\  ",
    "   \\ ",
    "    \\",
    "     ",
    "     ",
    "     "
};

vector<string> sword_left2_txt = {
    "     ",
    "     ",
    "- - -",
    "     ",
    "     ",
    "     "
};

vector<string> sword_left3_txt = {
    "     ",
    "     ",
    "     ",
    "    /",
    "   / ",
    "  /  "
};

vector<string> sword_left4_txt = {
    "     ",
    "     ",
    "     ",
    "    |",
    "    |",
    "    |"
};

// 검 이미지 클래스 생성
Image sword_right_image_array[5] = {
    Image(sword_right0_txt, COLOR_YELLOW),
    Image(sword_right1_txt, COLOR_YELLOW),
    Image(sword_right2_txt, COLOR_YELLOW),
    Image(sword_right3_txt, COLOR_YELLOW),
    Image(sword_right4_txt, COLOR_YELLOW),
};

Image sword_left_image_array[5] = {
    Image(sword_left0_txt, COLOR_YELLOW),
    Image(sword_left1_txt, COLOR_YELLOW),
    Image(sword_left2_txt, COLOR_YELLOW),
    Image(sword_left3_txt, COLOR_YELLOW),
    Image(sword_left4_txt, COLOR_YELLOW),
};