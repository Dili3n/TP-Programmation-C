#include <ncurses.h>

int main(void) {

    char chaine[128];

    initscr();

    mvgetstr(2, 4, chaine);
    mvprintw(0, 0, "%s", chaine);

    refresh();
    getch();
    endwin();
    return 0;
}