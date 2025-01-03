#include "sword.hpp"

Sword::Sword(int _x, int _y, Cell** _character)
: Weapon(_x, _y, 5, 6, 7, _character) {
    direction = RIGHT;
}

void Sword::attack(int input, int playerX, vector<Enemy*>& enemyArr) {
    if (input == RIGHT || input == LEFT) direction = input;

    if (attackTime > 5) return; 

    if (direction == RIGHT) {
        x = playerX + 3;
        changeCharacter(swordRightImageArr[attackTime - 1].data, width, height);
    } else if (direction == LEFT) {
        x = playerX - 5;
        changeCharacter(swordLeftImageArr[attackTime - 1].data, width, height);
    }
    
    for (size_t i = 0; i < enemyArr.size(); i++) {
        int ex = enemyArr[i] -> x;
        int ey = enemyArr[i] -> y;
        int ew = enemyArr[i] -> width;
        int eh = enemyArr[i] -> height;

        if (y <= ey + eh - 1 && ey <= y + height - 1 && x <= ex + ew - 1 && ex <= x + width - 1) {
            if (enemyArr[i] -> type == ENEMY4) {
                enemyArr.push_back(new Enemy(ENEMY4DIV1, enemyArr[i] -> x, enemyArr[i] -> y + 1, 4, 1, slimeDiv1Image.data));
                enemyArr.push_back(new Enemy(ENEMY4DIV1, enemyArr[i] -> x + 3, enemyArr[i] -> y - 1, 4, 1, slimeDiv1Image.data));
            } else if (enemyArr[i] -> type == ENEMY4DIV1) {
                enemyArr.push_back(new Enemy(ENEMY4DIV2, enemyArr[i] -> x + 3, enemyArr[i] -> y - 1, 3, 1, slimeDiv2Image.data)); 
                enemyArr.push_back(new Enemy(ENEMY4DIV2, enemyArr[i] -> x, enemyArr[i] -> y + 1, 3, 1, slimeDiv2Image.data));
            } else if (enemyArr[i] -> type == ENEMY2) {
                enemyArr.push_back(new Enemy(ENEMY2EXPLORE, enemyArr[i] -> x - 5, enemyArr[i] -> y - 1, 13, 5, explosionDeadImage.data));
            }

            if (enemyArr[i] -> type != ENEMY2EXPLORE) {
                enemyArr.erase(enemyArr.begin() + i);
            }
        }
    }
}

void Sword::changeSwordDirection(int input, int playerX) {
    if (input == RIGHT || input == LEFT) direction = input;

    if (direction == LEFT) {
        x = playerX - 5;
        changeCharacter(swordLeftImageArr[0].data, width, height);
    } else if (direction == RIGHT) {
        x = playerX + 3;
        changeCharacter(swordRightImageArr[0].data, width, height);
    }
}