#include "page.hpp"

int startPage() {
    int ch;
    int option = 1;

    while (1) {
        drawTitle();
        drawBorder();

        ch = getch();
        option = getOption(ch, option);

        drawOptionDisplay(option, "Start Game", "Quit", 3);

        if (ch == '\n') {
            if (option == 1) {
                return PLAY;
            } else if (option == 2 && checkQuitGamePage()) {
                return QUIT;
            }
        }

        usleep(SLEEP);
    }
}