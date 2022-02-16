#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {

    int touche;
    int temps = 500000;
    int x, y;
    int rd_x, rd_y;

    initscr();

    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();

    x = COLS/2;
    y = LINES/2;

    /* SET le random*/
    srand(time(NULL));

    while(1){
        touche = getch();
        move(y, x);
        addch('o');
        
        do{
        rd_x = rand() % 3;
        rd_y = rand() % 3;
        /* Condition pour position orthogonales.*/
        } while((rd_x - 1 == 0 && rd_y - 1 == 0) || (rd_x - 1 == 1 && rd_y - 1 == 1) ||
                (rd_x - 1 == -1 && rd_y - 1 == 1) || (rd_x - 1 == 1 && rd_y - 1 == -1) ||
                (rd_x - 1 == -1 && rd_y - 1 == -1) || x + rd_x - 1 == -1 || y + rd_y - 1 == -1 ||
                x + rd_x - 1 == COLS || y + rd_y - 1 == LINES);

        refresh();

        if (touche == '\n'){
            while(1){
                touche = getch();
                if (touche == '\n')
                    break;
            }
        } else if (touche == KEY_UP)
            temps /= 2;
        else if (touche == KEY_DOWN)
            temps *= 2;


        usleep(temps);
        mvaddch(y, x, 'x');
        x = x + rd_x - 1;
        y = y + rd_y - 1;

    }
    
    refresh();
    getch();
    endwin();

    return 0;
}