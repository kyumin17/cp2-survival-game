#include "player.hpp"

Player::Player(int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    direction = FRONT;
}

void Player::move(int input, vector<Enemy*>& enemy, vector<Block*>& block, vector<Bullet*>& bullet, PlayerCharacter playerCharacter) {
    switch (input) {
        case LEFT:
            direction = LEFT;
            changeCharacter(playerCharacter.left);
            for (size_t i = 0; i < enemy.size(); i++) {
                enemy[i] -> x++;
            }
            for (size_t i = 0; i < block.size(); i++) {
                block[i] -> x++;
            }
            for (size_t i = 0; i < bullet.size(); i++) {
                bullet[i] -> x++;
            }
            break;
        case RIGHT:
            direction = RIGHT;
            changeCharacter(playerCharacter.right);
            for (size_t i = 0; i < enemy.size(); i++) {
                enemy[i] -> x--;
            }
            for (size_t i = 0; i < block.size(); i++) {
                block[i] -> x--;
            }
            for (size_t i = 0; i < bullet.size(); i++) {
                bullet[i] -> x--;
            }
            break;
        case BACK:
            direction = BACK;
            changeCharacter(playerCharacter.back);
            if (3 <= y && y < 15) y++;
            break;
        case FRONT:
            direction = FRONT;
            changeCharacter(playerCharacter.front);
            if (3 < y && y <= 15) y--;
            break;
    }
}

void Player::attack(vector<Bullet*>& bullet) {
    BulletShape bulletShape;
    int dx, dy;

    switch (direction) {
        case LEFT:
            dx = 0;
            dy = 1;
            break;
        case RIGHT:
            dx = 4;
            dy = 1;
            break;
        case BACK:
            dx = 2;
            dy = 3;
            break;
        case FRONT:
            dx = 2;
            dy = -1;
            break;
    }

    bullet.push_back(new Bullet(1, direction, x + dx, y + dy, 1, 1, bulletShape.bullet));
}

bool Player::isTouch(vector<Enemy*>& enemy) {
    /*
    플레이어가 적과 만날 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */
    for (size_t i = 0; i < enemy.size(); i++) {
        int ex = enemy[i] -> x;
        int ey = enemy[i] -> y;
        if (-3 < x - ex && x - ex < 3 && -3 < y - ey && y - ey < 3) {
            return true;
        }
    }
    return false;
}

bool Player::isBlock(vector<Block*>& block, int input) {
    /*
    플레이어가 블록과 충돌할 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */
    for (size_t i = 0; i < block.size(); i++) {
        int bx = block[i] -> x;
        int by = block[i] -> y;
        int bw = block[i] -> width;
        int bh = block[i] -> height;
        
        if (input == LEFT && x == bx + bw - 1 && by - 2 <= y && y <= by + bh - 1) {
            return 1;
        } else if (input == RIGHT && x + 4 == bx && by - 2 <= y && y <= by + bh - 1) {
            return 1;
        } else if (input == BACK && y + 3 == by && bx - 3 <= x && x <= bx + bw - 2) {
            return 1;
        } else if (input == FRONT && y == by + bh && bx - 3 <= x && x <= bx + bw - 2) {
            return 1;
        }
    }
    return 0;
}