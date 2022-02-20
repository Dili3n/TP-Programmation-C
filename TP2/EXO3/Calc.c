#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
 
int main(int argc, char *argv[]) {

    char * endptr1, *str1;
    char * endptr2, *str2;
    long nombre1, nombre2;
    errno = 0;


    /* On vérifie que l'utilisateur n'entre 
     * que trois arguments, deux entiers et un opérateur 
     */
    if (argc != 4){
        fprintf(stderr, "Vous n'avez pas le bon nombre d'arguments.\n");
        exit(EXIT_FAILURE);
    }

    /* Utilisation de strtol au lieu de atoi car plus pratique et mieux détection negatif*/
    str1 = argv[2]; 
    nombre1 = strtol(str1, &endptr1, 10);
    str2 = argv[3]; 
    nombre2 = strtol(str2, &endptr2, 10);

    /* '\0' pour éviter lesstr après un nombre. */
    if (errno != 0 || (endptr1 == str1 || endptr2 == str2) 
       || *endptr1 != '\0' || *endptr2 != '\0' ) {
        fprintf(stderr, "21ème siècle et les calculs de str ne fonctionnent toujours pas !\n");
        exit(EXIT_FAILURE);
    }

     /* On utilise strcmp pour savoir si l'opérateur entré par l'utilisateur est un + */
    if (strcmp(argv[1], "+") == 0){
        fprintf(stdout, "Addition : %ld + %ld = %ld\n", nombre1, nombre2, nombre1 + nombre2);
        exit(EXIT_SUCCESS);

    /* On utilise strcmp pour savoir si l'opérateur entré par l'utilisateur est un - */
    }else if (strcmp(argv[1], "-") == 0){
        fprintf(stdout, "Soustraction : %ld - %ld = %ld\n", nombre1, nombre2, nombre1 - nombre2);
        exit(EXIT_SUCCESS);

    }else if (strcmp(argv[1], "x") == 0){
        fprintf(stdout, "Multiplication : %ld x %ld = %ld\n", nombre1, nombre2, nombre1 * nombre2);
        exit(EXIT_SUCCESS);

    /* On utilise strcmp pour savoir si l'opérateur entré par l'utilisateur est un / */
    }else if (strcmp(argv[1], "/") == 0) { 
        if (nombre2 == 0) {
            fprintf(stderr, "La division par 0 est impossible\n");
            exit(EXIT_FAILURE);
        } else {
        fprintf(stdout, "Division : %ld / %ld = %ld\n", nombre1, nombre2, nombre1 / nombre2);
        }
    }

    else {
        fprintf(stderr, "Le deuxième argument que vous avez entré n'est pas un opérateur.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}