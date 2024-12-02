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
    long long time = 0;

    //initial setting
    Display display;
    PlayerCharacter playerCharacter;
    EnemyCharacter enemyCharacter;
    Player player(3, 65, 10, 5, 4, playerCharacter.front);

    int enemyNum = 300;
    int blockNum = 600;
    Enemy* enemy[enemyNum];
    Block* block[blockNum];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(-130 * 30, 130 * 30);
    std::uniform_int_distribution<int> disY(3, 16);
    std::uniform_int_distribution<int> dis(0, 1000000);

    //give random position
    for (int i = 0; i < enemyNum; i++) {
        enemy[i] = new Enemy(3, 3, disX(gen), disY(gen), 5, 4, enemyCharacter.front);
    }
    for (int i = 0; i < blockNum; i++) {
        int bx = disX(gen);
        int by = disY(gen);
        block[i] = new Block(bx, by, 5 + dis(gen) % 10, dis(gen) % (17 - by) + 3);
    }

    //play
    while (1) {
        time++;
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
            player.move(direction, enemy, enemyNum, block, blockNum, playerCharacter);
        }

        //draw
        player.draw(&display);
        for (int i = 0; i < enemyNum; i++) {
            if (time % 70 == 0) {
                if (pow((enemy[i] -> x - player.x), 2) + pow((enemy[i] -> y - player.y), 2) < 500) {
                    enemy[i] -> move(player.x, player.y); //일정 시간마다 적이 움직임
                }
            }
            enemy[i] -> draw(&display);
        }

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