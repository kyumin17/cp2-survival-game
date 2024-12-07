#include "page.hpp"
#include <ncurses.h>
void stage1Page() {
    char ch;
    int direction = -1;
    int isClear = false;

    //initial setting
    Display display;
    PlayerCharacter playerCharacter;
    EnemyCharacter enemyCharacter;
    Player player(3, 65, 10, 5, 4, playerCharacter.front);
    Enemy enemy(3, 3, 120, 10, 5, 4, enemyCharacter.front);
    keypad(stdscr, TRUE);

    int enemyNum = 10;
    int blockNum = 1;
    Enemy* enemy[enemyNum];
    Block* block[blockNum];

    //give random position
    for (int i = 0; i < enemyNum; i++) {
        enemy[i] = new Enemy(3, 3, rand() % 130, 3 + rand() % 15, 5, 4, enemyCharacter.front);
    }
    for (int i = 0; i < blockNum; i++) {
        int bx = rand() % 130;
        int by = 3 + rand() % 15;
        block[i] = new Block(bx, by, 10, 5);
    }
    //play
    while (1) {
        display.clearDisplay();
        //get input
        ch = getch();

        switch(ch) {
            case 'a':
                direction = LEFT;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 'w':
                direction = BACK;
                break;
            case 's':
                direction = FRONT;
                break;
            default:
                direction = -1;
        }
        
        if (!player.isBlock(block, blockNum, direction)) {
            player.move(direction, enemy, enemyNum, block, blockNum);
        }

        player.draw(&display);
        for (int i = 0; i < enemyNum; i++) enemy[i] -> draw(&display);

        display.printDisplay();
        
        if (ch == 27){
            if(checkQuitStage()) {
                clear();
                refresh();
                if (!selectStagePage()) return; 
            } 
        }  
        usleep(10000);
    }

    clear();
}