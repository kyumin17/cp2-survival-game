#include "enemy_container.hpp"

EnemyContainer::EnemyContainer(): length(0) {
    max_num = 10;
    enemy_velocity = 40;
    create_freq[0] = 10;
    create_freq[1] = create_freq[2] = create_freq[3] = 0;
}

void EnemyContainer::createEnemy(int score, BlockContainer blockContainer) {
    //랜덤
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis_x(-30, 160);
    std::uniform_int_distribution<int> dis_y(-20, 50);

    int create_num = max_num - array.size();
    int freq_sum = create_freq[0] + create_freq[1] + create_freq[2] + create_freq[3];

    std::uniform_int_distribution<int> disTypeSeed(1, freq_sum);
    
    //생성된 적만큼 점수 증가
    if (score != 0 && create_num > 0) {
        score += create_num;
    }

    //적 생성
    for (int i = 0; i < create_num; i++) {
        int ex = dis_x(gen); //적 x좌표
        int ey = dis_y(gen); //적 y좌표
        int ew, eh;
        int type = 4;
        int seed = disTypeSeed(gen);

        //예외처리
        bool isValidPos = true;
        if (55 <= ex && ex <= 75) { //플레이어 근방
            isValidPos = false;
        }

        //freq 배열의 확률로 생성
        for (int i = 0; i < 4; i++) {
            seed -= create_freq[i];
            if (seed <= 0) {
                type = i + 1;
                break;
            }
        }

        switch(type) {
            case 1:
            case 2:
                ew = 3;
                eh = 3;
                break;
            case 3:
                ew = 4;
                eh = 1;
                break;
            case 4:
                ew = 4;
                eh = 2;
                break;
        }

        for (size_t i = 0; i < blockContainer.array.size(); i++) { //블럭과 만남
            if (blockContainer.array[i] -> isOverlap(ex, ey, ew, eh)) { //블럭 위치에 적 생성되지 않도록
                isValidPos = false;
                break;
            }
        }

        if (!isValidPos) continue;

        //적 생성
        switch(type) {
            case 1:
                array.push_back(new Enemy(ENEMY1, ex, ey, ew, eh, manImage.data));
                break;
            case 2:
                array.push_back(new Enemy(ENEMY2, ex, ey, ew, eh, explosionImage.data));
                break;
            case 3:
                array.push_back(new Enemy(ENEMY3, ex, ey, ew, eh, wormRightImage.data));
                break;
            case 4:
                array.push_back(new Enemy(ENEMY4, ex, ey, ew, eh, slimeImage.data));
                break; 
        }
    }
}

void EnemyContainer::moveEnemy(BlockContainer blockContainer, int player_x, int player_y, int time) {
    /*
    일정 프레임마다 적 움직임
    앞에 블럭 혹은 다른 적 있을 시 피해서 감
    */

    for (size_t i = 0; i < array.size(); i++) {
            
        if (array[i] -> type == ENEMY3 && time % (int)(enemy_velocity / 3) == 0) {
            if (array[i] -> surviveTime++ == 100) { //블럭에 막혀서 못 오는 경우 대비
                array.erase(array.begin() + i);
            }
            array[i] -> moveX(player_x, player_y, blockContainer.array); //일정 시간마다 적이 움직임
            if (array[i] -> isBlock(blockContainer.array) || isEnemy(i)) { //다른 적 혹은 block과 충돌 시 원위치
                array[i] -> x -= array[i] -> dx;
            }
            if (array[i] -> direction == LEFT) array[i] -> changeCharacter(wormLeftImage.data, 4, 1);
            if (array[i] -> direction == RIGHT) array[i] -> changeCharacter(wormRightImage.data, 4, 1);
            if (time % (2 * enemy_velocity) == 0) { //y축 이동이 느림
                array[i] -> moveY(player_x, player_y, blockContainer.array); //일정 시간마다 적이 움직임
                if (array[i] -> isBlock(blockContainer.array) || isEnemy(i)) { //다른 적 혹은 block과 충돌 시 원위치
                    array[i] -> y -= array[i] -> dy;
                }
            }
            continue;
        }

        if (array[i] -> type != ENEMY3 && time % enemy_velocity == 0) {
            if (array[i] -> surviveTime++ == 100) { //블럭에 막혀서 못 오는 경우 대비
                array.erase(array.begin() + i);
            }
            array[i] -> moveX(player_x, player_y, blockContainer.array); //일정 시간마다 적이 움직임
            if (array[i] -> isBlock(blockContainer.array) || isEnemy(i)) { //다른 적 혹은 block과 충돌 시 원위치
                array[i] -> x -= array[i] -> dx;
            }
            array[i] -> moveY(player_x, player_y, blockContainer.array); //일정 시간마다 적이 움직임
            if (array[i] -> isBlock(blockContainer.array) || isEnemy(i)) { //다른 적 혹은 block과 충돌 시 원위치
                array[i] -> y -= array[i] -> dy;
            }
            if (array[i] -> type == ENEMY2EXPLORE) {
                array.erase(array.begin() + i);
            }
        }

    }
}

bool EnemyContainer::isEnemy(int idx) {
    int x = array[idx] -> x;
    int y = array[idx] -> y;
    int w = array[idx] -> width;
    int h = array[idx] -> height;

    for (size_t i = 0; i < array.size(); i++) {
        if ((int)i == idx) continue;
        int ex = array[i] -> x;
        int ey = array[i] -> y;
        int ew = array[i] -> width;
        int eh = array[i] -> height;

        if (y <= ey + eh - 1 && ey <= y + h - 1 && x <= ex + ew - 1 && ex <= x + w - 1) {
            return true;
        }
    }

    return false;
}

void EnemyContainer::draw(Display& display) {
    for (size_t i = 0; i < array.size(); i++) {
        array[i] -> draw(display);
    }
}

void EnemyContainer::updateEnemy(int score) {
    if (50 >= score && score > 30) {
        max_num = 20;
        create_freq[1] = 5;
    } else if (70 >= score && score > 50) {
        create_freq[2] = 5;
    } else if (100 >= score && score > 70) {
        enemy_velocity = 35;
        max_num = 25;
        create_freq[3] = 10;
    } else if (150 >= score && score > 100) {
        enemy_velocity = 30;
        max_num = 30;
        create_freq[1] = 10;
        create_freq[2] = 10;
    } else if (200 >= score && score > 150) {
        enemy_velocity = 25;
        create_freq[3] = 10;
    } else if (300 >= score && score > 200) {
        max_num = 32;
    } else if (score > 300) {
        max_num = 35;
    }
}