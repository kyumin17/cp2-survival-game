#include "player.hpp"

Player::Player(int _hp, int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    hp = _hp;
    state = FRONT;
}

void Player::move(int direction, Enemy* enemy[], int& enemyNum, Block* block[], int& blockNum, PlayerCharacter playerCharacter) {
    switch (direction) {
        case LEFT:
            state = LEFT;
            changeCharacter(playerCharacter.left);
            for (int i = 0; i < enemyNum; i++) {
                enemy[i] -> x++;
            }
            for (int i = 0; i < blockNum; i++) {
                block[i] -> x++;
            }
            break;
        case RIGHT:
            state = RIGHT;
            changeCharacter(playerCharacter.right);
            for (int i = 0; i < enemyNum; i++) {
                enemy[i] -> x--;
            }
            for (int i = 0; i < blockNum; i++) {
                block[i] -> x--;
            }
            break;
        case BACK:
            state = BACK;
            changeCharacter(playerCharacter.back);
            if (3 <= y && y < 17) y++;
            break;
        case FRONT:
            state = FRONT;
            changeCharacter(playerCharacter.front);
            if (3 < y && y <= 17) y--;
            break;
    }
}

void Player::attack(Bullet* bullet[], int& bulletNum) {
    for (int i = 0; i < bulletNum; i++) {
        
    }
}

bool Player::isTouch(Enemy* enemy[], int& enemyNum) {
    /*
    플레이어가 적과 만날 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */
    for (int i = 0; i < enemyNum; i++) {
        int ex = enemy[i] -> x;
        int ey = enemy[i] -> y;
        if (-3 < x - ex && x - ex < 3 && -3 < y - ey && y - ey < 3) {
            return true;
        }
    }
    return false;
}

bool Player::isBlock(Block* block[], int& blockNum, int direction) {
    /*
    플레이어가 블록과 충돌할 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */

    for (int i = 0; i < blockNum; i++) {
        int bx = block[i] -> x;
        int by = block[i] -> y;
        int bw = block[i] -> width;
        int bh = block[i] -> height;
        
        if (direction == LEFT && x == bx + bw - 1 && by - 2 <= y && y <= by + bh - 1) {
            return 1;
        } else if (direction == RIGHT && x + 4 == bx && by - 2 <= y && y <= by + bh - 1) {
            return 1;
        } else if (direction == BACK && y + 3 == by && bx - 3 <= x && x <= bx + bw - 2) {
            return 1;
        } else if (direction == FRONT && y == by + bh && bx - 3 <= x && x <= bx + bw - 2) {
            return 1;
        }
    }
    return 0;
}