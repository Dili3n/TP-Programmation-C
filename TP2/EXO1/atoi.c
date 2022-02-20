#include <stdio.h>
#include <stdlib.h>   

int main() {

    char chaine1[50];
    int a;

    printf( "Entrez un entier (str): " );
    scanf( "%s", chaine1 );
       
    a = atoi(chaine1);
    printf("\n%d (int)\n", a);

    return 0;
}