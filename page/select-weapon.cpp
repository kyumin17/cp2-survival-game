#include "page.hpp"

int selectWeaponPage() {
    /*
    선택된 무기의 인덱스를 반환한다.
    */
    char ch = getch();
    while (1) {
        if (ch == '1') {
            return 0;
        } else if (ch == '2') {
            return 1;
        } else if (ch == '3') {
            return 2;
        }
    }
}