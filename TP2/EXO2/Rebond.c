#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>


void set_rectangle(void){

    int x, y;
    int i, j;

    x = COLS/2 - 20;
    y = LINES/2 - 5;

    move(y, x);

    for(i = 1; i < 11; i++){
        
        for(j = 0; j < 20; j++){

            /* Changement de couleur */
                attron(COLOR_PAIR(1));
                printw("  ");
                attroff(COLOR_PAIR(1)); 
        }
        /* On remet à la position initial avec une ligne en plus */
        move(y + i, x);
    }
}

void set_carre(int x, int y){


    int i, j;

    move(y, x);

    for(i = 1; i < 3; i++){
        
        for(j = 0; j < 2; j++){

            /* Changement de couleur */
                attron(COLOR_PAIR(2));
                printw("  ");
                attroff(COLOR_PAIR(2)); 
        }
        /* On remet à la position initial avec une ligne en plus */
        move(y + i, x);
    }
}

int main(void){

    int touche;
    int x, y, start = 0;
    int nb_x = 1;
    int nb_y = 1;


    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);

    set_rectangle();

    x = COLS/2 - 2;
    y = LINES/2 - 1;

    set_carre(x, y);

    

    while(1){

        touche = getch();
        timeout(0);
        if (touche == '\n'){
            if(start == 0)
                start = 1;
            else
                start = 0;

        }
        if (start == 1){
            set_rectangle();
            x = x + nb_x;
            y = y - nb_y;
            
            /* On change les mouvements selon ou se trouve le cube bleu */
            if ((y == LINES/2 - 5) || (y == LINES/2 + 3))
                nb_y = nb_y * (-1);
            if ((x ==  COLS/2 + 16) || (x == COLS/2 - 20)){ 
                nb_x = nb_x * (-1);

            }
            set_carre(x, y);
            refresh();
            usleep(500000);


        }
    }

    refresh();
    endwin();
    return 0;
}