#include <ncurses.h>
#include <stdio.h>

    int main(void) {

    int i, j, k;
    int start_x, start_y;

    initscr();

    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);

    curs_set(FALSE);

    start_x = COLS/2;
    start_y = LINES/2 - 11;

    printf("%d", COLS);

    for(i = 0; i < 10; i ++){
        start_y ++;
        move(start_y, start_x);
        for (j = 0; j < 5; j ++){

            if (i % 2 == 0){
                for (k = 1; k < 3; k++){
                    attron(COLOR_PAIR(k));
                    printw("  ");
                    attroff(COLOR_PAIR(k));
                }
            } else {
                for (k = 2; k > 0; k--){
                    attron(COLOR_PAIR(k));
                    printw("  ");
                    attroff(COLOR_PAIR(k));
                }
            }   
        }
    }

    refresh();
    getch();
    endwin();
    return 0;
}