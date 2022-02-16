#include <ncurses.h>
#include <unistd.h>

int main(void) {
    int touche, val, delai;

    initscr();
    cbreak();
    /* n'écrit pas les touches du clavier sur terminal */
    noecho();
    /* Cette fonction permet d'indiquer qu'il ne faut pas bloquer l'appel
    de la fonction getch lorsqu'il n'y a pas de caractère de disponible. */
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    val = 0;
    delai = 1000000;
    mvprintw(0, 0, "Valeur : ");

    /* Mettre en gras la valeur*/
    attron(A_BOLD);
    printw("%3d",val);
    attroff(A_BOLD);

    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == 'r')
            val = 0;
            if (touche == KEY_UP)
            delai /= 2;
            if (touche == KEY_DOWN)
            delai *= 2;
        } if (touche == 'q')
            break;
        mvprintw(0, 0, "Valeur : ");
        attron(A_BOLD);
        printw("%3d",val);
        attroff(A_BOLD);
        refresh();

        val = (val + 1) % 128;
        usleep(delai);
    }
    getch();
    endwin();
    return 0;
}