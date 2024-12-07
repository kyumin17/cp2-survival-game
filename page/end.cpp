#include "page.hpp"
#define WIDTH 130
#define HEIGHT 30

int endPage(int score) {
    /*
    retry라면 1을, quit이라면 0을 반환한다.
    */

    char ch;
    int endingPage = 1;

    char one[4][7] = {
        "  __  ",
        " /  \\ ",
        "(_/ / ",
        " (__) "
    };
    
    char two[4][7] = {
        " ____ ",
        "(___ \\",
        " / __/",
        "(____)"
    };

    char three[4][7] = {
        " ____ ",
        "( __ \\",
        " (__ (",
        "(____/"
    };

    char four[4][7] = {
        "  ___ ",
        " / _ \\",
        "(__  (",
        "  (__/"
    };
    
    char five[4][7] = {
        "  ___ ",
        " / __)",
        "(___ \\",
        "(____/"
    };

    char six[4][7] = {
        "  ___ ",
        " / __)",
        "(  _ \\",
        " \\___/"
    };

    char seven[4][7] = {
        " ____ ",
        "(__  )",
        "  / / ",
        " (_/  "
    };

    char eight[4][7] = {
        " ____ ",
        "/ _  \\",
        ") _  (",
        "\\____/"
    };

    char nine[4][7] = {
        " ___  ",
        "/ _ \\ ",
        "\\__  )",
        "(___/ "
    };

    char zero[4][7] = {
        "  __  ",  // 첫 번째 행
        " /  \\ ", // 두 번째 행
        "(  0 )", // 세 번째 행
        " \\__/ "  // 네 번째 행
    };
    
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

        mvprintw(2, 36, "   ____    _    __  __ _____    _____     _______ ____  ");
        mvprintw(3, 36, "  / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ ");
        mvprintw(4, 36, " | |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |");
        mvprintw(5, 36, " | |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ < ");
        mvprintw(6, 36, "  \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\");
        
        mvprintw(10,16," ____   ___  __  ____  ____  _   ");
        mvprintw(11,16,"/ ___) / __)/  \\(  _ \\(  __)(_)  ");
        mvprintw(12,16,"\\___ \\( (__(  O ))   / ) _)  _   ");
        mvprintw(13,16,"(____/ \\___)\\__/(__\\_)(____)(_)  ");

        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);

        switch (ch) {
            case 'w':
                if (endingPage != 1) {
                    endingPage--;
                } 
                break;
            case 's':
                if (endingPage != 2) {
                    endingPage++;
                }
                break;
        }

        switch (endingPage) {
            case 1:
                attron(COLOR_PAIR(1));
                mvprintw(18, 55, "> Restart");
                attroff(COLOR_PAIR(1));
                mvprintw(20, 55, "  Quit");
                break;
            case 2:
                mvprintw(18, 55, "  Restart");
                attron(COLOR_PAIR(2));
                mvprintw(20, 55, "> Quit");
                attroff(COLOR_PAIR(2));
                break;
        }

        if (ch == '\n') {
            if (endingPage == 1) {
                return 1; //back to game
            } else if (endingPage == 2) {
                return 0;
            }
        }

        usleep(10000);
    }
}