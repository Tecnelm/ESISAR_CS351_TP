#include <stdio.h>
#include"sort.h"


int main(int argc, char const *argv[])
{
    struct interv interL[] = {createInter(0, 3), createInter(3, 7), createInter(7, 10)};

    int tab[] = {5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8};

    sort(tab, 15,interL,3);
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    /* code */
    return 0;
}

