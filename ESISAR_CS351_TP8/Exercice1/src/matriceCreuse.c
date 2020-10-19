#include <stdlib.h>
#include "matriceCreuse.h"

Matrice *createMatrice(int x, int y, int initVal)
{
    Matrice *matrice = malloc(sizeof(Matrice) / sizeof(char));
    matrice->x = x;
    matrice->y = y;
    MatriceInfo *add;
    MatriceInfo *prev = NULL;

    for (int i = 0; i < x; i++)
    {

        add = malloc(sizeof(MatriceInfo) / sizeof(char));
        add->cell = NULL;
        add->next = NULL;
        add->id = i;
        if (prev == NULL)
        {
            matrice->col = add;
        }
        else
            prev->next = add;
        prev = add;
    }
    prev = NULL;
    for (int i = 0; i < y; i++)
    {
        add = malloc(sizeof(MatriceInfo) / sizeof(char));
        add->cell = NULL;
        add->next = NULL;
        add->id = i;
        if (prev == NULL)
        {
            matrice->row = add;
        }
        else
            prev->next = add;
        prev = add;
    }
    return matrice;
}

void insertElement(enum position pos, int id, int value, Matrice *matrice)
{
    MatriceInfo *infoline;
    MatriceCell *cell;
    MatriceCell *cellprev = NULL;
    MatriceCell *add;
    int index = 0, index2 = 0;
    int max;
    switch (pos)
    {
    case ROW:
        infoline = matrice->row;
        max = matrice->y;
        break;
    case COL:
        infoline = matrice->col;
        max = matrice->x;
        break;
    default:
        infoline = NULL;
        break;
    }

    for (index = 0; index < max && index < id; index++)
    {
        infoline = infoline->next;
    }
    if (index == id)
    {

        add = malloc(sizeof(MatriceCell) / sizeof(char));
        add->value = value;
        /**
             * TODO
             * faire une fonction qui permet d'avoir l'élément haut bas droite gauche
             */
        add->nextCellcol = NULL;
        add->nextCellrow = NULL;
        add->precCellcol = cellprev;
        add->precCellRow = NULL;

        cell = infoline->cell;
        if (cell != NULL)
        {

            while (cell != NULL)
            {
                cellprev = cell;
                switch (pos)
                {
                case ROW:
                    cell = cell->nextCellrow;
                    break;
                case COL:
                    cell = cell->nextCellcol;
                    break;
                default:
                    cell = NULL;
                    break;
                }
                index2++;
            }
            cell = cellprev;
        }
        switch (pos)
        {
        case ROW:
            add->y = index;
            add->x = index2;
            cell->nextCellrow = add;
            break;
        case COL:
            add->x = index;
            add->y = index2;
            cell->nextCellcol = add;
            break;
        default:
            cell = NULL;
            break;
        }
    }
}
void freeAll(Matrice *matrice)
{
    MatriceInfo *nextM = matrice->col;
    MatriceInfo *current = nextM;
    MatriceCell *next;
    MatriceCell *cell;

    for (int i = 0; i < matrice->x; i++)
    {
        cell = current->cell;
        while (cell != NULL)
        {
            next = cell->nextCellrow;
            free(cell);
            cell = next;
        }
        nextM = current->next;
        free(current);
        current = nextM;
    }
    current = matrice->row;
    for (int i = 0; i < matrice->y; i++)
    {

        nextM = current->next;
        free(current);
        current = nextM;
    }

    free(matrice);
}
/*
add = malloc(sizeof(MatriceInfo) / sizeof(char));
        add->cell = NULL;
        add->next = NULL;
        if (prev == NULL)
        {
            matrice->col = add;
        }
        else
            prev->next = add;
        prev = add;*/

void getLast(MatriceCell *cell)
{
}
/*
void freeAll(MatriceInfo *matrice)
{
    MatriceInfo *nextM = matrice->nextcol;
    MatriceInfo *current = nextM;
    MatriceCell *next;
    MatriceCell *cell;

    for (int i = 0; i < matrice->x; i++)
    {
        cell = current->cell;
        while (cell != NULL)
        {
            next = cell->nextCellrow;
            free(cell);
            cell = next;
        }
        nextM = current->nextcol;
        free(current);
        current = nextM;
    }
    current = matrice->nextrow;
    for (int i = 0; i < matrice->y; i++)
    {

        nextM = current->nextrow;
        free(current);
        current = nextM;
    }

    free(matrice);
}
*/
/*
void fillMatrice(Matrice* mat)
{
    int val;
    int res;

    for(int y = 0 ; y < mat->y ; y++)
    {
    
    }
}




void delElement(int x ,int y, Matrice* matrice){

}
void affList(Matrice * matrice)
{
    Matrice* colnext = matrice->nextCellcol;
    Matrice* rownext = matrice->nextCellrow;
    while (rownext != NULL)
    {
        
    }
    

}
*/
