
#include <stdio.h>
#include "main.h"

/**
 * La différence entre ++a et a++ (pré et post incrementation) est le fait que dans le cas de la post incrementation l'incrementation de la variable 
 * est réalisé après la réalisation de l'intruction suivante, 
 * exemple modification d'une case d'un tableau:
 * int index = 0;
 * int a [10];
 * 
 *  a[index++] = 3 ; dans ce cas la valeur de 3 est mise dans la case 0 puis index passe a 1:
 *  a[++index] = 10 ; dans ce cas index est incrementé à 1 puis la valeur 10 est mise dans la case 1 ;
 */

int main()
{
    int i, j, k, l;
    i = j = k = l = 0;
    while (i < 9)
    {
        printf("i++=%d, ++j=%d, k--=%d, --l=%d\n", i++, ++j, k--, --l);
    }
    printf("i=%d, j=%d, k=%d, l=%d\n", i, j, k, l);
    return (0);
}

void flushScanf()
{
    char c;

    while ((c = getchar()) != EOF && c != '\n')
        ;
}