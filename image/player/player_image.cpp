#include "player_image.hpp"

// 바라보는 방향에 따른 플레이어 캐릭터
vector<string> player_left_txt = {
    ":o ",
    "/|\\",
    "/ \\"
};

vector<string> player_right_txt = {
    " o:",
    "/|\\",
    "/ \\"
};

vector<string> player_up_txt = {
    " o ",
    "/|\\",
    "/ \\"
};

vector<string> player_down_txt = {
    " o ",
    "/|\\",
    "/ \\"
};

// 플레이어 이미지 클래스 생성
Image player_left_image(player_left_txt, COLOR_WHITE);
Image player_right_image(player_right_txt, COLOR_WHITE);
Image player_up_image(player_up_txt, COLOR_WHITE);
Image player_down_image(player_down_txt, COLOR_WHITE);