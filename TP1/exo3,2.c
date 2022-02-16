#include <ncurses.h>

int main(void) {
    int touche;
    int x, y, N;
    int x_prec, y_prec;

    initscr();
    /* Permet de retirer d'empecher les echo de l'utilisateur.*/
    noecho();

    x = COLS / 2;
    y = LINES / 2;
    N = 1;

    mvaddch(y, x, 'o');
    while (1) {
        x_prec = x;
        y_prec = y;

        touche = getch();
        if (touche == 'q' && x-N >= 0) 
        x -= N;
        if (touche == 'd'&& x+N <= COLS - 1)
        x += N;
        if (touche == 'z'&& y-N >= 0)
        y -= N;
        if (touche == 's' && y+N <= LINES - 1)
        y += N;

        /* Repositionne case initial si 'i' est pressé. */
        if (touche == 'i'){
        x = COLS / 2;
        y = LINES / 2;
        }

        if (touche == 'p' && N < 49)
            N ++;
        if (N > 1 && touche == 'm' && N < 49)
            N--;

        mvprintw(LINES - 1, 0, "Pas %d", N);
        mvaddch(y_prec, x_prec, ' ');
        mvaddch(y, x, 'o');
        
        refresh();
    }

    getch();
    endwin();
    return 0;
}