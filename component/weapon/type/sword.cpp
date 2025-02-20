#include "sword.hpp"

Sword::Sword(int _x, int _y, Cell** _character)
: Weapon(_x, _y, 5, 6, 7, _character) {
    direction = RIGHT;
}

void Sword::attack(int input, int player_x, vector<Enemy*>& enemy_arr) {
    if (input == RIGHT || input == LEFT) direction = input;

    if (attack_time > 5) return; 

    if (direction == RIGHT) {
        x = player_x + 3;
        changeCharacter(sword_right_image_array[attack_time - 1].data, width, height);
    } else if (direction == LEFT) {
        x = player_x - 5;
        changeCharacter(sword_left_image_array[attack_time - 1].data, width, height);
    }
    
    for (size_t i = 0; i < enemy_arr.size(); i++) {
        int ex = enemy_arr[i] -> x;
        int ey = enemy_arr[i] -> y;
        int ew = enemy_arr[i] -> width;
        int eh = enemy_arr[i] -> height;

        if (y <= ey + eh - 1 && ey <= y + height - 1 && x <= ex + ew - 1 && ex <= x + width - 1) {
            if (enemy_arr[i] -> type == ENEMY4) {
                enemy_arr.push_back(new Enemy(ENEMY4DIV1, enemy_arr[i] -> x, enemy_arr[i] -> y + 1, 4, 1, slime_div1_image.data));
                enemy_arr.push_back(new Enemy(ENEMY4DIV1, enemy_arr[i] -> x + 3, enemy_arr[i] -> y - 1, 4, 1, slime_div1_image.data));
            } else if (enemy_arr[i] -> type == ENEMY4DIV1) {
                enemy_arr.push_back(new Enemy(ENEMY4DIV2, enemy_arr[i] -> x + 3, enemy_arr[i] -> y - 1, 3, 1, slime_div2_image.data)); 
                enemy_arr.push_back(new Enemy(ENEMY4DIV2, enemy_arr[i] -> x, enemy_arr[i] -> y + 1, 3, 1, slime_div2_image.data));
            } else if (enemy_arr[i] -> type == ENEMY2) {
                enemy_arr.push_back(new Enemy(ENEMY2EXPLORE, enemy_arr[i] -> x - 5, enemy_arr[i] -> y - 1, 13, 5, explosion_dead_image.data));
            }

            if (enemy_arr[i] -> type != ENEMY2EXPLORE) {
                enemy_arr.erase(enemy_arr.begin() + i);
            }
        }
    }
}

void Sword::changeSwordDirection(int input, int player_x) {
    if (input == RIGHT || input == LEFT) direction = input;

    if (direction == LEFT) {
        x = player_x - 5;
        changeCharacter(sword_left_image_array[0].data, width, height);
    } else if (direction == RIGHT) {
        x = player_x + 3;
        changeCharacter(sword_right_image_array[0].data, width, height);
    }
}