#include "page.hpp"

bool checkQuitGamePage() {
    int ch;
    int option = 1;

    clear();

    while(1) {
        drawQuitConfirmText();
        drawBorder();

        ch = getch();
        option = getOption(ch, option);

        drawOptionDisplay(option, "Cancel", "Quit", 5);

        if (ch == '\n') {
            clear();
            return option == 2;
        }

        usleep(SLEEP);
    }
}