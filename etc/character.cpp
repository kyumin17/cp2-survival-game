#include "character.hpp"

PlayerCharacter::PlayerCharacter() {
    char leftTxt[4][6] = {
        "     ",
        " :o  ",
        " /|\\ ",
        " / \\ "
    };

    char rightTxt[4][6] = {
        "     ",
        "  o: ",
        " /|\\ ",
        " / \\ "
    };


    char backTxt[4][6] = {
        "  .  ",
        "  o  ",
        " /|\\ ",
        " / \\ "
    };

    char frontTxt[4][6] = {
        "     ",
        "  o  ",
        " /|\\ ",
        " / \\ "
    };

    int row = 4;
    int col = 5;

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
    char frontTxt[4][6] = {
        "     ",
        "  #  ",
        " /|\\ ",
        " / \\ "
    };

    int row = 4;
    int col = 5;

    front = new Cell*[row];

    for (int i = 0; i < row; i++) {
        front[i] = new Cell[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            front[i][j].value = frontTxt[i][j];
            front[i][j].color = COLOR_GREEN;
        }
    }
}

BulletShape::BulletShape() {
    bullet = new Cell*[1];
    bullet[0] = new Cell[1];

    bullet[0][0].value = '*';
    bullet[0][0].color = COLOR_WHITE;
}