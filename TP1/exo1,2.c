#include <ncurses.h>

    int main(void) {    
    initscr();

    /* Move n'est pas utile car position initial en 0, 0.
    move(0, 0); */

    attron(A_BOLD | A_UNDERLINE);
    printw("*10*");
    attroff(A_BOLD | A_UNDERLINE);

    refresh();
    getch();
    endwin();

    return 0;
}