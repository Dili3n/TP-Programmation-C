#include <ncurses.h>

int main(void) {
    int indice = 0;
    int entier;

    initscr();

    do{

        entier = 1;
        mvscanw(indice, indice, "%d", &entier);
        refresh();
        indice ++;

    }while(entier != 0);

    endwin();
    return 0;
}