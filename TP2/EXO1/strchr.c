#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char * chaine1, * chaine2 = "L'ecole est à 2 kilomètres !";
    char * changer;


    printf("Phrase de base : \n %s", chaine2);

    
    chaine1 = (char *) malloc(sizeof(char) * ((strlen(chaine2)) + 1));
    strcpy(chaine1, chaine2);

    /* remplace tous les 'e' de la phrase par des 'Z' */
    while ((changer = strchr(chaine1, 'e'))){
        *changer = 'Z'; 
    }


    /* Phrase finale */
    printf("\n Phrase finale : \n %s", chaine1);

    free(chaine1);


    return 0;
}