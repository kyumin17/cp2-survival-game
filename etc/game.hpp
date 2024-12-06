#pragma once
#include <vector>
#include <random>
#include <cmath>
#include "../component/player.hpp"
#include "../component/enemy.hpp"
#include "../component/weapon.hpp"
#include "../component/block.hpp"
#include "character.hpp"

class Game {
    public:
        Display display;
        Player* player;
        vector<Enemy*> enemyArr;
        vector<Block*> blockArr;

        int weaponType;
        Bow* bow;
        Pole* pole;
        Disk* disk;

        PlayerCharacter playerCharacter;
        EnemyCharacter enemyCharacter;
        BowShape bowShape;
        PoleShape poleShape;
        DiskShape diskShape;

        int time;
        int score;
        bool end;

        Game();
        int getDirection(char ch);
        void createMap();
        void createEnemy();
        void draw();
        void moveEnemy();
        bool isEnemy(int idx);
        void movePlayer(int direction);
        void changeWeapon(int type);
        void updateWeapon(int input);
        void attack();
};