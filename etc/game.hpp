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
        Eraser* eraser;

        PlayerCharacter playerCharacter;
        EnemyCharacter enemyCharacter;
        BowShape bowShape;
        PoleShape poleShape;
        EraserShape eraserShape;

        int time;
        int score;
        bool end;

        Game();
        int getDirection(char ch);
        void createMap();
        void createEnemy(int createNum);
        void draw();
        void moveEnemy();
        bool isEnemy(int idx);
        void movePlayer(int direction);
        void changeWeapon(int type);
        void updateWeapon(int input);
        void attack();
};