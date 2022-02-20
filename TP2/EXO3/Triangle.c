#include <ncurses.h>
#include <stdlib.h>
 
int main(int argc, char * argv[]){

    int entier;
    char symbol;
    int i, j;
    int base;
    int hauteur;

    if (argc > 2){

        entier = atoi(argv[1]);
        symbol = argv[2][0];
        base = entier * 2 + 1;
        hauteur = entier + 1;

        initscr();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(FALSE);


        for (j = 0; j < hauteur; j ++){
            for(i = 0; i < base; i++)
                addch(symbol);
            /* On retire 2 à la base pour donner cette aspect de pyramide*/
            base -= 2;
            move(j + 1, j + 1);
        }




        refresh();
        getch();
        endwin();
    }

    return 0;
}