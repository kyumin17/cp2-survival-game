#include "page.hpp"
#include <vector>
#include "../etc/game.hpp"

using namespace std;

int playPage(int& score) {
    char ch;
    Game game;

    game.createBlock(2500);

    while (!game.end) {
        game.time++;
        game.display.clearDisplay();

        ch = getch();
        int direction = game.getDirection(ch); //입력을 방향으로 변환
        
        game.moveEnemy();
        game.movePlayer(direction);
        game.updateWeapon(direction); //무기 상태 업데이트
        game.draw(); //컴포넌트들을 그림

        game.createEnemy(); //적 새로 생성
        game.updateEnemy();

        switch(ch) {
            /*공격*/
            case 'i':
                game.attack();
                break;
            /*게임 중단*/
            case 27:
                clear();
                if (checkQuitStage()) {
                    clear();
                    return START;
                }
                break;
            /*무기 전환*/
            case '1':
                game.changeWeapon(1);
                break;
            case '2':
                game.changeWeapon(2);
                break;
            case '3':
                game.changeWeapon(3);
                break;
        }

        game.end = game.end || game.player -> isDamaged(game.enemyArr); //적에 닿을 시 게임 종료

        if (game.time % 500 == 0) {
            
        }
        if (game.time % 100 == 0) {
            game.score += 1; //시간에 따라 스코어 증가
        }

        usleep(10000); //10ms
    }

    clear();
    score = game.score; //스코어 기록

    return END;
}