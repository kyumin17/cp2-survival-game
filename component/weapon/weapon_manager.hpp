#pragma once
#include "type/arrow.hpp"
#include "type/bow.hpp"
#include "type/sword.hpp"
#include "../enemy/enemy_container.hpp"
#include "../block/block_container.hpp"
#include "../player/player.hpp"

class WeaponManager {
    public:
        int weapon_type;
        Bow* bow;
        Sword* sword;
        WeaponManager(int player_x, int player_y);
        void draw(Display& display);
        void changeWeapon();
        void updateWeapon(int input, int time, Player* player, EnemyContainer& enemy_container, BlockContainer& block_container);
        void attack(int direction);
};