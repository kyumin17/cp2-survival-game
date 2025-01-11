#pragma once
#include <random>
#include "enemy.hpp"
#include "../block/block_container.hpp"
#include "../../image/enemy/man_image.hpp"
#include "../../image/enemy/worm_image.hpp"
#include "../../image/enemy/explosion_image.hpp"
#include "../../image/enemy/slime_image.hpp"

using namespace std;

class EnemyContainer {
    public:
        int length;
        int max_num;
        int enemy_velocity;
        int create_freq[4];
        vector<Enemy*> array;
        EnemyContainer();
        void createEnemy(int score, BlockContainer blockContainer);
        void moveEnemy(BlockContainer blockContainer, int player_x, int player_y, int time);
        bool isEnemy(int idx);
        void draw(Display& display);
        void updateEnemy(int score);
};