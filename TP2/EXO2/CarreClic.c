#include <ncurses.h>


void set_carre(int indice){

    int x, y;
    int i, j;

    x = COLS/2 - 10;
    y = LINES/2 - ((10 - 1) / 2);

    move(y, x);

    for(i = 1; i < 11; i++){
        
        for(j = 0; j < 10; j++){

            /* Changement de couleur */

            if (indice == 1){
                attron(COLOR_PAIR(1));
                printw("  ");
                attroff(COLOR_PAIR(1));
            }else{
                attron(COLOR_PAIR(2));
                printw("  ");
                attroff(COLOR_PAIR(2));
            }   
        }
        /* On remet à la position initial avec une ligne en plus */
        move(y + i, x);
    }
    refresh();
}

int main(void){

    int touche, indice = 1;
    int souris_x, souris_y;
    MEVENT ev;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);

    start_color();
    /* Initialisation des couleurs */
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    set_carre(1);

    while(1){

        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            souris_x = ev.x;
            souris_y = ev.y;

            /* Detection des clics. */
            if ((souris_x >= COLS/2 - 10) && (souris_x <= COLS/2 + 9)
                && (souris_y >= LINES/2 - 4) && (souris_y <= LINES/2 + 5)){
                    indice ++;
                    set_carre(indice);

            }

        }
        if(indice == 2)
            indice = 0;
    }

    refresh();
    endwin();
    return 0;
}