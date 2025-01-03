#pragma once
#include <vector>
#include <random>
#include "../component/enemy/enemy.hpp"
#include "../component/weapon/bow.hpp"
#include "../component/weapon/sword.hpp"
#include "../component/block/block.hpp"
#include "../component/player/player.hpp"
#include "../image/enemy/man-image.hpp"
#include "../image/enemy/worm-image.hpp"

class Game {
    public:
        Display display;
        Player* player;
        vector<Enemy*> enemyArr;
        vector<Block*> blockArr;

        int weaponType;
        Bow* bow;
        Sword* sword;

        int enemyNum; //맵의 전체 적 개수
        int time;
        int score;
        bool end;
        int enemyVelocity;
        int freq[4];

        Game();
        int getDirection(char ch);
        void createBlock(int blockNum);
        void createEnemy();
        void draw();
        void moveEnemy();
        bool isEnemy(int idx);
        void movePlayer(int direction);
        void changeWeapon(int type);
        void updateWeapon(int input);
        void attack();
        void printBackground();
        void updateEnemy();
};