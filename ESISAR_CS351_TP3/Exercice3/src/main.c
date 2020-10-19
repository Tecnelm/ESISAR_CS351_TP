#include <stdio.h>
int main(int argc, char *argv[])
{
    int i;
    printf("Nombre d'arguments : %d\n", argc);
    for (i = argc - 1; i > 0; i--)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}

/**
 * 
 * Ce programme permet d'afficher les arguments passé en paramètre, il commence par le dernier argument 
 * 
 * Les arguments sont les données placé après la commande pour lancer le programme 
 *
 * /