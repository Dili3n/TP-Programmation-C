#include <ncurses.h>

int main(void){

    int x, y;
    int i, j;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);

    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);

    x = COLS/2 - 15;
    y = LINES/2 - ((3 - 1) / 2);

    move(y, x);

    for(i = 1; i < 4; i++){
        for(j = 0; j < 15; j++){

            /* Changement de couleur */
            attron(COLOR_PAIR(1));
            printw("  ");
            attroff(COLOR_PAIR(1));
        }
        /* On remet à la position initial avec une ligne en plus */
        move(y + i, x);
    }

    refresh();
    getch();
    endwin();
    return 0;
}