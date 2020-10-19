#include <stdio.h>
#include <stdlib.h>
#include "folder.h"

int lireDonnee(const char *nomFichier, int *T)
{
    FILE *file = NULL;
    int index = 0;
    file = fopen(nomFichier, "r");
    int res;

    if (file == NULL)
    {
        fprintf(stderr, "ERROR OPEN FOLDER\n");
        exit(1);
    }

    while (!feof(file))
    {
        res = fscanf(file, "%d", T + index);
        if(res)
            index++;
    }
    index--;
    fclose(file);
    return index;
}
void afficherTableau(int *T, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", T[i]);
    }
}


void triABulle(int *T, int size)
{
    int i, l;
    int trie = 1;
    int temp;
    l = size;
    while (l > 0 && trie)
    {

        trie = 0;
        for (i = 0; i < l - 1; i++)
        {
            if (T[i] > T[i + 1])
            { // programme stable grâce à l'inégalité stricte.
                temp = T[i];
                T[i] = T[i + 1];
                T[i + 1] = temp;
                trie = 1;
            }
        }
        l--;
    }
}
void enregistrerDonnees(const char *nomFichier, int *T, int size)
{
    FILE *file = NULL;
    file = fopen(nomFichier, "w");
    if (file == NULL)
    {
        fprintf(stderr, "ERROR OPEN FOLDER\n");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", T[i]);
    }

    fclose(file);
}