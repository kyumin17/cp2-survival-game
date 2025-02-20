#include "weapon_manager.hpp"

WeaponManager::WeaponManager(int player_x, int player_y): weapon_type(1) {
    bow = new Bow(player_x, player_y + 1, bow_down_image.data);
    sword = new Sword(player_x + 3, player_y - 2, sword_right_image_array[0].data);
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

void WeaponManager::updateWeapon(int input, int time, Player* player, EnemyContainer& enemy_container, BlockContainer& block_container) {
    switch (weapon_type) {
        case 1:
            //플레이어 방향에 따라 활 방향 변경
            bow -> changeBowDirection(player -> direction, player -> x, player -> y);
            for (size_t i = 0; i < bow -> arrow_arr.size(); i++) {
                //플레이어 움직임에 따라 활 움직임
                switch(input) {
                    case LEFT:
                        bow -> arrow_arr[i] -> x++;
                        break;
                    case RIGHT:
                        bow -> arrow_arr[i] -> x--;
                        break;
                    case BACK:
                        bow -> arrow_arr[i] -> y--;
                        break;
                    case FRONT:
                        bow -> arrow_arr[i] -> y++;
                        break;
                }
            }
            //시간에 따라 활 움직임
            if (time % 10 == 0) {
                if (bow -> attack_time != 0) bow -> attack_time++;
                bow -> moveArrows();
                bow -> checkCollision(enemy_container.array, block_container.array); //충돌 시 활 없애기
                if (bow -> attack_time == bow -> cooldown) { //쿨타임
                    bow -> attack_time = 0;
                }
            }
            break;
        case 2:
            sword -> changeSwordDirection(player -> direction, player -> x);
            //시간에 따라 막대기 움직임
            if (time % 5 == 0) {
                if (sword -> attack_time != 0) {
                    sword -> attack(player -> direction, player -> x, enemy_container.array);
                    sword -> attack_time++;
                }
                if (sword -> attack_time == sword -> cooldown) {
                    sword -> attack_time = 0;
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
            if (bow -> attack_time == 0) {
                bow -> attack_time = 1;
                bow -> attack(direction);
            }
            break;
        case 2:
            if (sword -> attack_time == 0) {
                sword -> attack_time = 1;
            }
            break;
    }
}