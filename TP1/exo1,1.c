#include <ncurses.h>

int main(void) {
    
    initscr(); /* init screen LINES * COLS */

    /* Première méthode
    move(8, 4);
    addch('4');
    addch('!');
    addch('+');
    addch('2');
    addch('!');*/

    /* Deuxième méthode
    mvaddch(8, 4, '4');
    mvaddch(8, 5, '!');
    mvaddch(8, 6, '+');
    mvaddch(8, 7, '2');
    mvaddch(8, 8, '!'); */

    /* Trosième méthode */
    mvprintw(8, 4, "4!+2!");

    refresh();  
    getch();
    endwin();

    return 0;
}