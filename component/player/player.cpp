#include "player.hpp"

Player::Player(int _x, int _y, int _width, int _height, Cell** _image)
: Component(_x, _y, _width, _height, _image) {
    direction = FRONT;
}

void Player::move(int input, vector<Enemy*>& enemy_arr, vector<Block*>& block_arr) {
    /*
    플레이어의 움직임에 따라 배경을 움직임
    */

    int dx = 0;
    int dy = 0;

    switch (input) {
        case LEFT:
            direction = LEFT;
            changeCharacter(player_left_image.data, width, height);
            dx = 1;
            break;
        case RIGHT:
            direction = RIGHT;
            changeCharacter(player_right_image.data, width, height);
            dx = -1;
            break;
        case BACK:
            direction = BACK;
            changeCharacter(player_up_image.data, width, height);
            dy = -1;
            break;
        case FRONT:
            direction = FRONT;
            changeCharacter(player_down_image.data, width, height);
            dy = 1;
            break;
    }

    /*방향에 맞게 배경을 움직임*/
    for (size_t i = 0; i < enemy_arr.size(); i++) {
        (enemy_arr[i] -> x) += dx;
        (enemy_arr[i] -> y) += dy;
    }
    for (size_t i = 0; i < block_arr.size(); i++) {
        (block_arr[i] -> x) += dx;
        (block_arr[i] -> y) += dy;
    }
}

bool Player::isDamaged(vector<Enemy*>& enemy_arr) {
    /*
    플레이어가 적과 만날 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */

    for (size_t i = 0; i < enemy_arr.size(); i++) {
        int ex = enemy_arr[i] -> x;
        int ey = enemy_arr[i] -> y;
        int ew = enemy_arr[i] -> width;
        int eh = enemy_arr[i] -> height;

        if (x + width - 1 >= ex && x <= ex + ew - 1 && y + height - 1 >= ey && y <= ey + eh - 1) { //overlap 판단
            return true;
        }
    }

    return false;
}

bool Player::isBlock(vector<Block*>& block_arr, int input, bool& end) {
    /*
    플레이어가 블록과 충돌할 경우 true를 반환하고, 그렇지 않은 경우 false를 반환한다.
    */

    bool is_collision = false;
    int collision_idx = -1;
    for (size_t i = 0; i < block_arr.size(); i++) {
        int bx = block_arr[i] -> x;
        int by = block_arr[i] -> y;
        int bh = block_arr[i] -> height;
        
        if (input == LEFT && x == bx + bh * 2 && by - 2 <= y && y <= by + bh - 1) {
            is_collision = true;
            collision_idx = i;
        } else if (input == RIGHT && x + 3 == bx && by - 2 <= y && y <= by + bh - 1) {
            is_collision = true;
            collision_idx = i;
        } else if (input == BACK && y + 3 == by && bx - 3 <= x && x <= bx + bh * 2 - 1) {
            is_collision = true;
            collision_idx = i;
        } else if (input == FRONT && y == by + bh && bx - 3 <= x && x <= bx + bh * 2 - 1) {
            is_collision = true;
            collision_idx = i;
        }
    }

    if (is_collision && block_arr[collision_idx] -> is_attack) {
        end = true; //플레이어에게 피해를 주는 블록에 충돌했을 시 게임 끝냄
    } 

    return is_collision;
}