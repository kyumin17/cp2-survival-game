#include "bow.hpp"

Bow::Bow(int _x, int _y, Cell** _character)
: Weapon(_x, _y, 3, 1, 5, _character) {
    
}

void Bow::attack(int direction) {
    /*
    공격 방향에 따라 화살 배열에 화살 추가
    */

    switch(direction) {
        case LEFT:
            arrow_arr.push_back(new Arrow(x, y, direction, arrow_left_image.data));
            break;
        case RIGHT:
            arrow_arr.push_back(new Arrow(x + 2, y, direction, arrow_right_image.data));
            break;
        case BACK:
            arrow_arr.push_back(new Arrow(x + 1, y + 2, direction, arrow_up_image.data));
            break;
        case FRONT:
            arrow_arr.push_back(new Arrow(x + 1, y, direction, arrow_down_image.data));
            break;
    }
}

void Bow::changeBowDirection(int direction, int player_x, int player_y) {
    /*
    플레이어가 바라보는 방향에 따라 화살 이미지 변경
    */
    
    switch (direction) {
        case LEFT:
            changeCharacter(bow_left_image.data, width, height);
            x = player_x - 3;
            y = player_y + 1;
            break;
        case RIGHT:
            changeCharacter(bow_right_image.data, width, height);
            x = player_x + 3;
            y = player_y + 1;
            break;
        case BACK:
            changeCharacter(bow_up_image.data, width, height);
            x = player_x;
            y = player_y + 1;
            break;
        case FRONT:
            changeCharacter(bow_down_image.data, width, height);
            x = player_x;
            y = player_y + 1;
            break;
    }
}

void Bow::drawArrows(Display& display) {
    for (size_t i = 0; i < arrow_arr.size(); i++) {
        arrow_arr[i] -> draw(display);
    }
}

void Bow::moveArrows() {
    for (size_t i = 0; i < arrow_arr.size(); i++) {
        arrow_arr[i] -> move();
    }
}

void Bow::checkCollision(vector<Enemy*>& enemy_arr, vector<Block*>& block_arr) {
    size_t s = arrow_arr.size();
    for (size_t i = 0; i < s; i++) {
        int enemyIdx = arrow_arr[i] -> isHitEnemy(enemy_arr);
        if (enemyIdx != -1) {
            if (enemy_arr[enemyIdx] -> type == ENEMY4) {
                enemy_arr.push_back(new Enemy(ENEMY4DIV1, enemy_arr[enemyIdx] -> x, enemy_arr[enemyIdx] -> y + 1, 4, 1, slime_div1_image.data));
                enemy_arr.push_back(new Enemy(ENEMY4DIV1, enemy_arr[enemyIdx] -> x + 3, enemy_arr[enemyIdx] -> y - 1, 4, 1, slime_div1_image.data));
            } else if (enemy_arr[enemyIdx] -> type == ENEMY4DIV1) {
                enemy_arr.push_back(new Enemy(ENEMY4DIV2, enemy_arr[enemyIdx] -> x + 3, enemy_arr[enemyIdx] -> y - 1, 3, 1, slime_div2_image.data)); 
                enemy_arr.push_back(new Enemy(ENEMY4DIV2, enemy_arr[enemyIdx] -> x, enemy_arr[enemyIdx] -> y + 1, 3, 1, slime_div2_image.data));
            } else if (enemy_arr[enemyIdx] -> type == ENEMY2) {
                enemy_arr.push_back(new Enemy(ENEMY2EXPLORE, enemy_arr[enemyIdx] -> x - 5, enemy_arr[enemyIdx] -> y - 1, 13, 5, explosion_dead_image.data));
            }

            if (enemy_arr[enemyIdx] -> type != ENEMY2EXPLORE) {
                enemy_arr.erase(enemy_arr.begin() + enemyIdx);
            }
        } else if (arrow_arr[i] -> isHitBlock(block_arr)) {
            arrow_arr.erase(arrow_arr.begin() + i);
        }
    }
}