#include "page.hpp"
#include <random>
#include <vector>
#include <cmath>
#include "../etc/game.hpp"

using namespace std;

int playPage() {
    char ch;
    Game game;

    game.createMap();
    game.createEnemy();

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

        switch(ch) {
            case 'i':
                game.attack();
                break;
            case 'q':
                if (checkQuitPage()) clear();
                break;
            case 'o':
                game.weaponType = selectWeaponPage();
                break;
        }

        game.end = game.player -> isTouch(game.enemyArr);

        usleep(10000);
    }

    clear();

    return game.score;
}