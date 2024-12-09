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
        Sword* sword;
        Eraser* eraser;

        PlayerCharacter playerCharacter;
        EnemyCharacter enemyCharacter;
        BowShape bowShape;
        SwordShape swordShape;
        EraserShape eraserShape;

        int enemyNum;
        int time;
        int score;
        bool end;
        int enemyVelocity;

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
        void printBackground();
        void updateEnemy();
};