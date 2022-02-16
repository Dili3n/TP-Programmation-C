#include <ncurses.h>
#include <unistd.h>

#define DELAI 50000

int main(void) {
    int x, y;

    initscr();

    x = 0;
    y = 0;
    while(1) {
        /* Efface la fenêtre */
        clear();
        mvaddch(y, x, 'o');
        refresh();

        usleep(DELAI);
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
        
    }
    endwin();
    return 0;
    }