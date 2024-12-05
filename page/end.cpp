#include "page.hpp"

int endPage() {
    /*
    retry라면 1을, quit이라면 0을 반환한다.
    */

    char ch;
    while (1) {
        ch = getch();

        if (ch == '\n') {
            return 1;
        } else if (ch == 'q') {
            return 0;
        }

        usleep(10000);
    }
}