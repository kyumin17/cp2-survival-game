#include "player.hpp"

Player::Player(int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    direction = FRONT;
}

void Player::move(int input, vector<Enemy*>& enemyArr, vector<Block*>& blockArr, PlayerCharacter playerCharacter) {
    /*
    플레이어의 움직임에 따라 배경을 움직인다.
    */
    int dx = 0;
    int dy = 0;

    switch (input) {
        case LEFT:
            direction = LEFT;
            changeCharacter(playerCharacter.left);
            dx = 1;
            break;
        case RIGHT:
            direction = RIGHT;
            changeCharacter(playerCharacter.right);
            dx = -1;
            break;
        case BACK:
            direction = BACK;
            changeCharacter(playerCharacter.back);
            dy = -1;
            break;
        case FRONT:
            direction = FRONT;
            changeCharacter(playerCharacter.front);
            dy = 1;
            break;
    }

    for (size_t i = 0; i < enemyArr.size(); i++) {
        (enemyArr[i] -> x) += dx;
        (enemyArr[i] -> y) += dy;
    }
    for (size_t i = 0; i < blockArr.size(); i++) {
        (blockArr[i] -> x) += dx;
        (blockArr[i] -> y) += dy;
    }
}

bool Player::isTouch(vector<Enemy*>& enemyArr) {
    /*
    플레이어가 적과 만날 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */
    for (size_t i = 0; i < enemyArr.size(); i++) {
        int ex = enemyArr[i] -> x;
        int ey = enemyArr[i] -> y;
        if (-3 < x - ex && x - ex < 3 && -3 < y - ey && y - ey < 3) {
            return true;
        }
    }
    return false;
}

bool Player::isBlock(vector<Block*>& blockArr, int input) {
    /*
    플레이어가 블록과 충돌할 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */
    for (size_t i = 0; i < blockArr.size(); i++) {
        int bx = blockArr[i] -> x;
        int by = blockArr[i] -> y;
        int bh = blockArr[i] -> height;
        
        if (input == LEFT && x == bx + bh * 2 && by - 2 <= y && y <= by + bh - 1) {
            return 1;
        } else if (input == RIGHT && x + 3 == bx && by - 2 <= y && y <= by + bh - 1) {
            return 1;
        } else if (input == BACK && y + 3 == by && bx - 3 <= x && x <= bx + bh * 2 - 1) {
            return 1;
        } else if (input == FRONT && y == by + bh && bx - 3 <= x && x <= bx + bh * 2 - 1) {
            return 1;
        }
    }
    
    return false;
}