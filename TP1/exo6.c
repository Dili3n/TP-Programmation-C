#include <ncurses.h>

int main(void) {
    int entier;
    int i, j;

    initscr();

    do{
        /* Pour éviter un warning ! */
        entier = 0;
        scanw("%d", &entier);

    }while(entier < 1);
    
    move(1, 0);

    for (i = 0; i < entier + 1; i++){
        for (j = 0; j < i; j ++) {
        printw("*");
        }
        printw("\n");
    }

    refresh();
    getch();
    endwin();
    return 0;
}