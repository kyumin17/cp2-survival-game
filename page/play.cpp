#include "page.hpp"
#include "../manage/game.hpp"

using namespace std;

int playPage(int& score) {
    char ch;
    Game game;

    game.createBlock(2000); // 장애물 2000개 생성

    while (!game.end) {
        game.time++;
        game.display.clearDisplay();

        ch = getch();
        int direction = game.getDirection(ch); // 입력을 방향으로 변환
        
        game.moveEnemy();
        game.movePlayer(direction);
        game.updateWeapon(direction); // 무기 상태 업데이트
        game.draw();

        game.createEnemy();
        game.updateEnemy();

        switch(ch) {
            case 'i': // 공격
                game.attack();
                break;
            case 27: // ESC, 게임 중단
                if (checkQuitStagePage()) {
                    return START;
                }
                break;
            // 무기 전환
            case '1': // 활
                game.changeWeapon(1);
                break;
            case '2': // 검
                game.changeWeapon(2);
                break;
        }

        if (game.time % 100 == 0) {
            game.score += 1; // 시간에 따라 스코어 증가
        }
        
        game.end = game.end || game.player -> isDamaged(game.enemyArr); // 적에 닿을 시 게임 종료

        usleep(SLEEP);
    }

    clear();
    score = game.score; //스코어 기록

    return END; // 게임 종료
}