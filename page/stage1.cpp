#include "page.hpp"
#define MAXBULLET 300
#define MAXBLOCK 1000

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

void createMap(Block* block[], int &blockNum) {
    //랜덤
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1000000);
    std::uniform_int_distribution<int> disGap(10, 30);
    std::uniform_int_distribution<int> disBy(1, 4);
    std::uniform_int_distribution<int> boolean(0, 1);

    int blockX = -130 * 30;
    int blockY;
    int rightGap = 10; //현재 block과 내 앞 block간 거리
    int leftGap = 10; //현재 block과 내 뒤 block간 거리

    //block 생성
    while (blockX <= 130 * 30) {
        leftGap = rightGap;
        rightGap = disGap(gen);
        blockX += rightGap;
        blockY = disBy(gen);
        int blockHeight = std::max(6, (dis(gen) % (6 - blockY) + 1) * 3);

        //예외처리
        if (blockY == 1 && blockHeight == 15) {
            continue;
        } else if (63 <= blockX && blockX <= 68) {
            continue;
        }

        block[blockNum++] = new Block(blockX, blockY * 3, 2, blockHeight);
        int blockPos = dis(gen) % blockHeight + blockY * 3;

        //맨 위, 아래에는 block 뻗어나가지 않도록
        if (blockPos == 3) {
            blockPos++;
        } else if (blockPos == 17) {
            blockPos--;
        }

        if (boolean(gen)) { //50%확률로 뻗어나오지 않음
            if (boolean(gen)) { //block 왼쪽으로
                int blockWidth = std::max(dis(gen) % (leftGap - 6), 3);
                block[blockNum++] = new Block(blockX - blockWidth, blockPos, blockWidth, 1);
            } else { //block 오른쪽으로
                int blockWidth = std::max(dis(gen) % (rightGap - 6), 3);
                block[blockNum++] = new Block(blockX + 2, blockPos, blockWidth, 1);
            }
        }
    }
}

bool isOverlap(Block* block, int ex, int ey) {
    int bx = block -> x;
    int by = block -> y;
    int bw = block -> width;
    int bh = block -> height;

    if (bx <= ex + 2 && ex <= bx + bw - 1 && by <= ey + 2 && ey <= by + bh - 1) {
        return true;
    } else {
        return false;
    }
}

void createEnemy(Enemy* enemy[], int& enemyNum, Block* block[], int &blockNum, EnemyCharacter enemyCharacter) {
    //랜덤
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(-130 * 30, 130 * 30);
    std::uniform_int_distribution<int> disY(3, 15);

    //적 생성
    int i = 0;
    while (i < enemyNum) {
        int ex = disX(gen);
        int ey = disY(gen);

        //예외처리
        bool isValidPos = true;
        if (65 <= ex && ex <= 75) isValidPos = false; //플레이어 근방
        for (int j = 0; j < blockNum; j++) { //block과 만남
            if (isOverlap(block[j], ex, ey)) {
                isValidPos = false;
                break;
            }
        }

        if (!isValidPos) continue;

        enemy[i] = new Enemy(3, 3, ex, ey, 3, 3, enemyCharacter.front);
        i++;
    }
}

int getDirection(char ch) {
    switch(ch) {
        case 'a':
            return LEFT;
            break;
        case 'd':
            return RIGHT;
            break;
        case 'w':
            return BACK;
            break;
        case 's':
            return FRONT;
            break;
        default:
            return -1;
    }
}

void stage1Page() {
    char ch;
    int direction = -1;
    int isClear = false;
    long long time = 0;

    //세팅
    Display display;
    PlayerCharacter playerCharacter;
    EnemyCharacter enemyCharacter;
    Player player(65, 10, 5, 4, playerCharacter.front);

    int enemyNum = 300;
    int blockNum = 0;
    int bulletNum = 0;
    Enemy* enemy[enemyNum];
    Block* block[MAXBLOCK];
    Bullet* bullet[MAXBULLET];

    createMap(block, blockNum);
    createEnemy(enemy, enemyNum, block, blockNum, enemyCharacter);

    //게임
    while (1) {
        time++;
        display.clearDisplay();
        ch = getch();
        direction = getDirection(ch);
        
        if (!player.isBlock(block, blockNum, direction)) {
            player.move(direction, enemy, enemyNum, block, blockNum, playerCharacter);
        }

        //draw
        player.draw(&display);
        player.attack(bullet, bulletNum);
        for (int i = 0; i < enemyNum; i++) {
            if (time % 70 == 0) {
                if (pow((enemy[i] -> x - player.x), 2) + pow((enemy[i] -> y - player.y), 2) < 500) {
                    enemy[i] -> move(player.x, player.y); //일정 시간마다 적이 움직임
                }
            }
            enemy[i] -> draw(&display);
        }

        for (int i = 0; i < bulletNum; i++) {
            bullet[i] -> draw(&display);
            bullet[i] -> move();
        }

        display.printDisplay();

        //draw block
        for (int i = 0; i < blockNum; i++) {
            block[i] -> draw();
        }

        //적에 닿으면 죽음
        if (player.isTouch(enemy, enemyNum)) {
            //break;
        }

        //q누르면 종료 페이지 띄움
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