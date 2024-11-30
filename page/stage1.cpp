#include "page.hpp"

void stage1Clear() {
    char ch;
    while (ch != '\n') {
        ch = getch();
        mvprintw(0, 0, "clear!");

        usleep(10000);
    }
}

void stage1Fail() {
    char ch;
    while (ch != 'q') {
        ch = getch();
        mvprintw(0, 0, "dead");

        usleep(10000);
    }
}

void stage1Page() {
    char ch;
    int direction = -1;
    int isClear = false;

    //initial setting
    Display display;
    PlayerCharacter playerCharacter;
    EnemyCharacter enemyCharacter;
    Player player(3, 65, 10, 5, 4, playerCharacter.front);

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
        //block[i] = new Block(bx, by, 1 + rand() % (19 - by), 1 + rand() % 3);
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

        //draw
        player.draw(&display);
        for (int i = 0; i < enemyNum; i++) enemy[i] -> draw(&display);

        display.printDisplay();

        //draw block
        for (int i = 0; i < blockNum; i++) {
            block[i] -> draw();
        }

        //dead
        if (player.isTouch(enemy, enemyNum)) {
            break;
        }

        //quit game
        if (ch == 'q' && checkQuitPage()) {
            clear();
            if (!selectStagePage()) return;
        }

        usleep(10000);
    }

    clear();

    if (isClear) {
        stage1Clear();
    } else {
        stage1Fail();
    }
}