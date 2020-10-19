#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>

struct matrice
{
    int **matrice;
    int sx;
    int sy;
};

Matrice *createMatrice(int sx, int sy, int iniVal)
{
    int **ly = malloc(sizeof(int *) * sy / sizeof(char));
    for (int y = 0; y < sy; y++)
    {
        ly[y] = malloc(sizeof(int) * sx / sizeof(char));
        for (int x = 0; x < sx; x++)
        {
            ly[y][x] = iniVal;
        }
    }

    Matrice *matrice = malloc(sizeof(Matrice) / sizeof(char));

    matrice->matrice = ly;
    matrice->sx = sx;
    matrice->sy = sy;
    return matrice;
}

void freeMatrice(Matrice *matrice)
{
    for (int i = 0; i < matrice->sy; i++)
    {
        free(matrice->matrice[i]);
    }
    free(matrice->matrice);
    free(matrice);
}

void afficheMatrice(Matrice *matrice)
{
    for (int y = 0; y < matrice->sy; y++)
    {
        for (int x = 0; x < matrice->sx; x++)
        {
            printf("%d\t", matrice->matrice[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrice *additionnerMatrices(Matrice *m1, Matrice *m2)
{
    Matrice *result = NULL;

    if (m1->sx == m2->sx && m1->sy == m2->sy)
    {
        result = createMatrice(m1->sx, m2->sy, 0);

        for (int y = 0; y < m1->sy; y++)
        {
            for (int x = 0; x < m1->sx; x++)
            {
                result->matrice[y][x] = m1->matrice[y][x] + m2->matrice[y][x];
            }
        }
    }

    return result;
}

Matrice *transposeeMatrice(Matrice* m)
{
    Matrice * result = createMatrice(m->sy,m->sx,0);

        for (int y = 0; y < m->sy; y++)
        {
            for (int x = 0; x < m->sx; x++)
            {
                result->matrice[x][y] = m->matrice[y][x];
            }
        }
    return result;
}

Matrice* produitMatrice(Matrice* m1, Matrice* m2)
{
    Matrice* result = NULL;

    if(m1->sy == m2->sx)
    {
        result = createMatrice(m1->sy,m2->sx,0);

        for(int l1 = 0 ; l1< m1->sy ; l1++)
        {
            for(int c = 0;c < m2->sx; c++)
            {
                for(int c2 = 0 ; c2 < m2->sy; c2++)
                {
                    result->matrice[l1][c] = m1->matrice[l1][c2]*m2->matrice[c2][c];
                }
            }
        }
    }
    else
    {
        printf("Produit impossible\n");
    }
    
    return result;
}