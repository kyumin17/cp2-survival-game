#include "page.hpp"
#include "../component/display/display.hpp"
#include "asset/get_direction.hpp"
#include "../component/weapon/weapon_manager.hpp"
#include "../component/enemy/enemy.hpp"
#include "../component/weapon/type/bow.hpp"
#include "../component/weapon/type/sword.hpp"
#include "../component/block/block.hpp"
#include "../component/player/player.hpp"
#include "../component/block/block_container.hpp"
#include "../component/enemy/enemy_container.hpp"

using namespace std;

int playPage(int& s) {
    char ch;
    Player player(65, 14, 3, 3, playerDownImage.data);
    WeaponManager weaponManager(player.x, player.y);
    BlockContainer block_container;
    EnemyContainer enemy_container;
    Display display;
    int time = 0;
    int score = 0;
    bool end = false;

    block_container.createBlock(&player, 2000); // 장애물 2000개 생성

    while (!end) {
        time++;
        display.clearDisplay();

        ch = getch();
        int direction = getDirection(ch); // 입력을 방향으로 변환
        
        enemy_container.moveEnemy(block_container, player.x, player.y, time);

        if (!player.isBlock(block_container.array, direction, end)) { //앞에 블럭 없으면 감
            player.move(direction, enemy_container.array, block_container.array);
        }


        weaponManager.updateWeapon(direction, time, &player, enemy_container, block_container); // 무기 상태 업데이트
        
        player.draw(display);
        weaponManager.draw(display);
        enemy_container.draw(display);
        display.printDisplay();
        block_container.draw();

        enemy_container.createEnemy(score, block_container);

        enemy_container.updateEnemy(score);

        switch(ch) {
            case 'i': // 공격
                weaponManager.attack(player.direction);
                break;
            case 27: // ESC, 게임 중단
                if (checkQuitStagePage()) {
                    return START;
                }
                break;
            // 무기 전환
            case '1': // 활
                weaponManager.changeWeapon();
                break;
            case '2': // 검
                weaponManager.changeWeapon();
                break;
        }

        if (time % 100 == 0) {
            score++;
        }
        
        end = end || player.isDamaged(enemy_container.array); // 적에 닿을 시 게임 종료

        usleep(SLEEP);
    }

    clear();
    s = score; //스코어 기록

    return END; // 게임 종료
}