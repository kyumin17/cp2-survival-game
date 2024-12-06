#include "game.hpp"

Game::Game() {
    weaponType = 1;
    player = new Player(65, 14, 3, 3, playerCharacter.front);
    bow = new Bow(player -> x, player -> y + 1, bowShape.bowDown);
    pole = new Pole(player -> x + 3, player -> y - 2, poleShape.poleRight[0]);
    disk = new Disk(player -> x + 3, player -> y + 1, diskShape.disk);
    time = 0;
    score = 0;
    end = false;
}

int Game::getDirection(char ch) {
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

void Game::createMap() {
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
        if (blockArr[i] -> isOverlap(player -> x, player -> y)) { //플레이어 위치에 블럭 생성되지 않도록
            blockArr.erase(blockArr.begin() + i);
        }
    }
}

void Game::createEnemy() {
    //랜덤
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(-130 * 30, 130 * 30);
    std::uniform_int_distribution<int> disY(3, 15);

    //적 생성
    for (int i = 0; i < 500; i++) {
        int ex = disX(gen); //적 x좌표
        int ey = disY(gen); //적 y좌표

        //예외처리
        bool isValidPos = true;
        if (55 <= ex && ex <= 75) { //플레이어 근방
            isValidPos = false;
        }
        for (size_t j = 0; j < blockArr.size(); j++) { //block과 만남
            if (blockArr[j] -> isOverlap(ex, ey)) { //block위치에 적 생성되지 않도록
                isValidPos = false;
                break;
            }
        }

        if (!isValidPos) continue;

        //적 생성
        enemyArr.push_back(new Enemy(3, 3, ex, ey, 3, 3, enemyCharacter.front));
    }
}

void Game::draw() {
    /*
    오브젝트들을 화면에 출력
    */
    player -> draw(&display);
    
    switch(weaponType) {
        case 1:
            bow -> draw(&display);
            bow -> drawArrows(&display);
            break;
        case 2:
            pole -> draw(&display);
            break;
        case 3:
            disk -> draw(&display);
            break;
    }

    for (size_t i = 0; i < enemyArr.size(); i++) {
        enemyArr[i] -> draw(&display);
    }

    display.printDisplay();

    for (size_t i = 0; i < blockArr.size(); i++) {
        blockArr[i] -> draw();
    }
}

void Game::moveEnemy() {
    for (size_t i = 0; i < enemyArr.size(); i++) {
        if (time % 20 == 0) {
            if (pow((enemyArr[i] -> x - player -> x), 2) + pow((enemyArr[i] -> y - player -> y), 2) < 400) {
                enemyArr[i] -> isTracking = true;
            }
            enemyArr[i] -> move(player -> x, player -> y); //일정 시간마다 적이 움직임
        }
    }
}

void Game::movePlayer(int direction) {
    if (!player -> isBlock(blockArr, direction)) {
        player -> move(direction, enemyArr, blockArr, playerCharacter);
    }
}

void Game::changeWeapon(int type) {
    weaponType = type;
}

void Game::updateWeapon(int input) {
    switch (weaponType) {
        case 1:
            bow -> changeBowDirection(player -> direction, player -> x, player -> y);
            for (size_t i = 0; i < bow -> arrowArr.size(); i++) {
                switch(input) {
                    case LEFT:
                        bow -> arrowArr[i] -> x++;
                        break;
                    case RIGHT:
                        bow -> arrowArr[i] -> x--;
                        break;
                    case BACK:
                        bow -> arrowArr[i] -> y--;
                        break;
                    case FRONT:
                        bow -> arrowArr[i] -> y++;
                        break;
                }
            }
            if (time % 10 == 0) {
                if (bow -> attackTime != 0) bow -> attackTime++;
                bow -> moveArrows();
                bow -> checkCollision(enemyArr, blockArr);
                if (bow -> attackTime == bow -> cooldown) {
                    bow -> attackTime = 0;
                }
            }
            break;
        case 2:
            pole -> changePoleDirection(player -> direction, player -> x);
            if (time % 5 == 0) {
                if (pole -> attackTime != 0) {
                    pole -> attack(player -> direction, player -> x, enemyArr);
                    pole -> attackTime++;
                }
                if (pole -> attackTime == pole -> cooldown) {
                    pole -> attackTime = 0;
                }
            }
            break;
        case 3:
            if (time % 10 == 0) {
                if (disk -> attackTime != 0) {
                    disk -> attack(player -> direction);
                    disk -> attackTime++;
                }
                if (disk -> attackTime == disk -> cooldown) {
                    disk -> attackTime = 0;
                }
            }
            break;
    }
}

void Game::attack() {
    switch(weaponType) {
        case 1:
            if (bow -> attackTime == 0) {
                bow -> attackTime = 1;
                bow -> attack(player -> direction);
            }
            break;
        case 2:
            if (pole -> attackTime == 0) {
                pole -> attackTime = 1;
            }
            break;
        case 3:
            if (disk -> attackTime == 0) {
                disk -> attackTime = 1;
                disk -> attack(player -> direction);
            }
            break;
    }
}