#include <stdio.h>
#include <string.h>

int main() {

    char chaine1[50];
    char chaine2[50];

    printf( "Entrez la première chaîne de caractère : " );
    scanf( "%s", chaine1 );

    printf( "Entrez la deuxième chaîne de caractère : " );
    scanf( "%s", chaine2 );
       
    if ( strcmp(chaine1, chaine2) == 0) {
        printf( "Les deux châines de caractères sont identique\n" );
    } else {
        printf( "Les deux chaînes de caractères sont différentes\n" );
    } 

    return 0;
}