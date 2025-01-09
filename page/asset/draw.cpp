#include <ncurses.h>
#define WIDTH 130
#define HEIGHT 30

void drawBorder() {
    for (int x = 0; x < WIDTH; x += 2) {
        mvprintw(0, x, "-=");
        mvprintw( HEIGHT - 1, x, "-=");
    }
    for(int y = 0; y < HEIGHT; y += 2) {
        mvprintw(y, 0, "|");
        mvprintw(y, WIDTH - 1, "|");
    }
    for(int y = 0; y < HEIGHT; y += 3) {
        mvprintw(y, 0, ":");
        mvprintw(y, WIDTH - 1, ":");
    }
}

void drawTitle() {
    mvprintw(7, 29, "                     _     _                                    ");
    mvprintw(8, 29, "  _______  _ __ ___ | |__ (_) ___    __ _  __ _ _ __ ___   ___  ");
    mvprintw(9, 29, " |_  / _ \\| '_ ` _ \\| '_ \\| |/ _ \\  / _` |/ _` | '_ ` _ \\ / _ \\ ");
    mvprintw(10, 29, "  / / (_) | | | | | | |_) | |  __/ | (_| | (_| | | | | | |  __/ ");
    mvprintw(11, 29, " /___\\___/|_| |_| |_|_.__/|_|\\___|  \\__, |\\__,_|_| |_| |_|\\___| ");
    mvprintw(12, 29, "                                    |___/                       ");

    mvprintw(22, 50, "W: jump        S: down");
    mvprintw(23, 50, "A: left        D: right");
    mvprintw(24, 50, "I: attack      ESC: pause");
    
    mvprintw(2, 1, "                 '");
    mvprintw(3, 1, "            *          .");
    mvprintw(4, 1, "                   *       '");
    mvprintw(5, 1, "              *                *");
    mvprintw(10, 1, "  *   '*");
    mvprintw(11, 1, "          *");
    mvprintw(12, 1, "               *");
    mvprintw(13, 1, "                       *");
    mvprintw(14, 1, "               *");
    mvprintw(15, 1, "                     *");
}

void drawQuitConfirmText() {
    mvprintw(5, 39, "    _                                              ");
    mvprintw(6, 39, "   /_\\  _ _ ___   _  _ ___ _  _   ____  _ _ _ ___  ");
    mvprintw(7, 39, "  / _ \\| '_/ -_) | || / _ \\ || | (_-< || | '_/ -_) ");
    mvprintw(8, 39, " /_/ \\_\\_| \\___|  \\_, \\___/\\_,_| /__/\\_,_|_| \\___| ");
    mvprintw(9, 39, "                  |__/                             ");
    mvprintw(10, 39, "                 | |_ ___                          ");
    mvprintw(11, 39, "            _ _  |  _/ _ \\             ___         ");
    mvprintw(12, 39, "  __ _ _  _(_) |_ \\__\\___/_ _ _ __  __|__ \\        ");
    mvprintw(13, 39, " / _` | || | |  _| / _` / _` | '  \\/ -_)/_/        ");
    mvprintw(14, 39, " \\__, |\\_,_|_|\\__| \\__, \\__,_|_|_|_\\___(_)         ");
    mvprintw(15, 39, "    |_|            |___/                           ");
}

void drawNewRecordText() {
    mvprintw(16, 43, "NEW RECORD!");
}

void drawEndText() {
    mvprintw(5, 36, "   ____    _    __  __ _____    _____     _______ ____  ");
    mvprintw(6, 36, "  / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ ");
    mvprintw(7, 36, " | |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |");
    mvprintw(8, 36, " | |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ < ");
    mvprintw(9, 36, "  \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\");
    
    mvprintw(12, 43, "__  __ __  __  __");
    mvprintw(13, 43, "|_  |  | | |_| |_  '");
    mvprintw(14, 43, "__| |_ |_| | | |_  '");
}

void drawBackground(int score, int weapon_type) {
    attron(COLOR_PAIR(11));
    mvprintw(1, 119, "SCORE: %d", score);
    switch(weapon_type) {
        case 1:
            mvprintw(3, 119, "arrow(1)");
            break;
        case 2:
            mvprintw(3, 119, "sword(2)");
            break;
        case 3:
            mvprintw(3, 119, "eraser(3)");
            break;
    }
    attroff(COLOR_PAIR(11));
}