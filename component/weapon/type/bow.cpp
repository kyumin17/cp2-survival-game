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
            arrowArr.push_back(new Arrow(x, y, direction, arrowLeftImage.data));
            break;
        case RIGHT:
            arrowArr.push_back(new Arrow(x + 2, y, direction, arrowRightImage.data));
            break;
        case BACK:
            arrowArr.push_back(new Arrow(x + 1, y + 2, direction, arrowUpImage.data));
            break;
        case FRONT:
            arrowArr.push_back(new Arrow(x + 1, y, direction, arrowDownImage.data));
            break;
    }
}

void Bow::changeBowDirection(int direction, int player_x, int player_y) {
    /*
    플레이어가 바라보는 방향에 따라 화살 이미지 변경
    */
    
    switch (direction) {
        case LEFT:
            changeCharacter(bowLeftImage.data, width, height);
            x = player_x - 3;
            y = player_y + 1;
            break;
        case RIGHT:
            changeCharacter(bowRightImage.data, width, height);
            x = player_x + 3;
            y = player_y + 1;
            break;
        case BACK:
            changeCharacter(bowUpImage.data, width, height);
            x = player_x;
            y = player_y + 1;
            break;
        case FRONT:
            changeCharacter(bowDownImage.data, width, height);
            x = player_x;
            y = player_y + 1;
            break;
    }
}

void Bow::drawArrows(Display& display) {
    for (size_t i = 0; i < arrowArr.size(); i++) {
        arrowArr[i] -> draw(display);
    }
}

void Bow::moveArrows() {
    for (size_t i = 0; i < arrowArr.size(); i++) {
        arrowArr[i] -> move();
    }
}

void Bow::checkCollision(vector<Enemy*>& enemyArr, vector<Block*>& blockArr) {
    size_t s = arrowArr.size();
    for (size_t i = 0; i < s; i++) {
        int enemyIdx = arrowArr[i] -> isHitEnemy(enemyArr);
        if (enemyIdx != -1) {
            if (enemyArr[enemyIdx] -> type == ENEMY4) {
                enemyArr.push_back(new Enemy(ENEMY4DIV1, enemyArr[enemyIdx] -> x, enemyArr[enemyIdx] -> y + 1, 4, 1, slimeDiv1Image.data));
                enemyArr.push_back(new Enemy(ENEMY4DIV1, enemyArr[enemyIdx] -> x + 3, enemyArr[enemyIdx] -> y - 1, 4, 1, slimeDiv1Image.data));
            } else if (enemyArr[enemyIdx] -> type == ENEMY4DIV1) {
                enemyArr.push_back(new Enemy(ENEMY4DIV2, enemyArr[enemyIdx] -> x + 3, enemyArr[enemyIdx] -> y - 1, 3, 1, slimeDiv2Image.data)); 
                enemyArr.push_back(new Enemy(ENEMY4DIV2, enemyArr[enemyIdx] -> x, enemyArr[enemyIdx] -> y + 1, 3, 1, slimeDiv2Image.data));
            } else if (enemyArr[enemyIdx] -> type == ENEMY2) {
                enemyArr.push_back(new Enemy(ENEMY2EXPLORE, enemyArr[enemyIdx] -> x - 5, enemyArr[enemyIdx] -> y - 1, 13, 5, explosionDeadImage.data));
            }

            if (enemyArr[enemyIdx] -> type != ENEMY2EXPLORE) {
                enemyArr.erase(enemyArr.begin() + enemyIdx);
            }
        } else if (arrowArr[i] -> isHitBlock(blockArr)) {
            arrowArr.erase(arrowArr.begin() + i);
        }
    }
}