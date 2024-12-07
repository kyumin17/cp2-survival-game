#include "page.hpp"
#include <random>
#include <vector>
#include "../etc/game.hpp"

using namespace std;

int playPage() {
    char ch;
    Game game;

    game.createMap();
    game.createEnemy(10);

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

        if (game.enemyArr.size() < 30) game.createEnemy(30 - game.enemyArr.size());

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

        game.end = game.player -> isTouch(game.enemyArr);

        usleep(10000);
    }

    clear();

    return game.score;
}