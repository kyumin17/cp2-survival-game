#pragma once
#include "../component/component.hpp"
#include <vector>

class PlayerCharacter {
    public:
        Cell** left;
        Cell** right;
        Cell** back;
        Cell** front;
        PlayerCharacter();
};

class EnemyCharacter {
    public:
        Cell** enemy1;
        Cell** enemy2;
        Cell** enemy2Dead; //적2 범위 피해 이미지
        Cell** enemy3Left;
        Cell** enemy3Right;
        Cell** enemy3Front;
        Cell** enemy3Back;
        Cell** enemy4;
        Cell** enemy4Div1; //1차 분열 이미지
        Cell** enemy4Div2; //2차 분열 이미지
        EnemyCharacter();
};

class BowShape {
    public:
        Cell** bowRight;
        Cell** bowLeft;
        Cell** bowDown;
        Cell** bowUp;
        Cell** arrowRight;
        Cell** arrowLeft;
        Cell** arrowDown;
        Cell** arrowUp;
        BowShape();
};

class SwordShape {
    public:
        Cell** swordRight[5]; //움직임 배열로 저장
        Cell** swordLeft[5];
        SwordShape();
};

class EraserShape {
    public:
        Cell** eraserNonactive;
        Cell** eraserActive; //공격 시 이미지
        EraserShape();
};