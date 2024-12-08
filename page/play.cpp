#include "page.hpp"
#include <random>
#include <vector>
#include "../etc/game.hpp"

using namespace std;

int playPage(int& score) {
    char ch;
    Game game;

    game.createMap();

    //게임
    while (!game.end) {
        game.time++;
        game.display.clearDisplay();
        ch = getch();
        int direction = game.getDirection(ch);
        
        game.moveEnemy();
        game.movePlayer(direction);
        game.updateWeapon(direction);
        game.draw();

        game.createEnemy();

        switch(ch) {
            case 'i':
                game.attack();
                break;
            case 27:
                clear();
                if (checkQuitStage()) {
                    clear();
                    return START;
                }
                break;
            case '1':
                game.changeWeapon(1);
                break;
            case '2':
                game.changeWeapon(2);
                break;
            case '3':
                game.changeWeapon(3);
                break;
        }

        game.end = game.end || game.player -> isTouch(game.enemyArr);
        if (game.time % 500 == 0) {
            game.enemyNum += 5;
        }
        if (game.time % 100 == 0) {
            game.score += 1;
        }

        usleep(10000); //10ms
    }

    clear();
    score = game.score;

    return END;
}