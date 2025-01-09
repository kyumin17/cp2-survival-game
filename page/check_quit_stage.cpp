#include "page.hpp"

bool checkQuitStagePage() {
    int ch;
    int option = 1;

    clear();

    while(1) {
        drawBorder();

        ch = getch();
        option = getOption(ch, option);

        drawOptionDisplay(option, "Resume", "Home", 0);

        if (ch == '\n') {
            clear();
            return option == 2;
        }

        usleep(SLEEP);
    }
}