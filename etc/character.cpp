#include "character.hpp"

PlayerCharacter::PlayerCharacter() {
    char leftTxt[3][4] = {
        ":o ",
        "/|\\",
        "/ \\"
    };

    char rightTxt[3][4] = {
        " o:",
        "/|\\",
        "/ \\"
    };


    char backTxt[3][4] = {
        " o ",
        "/|\\",
        "/ \\"
    };

    char frontTxt[3][4] = {
        " o ",
        "/|\\",
        "/ \\"
    };

    int row = 3;
    int col = 3;

    //동적할당
    left = new Cell*[row];
    right = new Cell*[row];
    back = new Cell*[row];
    front = new Cell*[row];

    for (int i = 0; i < row; i++) {
        left[i] = new Cell[col];
        right[i] = new Cell[col];
        back[i] = new Cell[col];
        front[i] = new Cell[col];
    }

    //값 및 색깔 설정
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            left[i][j].value = leftTxt[i][j];
            right[i][j].value = rightTxt[i][j];
            back[i][j].value = backTxt[i][j];
            front[i][j].value = frontTxt[i][j];

            left[i][j].color = COLOR_WHITE;
            right[i][j].color = COLOR_WHITE;
            back[i][j].color = COLOR_WHITE;
            front[i][j].color = COLOR_WHITE;
        }
    }
}

EnemyCharacter::EnemyCharacter() {
    char enemy1Txt[3][4] = {
        " # ",
        "/|\\",
        "/ \\"
    };

    int row = 3;
    int col = 3;

    enemy1 = new Cell*[row];

    for (int i = 0; i < row; i++) {
        enemy1[i] = new Cell[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            enemy1[i][j].value = enemy1Txt[i][j];
            enemy1[i][j].color = COLOR_GREEN;
        }
    }
}

BowShape::BowShape() {
    //활
    bowRight = new Cell*[1];
    bowRight[0] = new Cell[3];
    bowRight[0][0].value = '-';
    bowRight[0][1].value = '}';
    bowRight[0][2].value = '>';
    bowRight[0][0].color = COLOR_YELLOW;
    bowRight[0][1].color = COLOR_WHITE;
    bowRight[0][2].color = COLOR_YELLOW;

    bowLeft = new Cell*[1];
    bowLeft[0] = new Cell[3];
    bowLeft[0][0].value = '<';
    bowLeft[0][1].value = '{';
    bowLeft[0][2].value = '-';
    bowLeft[0][0].color = COLOR_YELLOW;
    bowLeft[0][1].color = COLOR_WHITE;
    bowLeft[0][2].color = COLOR_YELLOW;

    bowDown = new Cell*[1];
    bowDown[0] = new Cell[3];
    bowDown[0][0].value = '(';
    bowDown[0][1].value = '-';
    bowDown[0][2].value = '\'';
    bowDown[0][0].color = COLOR_WHITE;
    bowDown[0][1].color = COLOR_YELLOW;
    bowDown[0][2].color = COLOR_WHITE;

    bowUp = new Cell*[1];
    bowUp[0] = new Cell[3];
    bowUp[0][0].value = '\'';
    bowUp[0][1].value = '|';
    bowUp[0][2].value = ')';
    bowUp[0][0].color = COLOR_WHITE;
    bowUp[0][1].color = COLOR_WHITE;
    bowUp[0][2].color = COLOR_WHITE;

    //화살
    arrowRight = new Cell*[1];
    arrowRight[0] = new Cell[1];
    arrowRight[0][0].value = '>';
    arrowRight[0][0].color = COLOR_YELLOW;

    arrowLeft = new Cell*[1];
    arrowLeft[0] = new Cell[1];
    arrowLeft[0][0].value = '<';
    arrowLeft[0][0].color = COLOR_YELLOW;

    arrowDown = new Cell*[1];
    arrowDown[0] = new Cell[1];
    arrowDown[0][0].value = 'v';
    arrowDown[0][0].color = COLOR_YELLOW;

    arrowUp = new Cell*[1];
    arrowUp[0] = new Cell[1];
    arrowUp[0][0].value = '^';
    arrowUp[0][0].color = COLOR_YELLOW;
}

PoleShape::PoleShape() {
    char poleRight0[6][6] = {
        "|    ",
        "|    ",
        "T    ",
        "     ",
        "     ",
        "     "
    };

    char poleRight1[6][6] = {
        "  /  ",
        " /   ",
        "/    ",
        "     ",
        "     ",
        "     "
    };

    char poleRight2[6][6] = {
        "     ",
        "     ",
        "- - -",
        "     ",
        "     ",
        "     "
    };

    char poleRight3[6][6] = {
        "     ",
        "     ",
        "     ",
        "\\    ",
        " \\   ",
        "  \\  "
    };

    char poleRight4[6][6] = {
        "     ",
        "     ",
        "     ",
        "|    ",
        "|    ",
        "|    "
    };

    char poleLeft0[6][6] = {
        "    |",
        "    |",
        "    T",
        "     ",
        "     ",
        "     "
    };

    char poleLeft1[6][6] = {
        "    \\",
        "   \\ ",
        "  \\  ",
        "     ",
        "     ",
        "     "
    };

    char poleLeft2[6][6] = {
        "     ",
        "     ",
        "- - -",
        "     ",
        "     ",
        "     "
    };

    char poleLeft3[6][6] = {
        "     ",
        "     ",
        "     ",
        "    /",
        "   / ",
        "  /  "
    };

    char poleLeft4[6][6] = {
        "     ",
        "     ",
        "     ",
        "    |",
        "    |",
        "    |"
    };

    int row = 6;
    int col = 5;

    //동적할당
    for (int i = 0; i < 5; i++) {
        poleRight[i] = new Cell*[row];
        poleLeft[i] = new Cell*[row];
        for (int j = 0; j < 6; j++) {
            poleRight[i][j] = new Cell[col];
            poleLeft[i][j] = new Cell[col];
        }
    }
    
    //값 설정
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            poleRight[0][i][j].value = poleRight0[i][j];
            poleRight[1][i][j].value = poleRight1[i][j];
            poleRight[2][i][j].value = poleRight2[i][j];
            poleRight[3][i][j].value = poleRight3[i][j];
            poleRight[4][i][j].value = poleRight4[i][j];
            poleLeft[0][i][j].value = poleLeft0[i][j];
            poleLeft[1][i][j].value = poleLeft1[i][j];
            poleLeft[2][i][j].value = poleLeft2[i][j];
            poleLeft[3][i][j].value = poleLeft3[i][j];
            poleLeft[4][i][j].value = poleLeft4[i][j];
        }
    }

    //색깔 설정
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < 5; k++) {
                poleRight[k][i][j].color = COLOR_YELLOW;
                poleLeft[k][i][j].color = COLOR_YELLOW;
            }
        }
    }
}

DiskShape::DiskShape() {
    disk = new Cell*[1];
    disk[0] = new Cell[1];
    disk[0][0].value = 'O';
    disk[0][0].color = COLOR_YELLOW;
}