#include "page.hpp"

int bulletSelectPage() {
    char ch;
    int bullets = 1;
    while(1) {
        ch = getch();
        for (int x = 0; x < WIDTH; x+=2) {
            mvprintw(0, x, "-=");
            mvprintw( HEIGHT - 1, x, "-=");
        }
        for(int y = 0; y < HEIGHT; y+=2) {
            mvprintw(y, 0, "|");
            mvprintw(y, WIDTH - 1, "|");
        }
        for(int y = 0; y < HEIGHT; y+=3) {
            mvprintw(y, 0, ":");
            mvprintw(y, WIDTH - 1, ":");
        }
    }
    
}