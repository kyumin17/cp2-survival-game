#include "weapon_manager.hpp"

WeaponManager::WeaponManager(int player_x, int player_y): weapon_type(1) {
    bow = new Bow(player_x, player_y + 1, bowDownImage.data);
    sword = new Sword(player_x + 3, player_y - 2, swordRightImageArr[0].data);
}

void WeaponManager::draw(Display& display) {
    switch(weapon_type) {
        case 1:
            bow -> draw(display);
            bow -> drawArrows(display);
            break;
        case 2:
            sword -> draw(display);
            break;
    }
}

void WeaponManager::changeWeapon() {
    weapon_type = weapon_type == 1 ? 2 : 1;
}

void WeaponManager::updateWeapon(int input, int time, Player* player, EnemyContainer& enemyContainer, BlockContainer& blockContainer) {
    switch (weapon_type) {
        case 1:
            //플레이어 방향에 따라 활 방향 변경
            bow -> changeBowDirection(player -> direction, player -> x, player -> y);
            for (size_t i = 0; i < bow -> arrowArr.size(); i++) {
                //플레이어 움직임에 따라 활 움직임
                switch(input) {
                    case LEFT:
                        bow -> arrowArr[i] -> x++;
                        break;
                    case RIGHT:
                        bow -> arrowArr[i] -> x--;
                        break;
                    case BACK:
                        bow -> arrowArr[i] -> y--;
                        break;
                    case FRONT:
                        bow -> arrowArr[i] -> y++;
                        break;
                }
            }
            //시간에 따라 활 움직임
            if (time % 10 == 0) {
                if (bow -> attackTime != 0) bow -> attackTime++;
                bow -> moveArrows();
                bow -> checkCollision(enemyContainer.array, blockContainer.array); //충돌 시 활 없애기
                if (bow -> attackTime == bow -> cooldown) { //쿨타임
                    bow -> attackTime = 0;
                }
            }
            break;
        case 2:
            sword -> changeSwordDirection(player -> direction, player -> x);
            //시간에 따라 막대기 움직임
            if (time % 5 == 0) {
                if (sword -> attackTime != 0) {
                    sword -> attack(player -> direction, player -> x, enemyContainer.array);
                    sword -> attackTime++;
                }
                if (sword -> attackTime == sword -> cooldown) {
                    sword -> attackTime = 0;
                }
            }
            break;
    }
}

void WeaponManager::attack(int direction) {
    /*
    공격 키 입력했을 때 실행
    */
    switch(weapon_type) {
        case 1:
            if (bow -> attackTime == 0) {
                bow -> attackTime = 1;
                bow -> attack(direction);
            }
            break;
        case 2:
            if (sword -> attackTime == 0) {
                sword -> attackTime = 1;
            }
            break;
    }
}