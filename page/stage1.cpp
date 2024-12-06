#include "page.hpp"
#include <ncurses.h>
void stage1Page() {
    char ch;
    int direction;

    Display display;
    PlayerCharacter playerCharacter;
    EnemyCharacter enemyCharacter;
    Player player(3, 65, 10, 5, 4, playerCharacter.front);
    Enemy enemy(3, 3, 120, 10, 5, 4, enemyCharacter.front);
    keypad(stdscr, TRUE);

    while (1) {
        display.clearDisplay();
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
        }
        
        player.draw(&display);
        enemy.draw(&display);

        display.printDisplay();

        
        if (ch == 27){
            if(checkQuitStage()) {
                clear();
                refresh();
                if (!selectStagePage()) return; 
            } 
        }  
        usleep(10000);
    }
}