#include "page.hpp"
#include <random>
#include <vector>
#include <cmath>

using namespace std;

bool isOverlap(Block* block, int x, int y) {
    int bx = block -> x;
    int by = block -> y;
    int bh = block -> height;

    if (bx <= x + 2 && x <= bx + bh * 2 - 1 && by <= y + 2 && y <= by + bh - 1) {
        return true;
    } else {
        return false;
    }
}

void createBlock(vector<Block*>& blockArr, int px, int py) {
    //랜덤
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disPos(-100, 100);
    std::uniform_int_distribution<int> disLen(4, 8);

    //block 생성
    for (int i = 0; i < 100; i++) {
        blockArr.push_back(new Block(disPos(gen), disPos(gen), disLen(gen)));
    }

    for (int i = 0; i < 100; i++) {
        if (isOverlap(blockArr[i], px, py)) {
            blockArr.erase(blockArr.begin() + i);
        }
    }
}

void createEnemy(vector<Enemy*>& enemyArr, vector<Block*> blockArr, EnemyCharacter enemyCharacter) {
    //랜덤
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(-130 * 30, 130 * 30);
    std::uniform_int_distribution<int> disY(3, 15);

    //적 생성
    for (int i = 0; i < 500; i++) {
        int ex = disX(gen);
        int ey = disY(gen);

        //예외처리
        bool isValidPos = true;
        if (55 <= ex && ex <= 75) { //플레이어 근방
            isValidPos = false;
        }
        for (size_t j = 0; j < blockArr.size(); j++) { //block과 만남
            if (isOverlap(blockArr[j], ex, ey)) {
                isValidPos = false;
                break;
            }
        }

        if (!isValidPos) continue;

        enemyArr.push_back(new Enemy(3, 3, ex, ey, 3, 3, enemyCharacter.front));
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

int playPage() {
    char ch;
    long long time = 0;

    //세팅
    Display display;
    PlayerCharacter playerCharacter;
    EnemyCharacter enemyCharacter;
    Player player(65, 14, 5, 4, playerCharacter.front);

    vector<Enemy*> enemyArr;
    vector<Block*> blockArr;
    vector<Weapon*> weaponArr;

    createEnemy(enemyArr, blockArr, enemyCharacter);
    createBlock(blockArr, player.x, player.y);

    //게임
    while (1) {
        time++;
        display.clearDisplay();
        ch = getch();
        int input = getDirection(ch);
        
        if (!player.isBlock(blockArr, input)) {
            player.move(input, enemyArr, blockArr, weaponArr, playerCharacter);
        }

        //플레이어 출력
        player.draw(&display);
        if (ch == 'i') {
            player.attack(weaponArr);
        }
        
        //적 출력
        for (size_t i = 0; i < enemyArr.size(); i++) {
            if (time % 20 == 0) {
                if (pow((enemyArr[i] -> x - player.x), 2) + pow((enemyArr[i] -> y - player.y), 2) < 400) {
                    enemyArr[i] -> isTracking = true;
                }
                enemyArr[i] -> move(player.x, player.y); //일정 시간마다 적이 움직임
            }
            enemyArr[i] -> draw(&display);
        }

        //플레이어 총알 출력
        for (size_t i = 0; i < weaponArr.size(); i++) {
            int enemyIdx = weaponArr[i] -> isTouched(enemyArr); //공격한 적 인덱스
            if (enemyIdx != -1) { //적 만나면 총알 사라짐
                enemyArr.erase(enemyArr.begin() + enemyIdx);
                weaponArr.erase(weaponArr.begin() + i);
            } else if (weaponArr[i] -> isBlock(blockArr)) { //블럭 만나면 총알 사라짐
                weaponArr.erase(weaponArr.begin() + i);
            } else if (weaponArr[i] -> isEndOfDisplay()) { //화면 나가면 총알 사라짐
                weaponArr[i] -> draw(&display);
                weaponArr.erase(weaponArr.begin() + i);
            } else {
                weaponArr[i] -> draw(&display);
            }
            
            if (time % 2 == 0) {
                weaponArr[i] -> move();
            }
        }

        display.printDisplay();

        //block 출력
        for (size_t i = 0; i < blockArr.size(); i++) {
            blockArr[i] -> draw();
        }

        //적에 닿으면 죽음
        if (player.isTouch(enemyArr)) {
            break;
        }

        //q누르면 종료 페이지 띄움
        if (ch == 'q' && checkQuitPage()) {
            clear();
            break;
        }

        usleep(10000);
    }

    clear();

    return time;
}