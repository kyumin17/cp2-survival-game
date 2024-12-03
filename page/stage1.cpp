#include "page.hpp"
#define MAXBULLET 300
#define MAXBLOCK 1000

using namespace std;

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

void createBlock(vector<Block*>& block) {
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
        } else if (55 <= blockX && blockX <= 75) {
            continue;
        }

        block.push_back(new Block(blockX, blockY * 3, 2, blockHeight));
        int blockPos = dis(gen) % blockHeight + blockY * 3;

        //맨 위, 아래에는 block 가로 블럭이 생기지 않도록
        if (blockPos == 3) {
            blockPos++;
        } else if (blockPos == 17) {
            blockPos--;
        }

        if (boolean(gen)) { //50%확률로 가로 블럭이 생기지 않음
            if (boolean(gen)) { //block 왼쪽으로
                int blockWidth = std::max(dis(gen) % (leftGap - 6), 3);
                block.push_back(new Block(blockX - blockWidth, blockPos, blockWidth, 1));
            } else { //block 오른쪽으로
                int blockWidth = std::max(dis(gen) % (rightGap - 6), 3);
                block.push_back(new Block(blockX + 2, blockPos, blockWidth, 1));
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

void createEnemy(vector<Enemy*>& enemy, vector<Block*> block, EnemyCharacter enemyCharacter) {
    //랜덤
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(-130 * 30, 130 * 30);
    std::uniform_int_distribution<int> disY(3, 15);

    //적 생성
    for (int i = 0; i < 300; i++) {
        int ex = disX(gen);
        int ey = disY(gen);

        //예외처리
        bool isValidPos = true;
        if (65 <= ex && ex <= 75) isValidPos = false; //플레이어 근방
        for (size_t j = 0; j < block.size(); j++) { //block과 만남
            if (isOverlap(block[j], ex, ey)) {
                isValidPos = false;
                break;
            }
        }

        if (!isValidPos) continue;

        enemy.push_back(new Enemy(3, 3, ex, ey, 3, 3, enemyCharacter.front));
    }
}

void getMap(int** map, vector<Block*> block) {
    //갈 수 있다면 1, 갈 수 없다면 0
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 130 * 30 * 2 + 1; j++) {
            map[i][j] = 0;
        }
    }

    for (size_t i = 0; i < block.size(); i++) {
        for (int r = 0; r < block[i] -> height; r++) {
            for (int c = 0; c < block[i] -> width; c++) {
                int mr = r + (block[i] -> y) - 3;
                int mc = c + (block[i] -> x) + 130 * 30;
                map[mr][mc] = 1;
            }
        }
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
    int isClear = false;
    long long time = 0;

    //세팅
    Display display;
    PlayerCharacter playerCharacter;
    EnemyCharacter enemyCharacter;
    Player player(65, 10, 5, 4, playerCharacter.front);

    vector<Enemy*> enemy;
    vector<Block*> block;
    vector<Bullet*> bullet;

    int** map = new int*[17];
    for (int i = 0; i < 17; i++) {
        map[i] = new int[130 * 30 * 2 + 1];
    }

    createBlock(block);
    createEnemy(enemy, block, enemyCharacter);
    getMap(map, block);

    //게임
    while (1) {
        time++;
        display.clearDisplay();
        ch = getch();
        int input = getDirection(ch);
        
        if (!player.isBlock(block, input)) {
            player.move(input, enemy, block, bullet, playerCharacter);
        }

        //플레이어 출력
        player.draw(&display);
        if (ch == 'i') {
            player.attack(bullet);
        }
        
        //적 출력
        for (size_t i = 0; i < enemy.size(); i++) {
            if (time % 70 == 0) {
                if (pow((enemy[i] -> x - player.x), 2) + pow((enemy[i] -> y - player.y), 2) < 900) {
                    enemy[i] -> move(player.x, player.y, map); //일정 시간마다 적이 움직임
                }
            }
            enemy[i] -> draw(&display);
        }

        //플레이어 총알 출력
        for (size_t i = 0; i < bullet.size(); i++) {
            int enemyIdx = bullet[i] -> isTouched(enemy); //공격한 적 인덱스
            if (enemyIdx != -1) { //적 만나면 총알 사라짐
                enemy.erase(enemy.begin() + enemyIdx);
                bullet.erase(bullet.begin() + i);
            } else if (bullet[i] -> isBlock(block)) { //블럭 만나면 총알 사라짐
                bullet.erase(bullet.begin() + i);
            } else if (bullet[i] -> isEndOfDisplay()) { //화면 나가면 총알 사라짐
                bullet[i] -> draw(&display);
                bullet.erase(bullet.begin() + i);
            } else {
                bullet[i] -> draw(&display);
            }
            
            if (time % 2 == 0) {
                bullet[i] -> move();
            }
        }

        display.printDisplay();

        //block 출력
        for (size_t i = 0; i < block.size(); i++) {
            block[i] -> draw();
        }

        //적에 닿으면 죽음
        if (player.isTouch(enemy)) {
            break;
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