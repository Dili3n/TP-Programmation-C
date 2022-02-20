#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

int vitesse(void){

    int touche;
    int speed = 0; 
    
    clear();
    echo();
    mvprintw(1, 5, "Quelle vitesse voulez-vous ?");
    refresh();
    while (speed <= 0){
        mvscanw(2, 5, "%d", &speed);

        /* On quitte le menu si 'q' est pressé */

        touche = getch();
        if(touche == 'q')
            return 1;
        timeout(0);
    }
    return speed;
}


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



void rebond(int speed){

    int touche, start = 0;
    int x, y;
    int nb_x = 1;
    int nb_y = 1;
    int vitesse = (1000000)/(speed);

    clear();
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
            
            /* On change les mouvement selon ou se trouve le cube bleu */
            if ((y == LINES/2 - 5) || (y == LINES/2 + 3))
                nb_y = nb_y * (-1);
            if ((x ==  COLS/2 + 16) || (x == COLS/2 - 20)){ 
                nb_x = nb_x * (-1);

            }
            set_carre(x, y);
            refresh();
            usleep(vitesse);


        }
        if (touche == 'q')
            break;
    }
}

void credit(void){

    int touche;

    clear();
    mvprintw(1, 5, ": Crédits :");
    mvprintw(2, 5, "Dilien Oeuvrard");
    mvprintw(3, 5, "Lucas Zaverio");
    mvprintw(5, 5, "Date d'édition : 10/02/2022");
    mvprintw(7, 5, "L2 Informatique");
    mvprintw(8, 5, "TP 6 Perf C");
    refresh();

    touche = getch();
    /* Tant que l'utilisateur n'appuie pas sur entrer on
       reste sur ce menu */
    while(touche != '\n'){
        touche = getch();
    }
}

void set_menu(int indice){

    if (indice == 1){
        /* Le mode surligné */
        attron(A_REVERSE);
        mvprintw(1, 5, "1 - Démarrer");
        attroff(A_REVERSE);
        mvprintw(2, 5, "2 - Options");
        mvprintw(3, 5, "3 - Crédits");
        mvprintw(4, 5, "4 - Quitter");

    } else if(indice == 2){
        mvprintw(1, 5, "1 - Démarrer");
        attron(A_REVERSE);
        mvprintw(2, 5, "2 - Options");
        attroff(A_REVERSE);
        mvprintw(3, 5, "3 - Crédits");
        mvprintw(4, 5, "4 - Quitter");

    } else if(indice == 3){
        mvprintw(1, 5, "1 - Démarrer");
        mvprintw(2, 5, "2 - Options");
        attron(A_REVERSE);
        mvprintw(3, 5, "3 - Crédits");
        attroff(A_REVERSE);
        mvprintw(4, 5, "4 - Quitter");
    } else {
        mvprintw(1, 5, "1 - Démarrer");
        mvprintw(2, 5, "2 - Options");
        mvprintw(3, 5, "3 - Crédits");
        attron(A_REVERSE);
        mvprintw(4, 5, "4 - Quitter");
        attroff(A_REVERSE);
    }
    refresh();


}
int main(void){

    int touche;
    int indice = 1;
    int speed = 1;

    initscr();

    start_color();

    set_menu(indice);
    
    while(1){

        keypad(stdscr, TRUE);
        curs_set(FALSE);
        noecho();
        touche = getch();

        if (touche == KEY_DOWN)
            indice ++;
        if (touche == KEY_UP)
            indice --;

        if (touche == '\n'){
            if(indice == 4)
                break;
            if(indice == 3){
                credit();
                clear();
            }if(indice == 2){
                speed = vitesse();
                clear();
            }if(indice == 1){
                rebond(speed);
                clear();
                refresh();
                

            }
        /* On fait fonctionner le menu avec les chiffres */
        } else if ((touche == '1') || (touche == '2') 
        || (touche == '3') || (touche == '4')){
            if(touche == '4')
                break;
            if(touche == '3'){
                credit();
                clear();
            }if (touche == '2'){
                speed = vitesse();
                clear();
            }if(touche == '1'){
                rebond(speed);
                clear();
                refresh();
            }
        }

        if (indice == 5)
            indice = 1;
        
        set_menu(indice);
        refresh();

    }

    refresh();
    endwin();

    return 0;
}


