#include <stdlib.h>
#include <stdio.h>
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
            switch (pos)
            {
            case ROW:
                add->y = index;
                add->x = index2;
                break;
            case COL:
                add->x = index;
                add->y = index2;
                break;
            }
        fillAddCel(add,matrice);

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
            switch (pos)
            {
            case ROW:
                add->y = index;
                add->x = index2;
                cellprev->nextCellrow = add;
                break;
            case COL:
                add->x = index;
                add->y = index2;
                cellprev->nextCellcol = add;
                break;
            default:
                cellprev = NULL;
                break;
            }
        }
        else
        {
            switch (pos)
            {
            case ROW:
                add->y = index;
                add->x = 0;
                infoline->cell = add;
                break;
            case COL:
                add->x = index;
                add->y = 0;
                infoline->cell = add;
                break;
            default:
                cell = NULL;
                break;
            }
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
void fillAddCel(MatriceCell *cell, Matrice *matrice)
{
      
}

void affMatrice(Matrice *matrice)
{
    MatriceInfo *row = matrice->row;
    MatriceCell *cell = row->cell;
    for (int y = 0; y < matrice->y; y++)
    {
        printf("|");
        for (int x = 0; x < matrice->x; x++)
        {
            if (cell != NULL)
            {
                printf(" %d |", x == cell->x ? cell->value : 0);
                cell = cell->nextCellcol;
            }
            else
            {
                printf(" 0 |");
            }
        }
        printf("\n");
        row = row->next;
        if (row != NULL)
            cell = row->cell;
    }
}

MatriceCell *getFirstElement(enum relativPos pos, Matrice *matrice, int x, int y)
{
    MatriceCell *cell = NULL;
    MatriceInfo *info ;

    switch (pos)
    {
    case UP:
        info = matrice->col;
        for (int i = 0; i < y; y++)
        {
            info = info->next;
        }
        cell = info->cell;
        for (int i = 0; i < x && cell != NULL; i++)
        {
            cell = cell->nextCellrow;
        }
        break;
    case LEFT:
        info = matrice->row;
        for (int i = 0; i < y; y++)
        {
            info = info->next;
        }
        cell = info->cell;
        for (int i = 0; i < x && cell != NULL; i++)
        {
            cell = cell->nextCellcol;
        }
        break;
    case DOWN:
        break;
    case RIGHT:
        break;

    default:
        break;
    }

    return cell;
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

*/
