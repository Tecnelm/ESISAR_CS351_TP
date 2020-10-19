#include <stdio.h>

void incr(int *a) { *a = (*a) + 1; }

int main()
{
    int x = 5;
    incr(&x);
    printf("%d\n", x); /* ce programme affiche 6 */
    return 0;
}

/**
 * On remarque que la valeur est passé dans une fonction et est bien incrementer sans "sauvegarde ou modification de la valeur initial (x = incr(x))" 
 * on a donc bien un "passage par reférence"
 */

