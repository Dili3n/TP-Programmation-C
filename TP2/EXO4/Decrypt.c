#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char change_letter(int lettre, int clef){

    while (clef > 25)
        clef -= 25;
    if ((lettre - clef <= 'z' && lettre - clef >= 'a') 
    || ((lettre - clef <= 'Z' && lettre - clef >= 'A')))
        return lettre - clef;
    else if ((lettre - clef > 'a') || (lettre - clef > 'A'))
        /* Si on dépasse A on retourne sur Z */
        return lettre - clef + ('z' - 'a');

    return lettre;
}

int main(int argc, char *argv[]){

    int clef;
    int i, j;
    char ** phrase;

    /* On alloue le tableau deux dimension */
    phrase = (char **)malloc(sizeof(char **) * (argc - 1));

    for (i = 0; i < (argc - 1); i++){
        phrase[i] = (char *)malloc(sizeof(char *) * 50);
    }

    if (argc < 3)
        return -1;

    /* STR vers INT */
    clef = atoi(argv[1]);

    printf("Mot Crypté : ");
    for (i = 2; i < argc; i++){
        phrase[i - 2] = argv[i];
        printf("%s ", phrase[i - 2]);
    }

    printf("\nMot décrypté : ");
    /* Boucles qui font le décryptage */
    for (i = 0; i < argc - 2; i ++){
        for (j = 0; j < strlen(phrase[i]); j++){
            phrase[i][j] = change_letter(phrase[i][j], clef);
            printf("%c", phrase[i][j]);
        }
        printf(" ");
    }

    printf("\n");




    return 0;
}