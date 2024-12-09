#include "player.hpp"

Player::Player(int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    direction = FRONT;
}

void Player::move(int input, vector<Enemy*>& enemyArr, vector<Block*>& blockArr, PlayerCharacter playerCharacter) {
    /*
    플레이어의 움직임에 따라 배경을 움직임
    */

    int dx = 0;
    int dy = 0;

    switch (input) {
        case LEFT:
            direction = LEFT;
            changeCharacter(playerCharacter.left, width, height);
            dx = 1;
            break;
        case RIGHT:
            direction = RIGHT;
            changeCharacter(playerCharacter.right, width, height);
            dx = -1;
            break;
        case BACK:
            direction = BACK;
            changeCharacter(playerCharacter.back, width, height);
            dy = -1;
            break;
        case FRONT:
            direction = FRONT;
            changeCharacter(playerCharacter.front, width, height);
            dy = 1;
            break;
    }

    /*방향에 맞게 배경을 움직임*/
    for (size_t i = 0; i < enemyArr.size(); i++) {
        (enemyArr[i] -> x) += dx;
        (enemyArr[i] -> y) += dy;
    }
    for (size_t i = 0; i < blockArr.size(); i++) {
        (blockArr[i] -> x) += dx;
        (blockArr[i] -> y) += dy;
    }
}

bool Player::isDamaged(vector<Enemy*>& enemyArr) {
    /*
    플레이어가 적과 만날 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */

    for (size_t i = 0; i < enemyArr.size(); i++) {
        int ex = enemyArr[i] -> x;
        int ey = enemyArr[i] -> y;
        int ew = enemyArr[i] -> width;
        int eh = enemyArr[i] -> height;

        if (x + width - 1 >= ex && x <= ex + ew - 1 && y + height - 1 >= ey && y <= ey + eh - 1) { //overlap 판단
            return true;
        }
    }

    return false;
}

bool Player::isBlock(vector<Block*>& blockArr, int input, bool& end) {
    /*
    플레이어가 블록과 충돌할 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */

    bool isCollision = false;
    int collisionIdx = -1;
    for (size_t i = 0; i < blockArr.size(); i++) {
        int bx = blockArr[i] -> x;
        int by = blockArr[i] -> y;
        int bh = blockArr[i] -> height;
        
        if (input == LEFT && x == bx + bh * 2 && by - 2 <= y && y <= by + bh - 1) {
            isCollision = true;
            collisionIdx = i;
        } else if (input == RIGHT && x + 3 == bx && by - 2 <= y && y <= by + bh - 1) {
            isCollision = true;
            collisionIdx = i;
        } else if (input == BACK && y + 3 == by && bx - 3 <= x && x <= bx + bh * 2 - 1) {
            isCollision = true;
            collisionIdx = i;
        } else if (input == FRONT && y == by + bh && bx - 3 <= x && x <= bx + bh * 2 - 1) {
            isCollision = true;
            collisionIdx = i;
        }
    }

    if (isCollision && blockArr[collisionIdx] -> isAttack) {
        end = true; //플레이어에게 피해를 주는 블록에 충돌했을 시 게임 끝냄
    } 

    return isCollision;
}