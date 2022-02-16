#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void coloriage(int y, int x){

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLUE);

    attron(COLOR_PAIR(1));
    mvaddch(y, x, ' ');
    attroff(COLOR_PAIR(1));    

}


void contruire_terrain(void){

    int i, j;

    for (i = 0; i < COLS; i++){
        for (j = 0; j < LINES; j ++){
            addch('0');
        }
    }

    refresh();

}

int main(void){

    int souris_x, souris_y;
    int touche;
    MEVENT ev;
    int ** terrain;
    int i, j;

    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    /* Configure les événements de souris à surveiller 
        Dans ce cas là tous les événements de la souris ! */
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    contruire_terrain();


    /* Initialisation tableau deux dim*/
    terrain = (int **)malloc(sizeof(int **) * LINES);

    for (i = 0; i < LINES; i++){
        terrain[i] = (int *)malloc(sizeof(int *) * COLS);
    }

    for(i = 0; i < LINES; i++){
        move(i, 0);
        for(j = 0; j < COLS; j++){
            addch('0');
            terrain[i][j] = 0;
        }
    }

    while(1){
        
        touche = getch();

        if (touche != ERR){
            if (touche == KEY_MOUSE && getmouse(&ev) == OK){

                souris_x = ev.x;
                souris_y = ev.y;

                /* On vérifie l'indice à telle position du tableau*/
                if (terrain[souris_y][souris_x] == 0){
                    mvaddch(souris_y, souris_x, '1');
                    terrain[souris_y][souris_x] = 1;
                } else if (terrain[souris_y][souris_x] == 1){
                    mvaddch(souris_y, souris_x, '2');
                    terrain[souris_y][souris_x] = 2;
                } else if (terrain[souris_y][souris_x] == 2)
                    coloriage(souris_y, souris_x);

            }else if (touche == 'q')
                break;
            refresh();

        }
    }

    refresh();
    getch();
    endwin();


    return 0;
}