#include "player-image.hpp"

// 바라보는 방향에 따른 플레이어 캐릭터
vector<string> playerLeftTxt = {
    ":o ",
    "/|\\",
    "/ \\"
};

vector<string> playerRightTxt = {
    " o:",
    "/|\\",
    "/ \\"
};

vector<string> playerUpTxt = {
    " o ",
    "/|\\",
    "/ \\"
};

vector<string> playerDownTxt = {
    " o ",
    "/|\\",
    "/ \\"
};

// 플레이어 이미지 클래스 생성
Image playerLeftImage(playerLeftTxt, COLOR_WHITE);
Image playerRightImage(playerRightTxt, COLOR_WHITE);
Image playerUpImage(playerUpTxt, COLOR_WHITE);
Image playerDownImage(playerDownTxt, COLOR_WHITE);