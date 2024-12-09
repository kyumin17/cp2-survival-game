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

    char enemy2Txt[3][4] = {
        "(!)",
        "/|\\",
        "/ \\"
    };

    char enemy2DeadTxt[5][8] = {
        "   |   ",
        " \\   / ",
        "-     -",
        " /   \\ ",
        "   |   "
    };

    char enemy3RightTxt[1][5] = {
       "~~~@"
    };

    char enemy3LeftTxt[1][5] = {
       "@~~~"
    };

    char enemy4Txt[2][5] = {
       " /\\ ",
       "(++)"
    };

    char enemy4Div1Txt[1][5] = {
        "(++)"
    };

    char enemy4Div2Txt[1][4] = {
        "(+)"
    };

    //enemy1
    int row1 = 3;
    int col1 = 3;

    enemy1 = new Cell*[row1];

    for (int i = 0; i < row1; i++) {
        enemy1[i] = new Cell[col1];
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            enemy1[i][j].value = enemy1Txt[i][j];
            enemy1[i][j].color = COLOR_GREEN;
        }
    }

    //enemy2
    int row2 = 3;
    int col2 = 3;

    enemy2 = new Cell*[row2];
    enemy2Dead = new Cell*[5];

    for (int i = 0; i < row2; i++) {
        enemy2[i] = new Cell[col2];
    }

    for (int i = 0; i < 7; i++) {
        enemy2Dead[i] = new Cell[7];
    }

    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            enemy2[i][j].value = enemy2Txt[i][j];
            enemy2[i][j].color = COLOR_GREEN;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            enemy2Dead[i][j].value = enemy2DeadTxt[i][j];
            enemy2Dead[i][j].color = COLOR_GREEN;
        }
    }

    //enemy3
    int row3 = 1;
    int col3 = 4;

    enemy3Right = new Cell*[row3];
    enemy3Left = new Cell*[row3];

    for (int i = 0; i < row3; i++) {
        enemy3Right[i] = new Cell[col3];
        enemy3Left[i] = new Cell[col3];
    }

    for (int i = 0; i < row3; i++) {
        for (int j = 0; j < col3; j++) {
            enemy3Right[i][j].value = enemy3RightTxt[i][j];
            enemy3Right[i][j].color = COLOR_GREEN;
            enemy3Left[i][j].value = enemy3LeftTxt[i][j];
            enemy3Left[i][j].color = COLOR_GREEN;
        }
    }

    //enemy4
    int row4 = 2;
    int col4 = 4;

    enemy4 = new Cell*[row4];
    enemy4Div1 = new Cell*[1];
    enemy4Div2 = new Cell*[1];

    for (int i = 0; i < row4; i++) {
        enemy4[i] = new Cell[col4];
        enemy4Div1[i] = new Cell[4];
        enemy4Div2[i] = new Cell[3];
    }

    for (int i = 0; i < row4; i++) {
        for (int j = 0; j < col4; j++) {
            enemy4[i][j].value = enemy4Txt[i][j];
            enemy4[i][j].color = COLOR_GREEN;
        }
    }

    for (int i = 0; i < 4; i++) {
        enemy4Div1[0][i].value = enemy4Div1Txt[0][i];
        enemy4Div1[0][i].color = COLOR_GREEN;
    }

    for (int i = 0; i < 3; i++) {
        enemy4Div2[0][i].value = enemy4Div2Txt[0][i];
        enemy4Div2[0][i].color = COLOR_GREEN;
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

SwordShape::SwordShape() {
    char swordRight0[6][6] = {
        "|    ",
        "|    ",
        "T    ",
        "     ",
        "     ",
        "     "
    };

    char swordRight1[6][6] = {
        "  /  ",
        " /   ",
        "/    ",
        "     ",
        "     ",
        "     "
    };

    char swordRight2[6][6] = {
        "     ",
        "     ",
        "- - -",
        "     ",
        "     ",
        "     "
    };

    char swordRight3[6][6] = {
        "     ",
        "     ",
        "     ",
        "\\    ",
        " \\   ",
        "  \\  "
    };

    char swordRight4[6][6] = {
        "     ",
        "     ",
        "     ",
        "|    ",
        "|    ",
        "|    "
    };

    char swordLeft0[6][6] = {
        "    |",
        "    |",
        "    T",
        "     ",
        "     ",
        "     "
    };

    char swordLeft1[6][6] = {
        "  \\  ",
        "   \\ ",
        "    \\",
        "     ",
        "     ",
        "     "
    };

    char swordLeft2[6][6] = {
        "     ",
        "     ",
        "- - -",
        "     ",
        "     ",
        "     "
    };

    char swordLeft3[6][6] = {
        "     ",
        "     ",
        "     ",
        "    /",
        "   / ",
        "  /  "
    };

    char swordLeft4[6][6] = {
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
        swordRight[i] = new Cell*[row];
        swordLeft[i] = new Cell*[row];
        for (int j = 0; j < 6; j++) {
            swordRight[i][j] = new Cell[col];
            swordLeft[i][j] = new Cell[col];
        }
    }
    
    //값 설정
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            swordRight[0][i][j].value = swordRight0[i][j];
            swordRight[1][i][j].value = swordRight1[i][j];
            swordRight[2][i][j].value = swordRight2[i][j];
            swordRight[3][i][j].value = swordRight3[i][j];
            swordRight[4][i][j].value = swordRight4[i][j];
            swordLeft[0][i][j].value = swordLeft0[i][j];
            swordLeft[1][i][j].value = swordLeft1[i][j];
            swordLeft[2][i][j].value = swordLeft2[i][j];
            swordLeft[3][i][j].value = swordLeft3[i][j];
            swordLeft[4][i][j].value = swordLeft4[i][j];
        }
    }

    //색깔 설정
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < 5; k++) {
                swordRight[k][i][j].color = COLOR_YELLOW;
                swordLeft[k][i][j].color = COLOR_YELLOW;
            }
        }
    }
}

EraserShape::EraserShape() {
    char activateTxt[5][8] = {
        "  * *  ",
        " *   * ",
        "*     *",
        " *   * ",
        "  * *  "
    };

    char nonactiveTxt[5][8] = {
        "       ",
        "       ",
        "*     *",
        "       ",
        "       "
    };


    int row = 5;
    int col = 7;

    eraserNonactive = new Cell*[row];
    eraserActive = new Cell*[row];
    for (int i = 0; i < row; i++) {
        eraserNonactive[i] = new Cell[col];
        eraserActive[i] = new Cell[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            eraserNonactive[i][j].value = nonactiveTxt[i][j];
            eraserNonactive[i][j].color = COLOR_YELLOW;
            eraserActive[i][j].value = activateTxt[i][j];
            eraserActive[i][j].color = COLOR_YELLOW;
        }
    }
}