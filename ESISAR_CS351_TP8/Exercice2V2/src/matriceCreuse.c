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
        add->id = y;
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

void insertElement(int x, int y, int value, Matrice *matrice)
{
    MatriceCell *newcell;

    MatriceInfo *rowcell = matrice->row;
    MatriceInfo *colcell = matrice->col;
    int indexX;
    int indexY;
    if (x < matrice->x && y < matrice->y && value != 0)
    {
        newcell = malloc(sizeof(MatriceCell) / sizeof(char));
        newcell->y = y;
        newcell->x = x;
        newcell->value = value;

        for (indexX = 0; colcell != NULL && indexX < x; indexX++)
        {
            colcell = colcell->next;
        }

        for (indexY = 0; rowcell != NULL && indexY < y; indexY++)
        {
            rowcell = rowcell->next;
        }
        insertcellcol(colcell, newcell, y);
        insertcellrow(rowcell, newcell, x);
    }
    else
    {
        if (!value)
            fprintf(stderr, "ERROR BAD POSITION \n");
    }
}

void insertcellrow(MatriceInfo *ligne, MatriceCell *cell, int pos)
{
    int index;
    MatriceCell *prevcell;
    if (ligne->cell == NULL)
    {
        cell->precCellRow = NULL;
        cell->nextCellrow = NULL;
        ligne->cell = cell;
    }
    else
    {
        prevcell = ligne->cell;
        for (index = 0; index < pos && prevcell->nextCellrow != NULL; index++)
        {
            prevcell = prevcell->nextCellrow;
        }
        if (prevcell->nextCellrow == NULL && index < pos)
        {
            prevcell->nextCellrow = cell;
            cell->precCellRow = prevcell;
            cell->nextCellrow = NULL;
        }
        else
        {
            cell->precCellRow = prevcell->precCellRow;
            cell->nextCellrow = prevcell;
            prevcell->precCellRow = cell;
            if (cell->precCellRow == NULL)
            {
                ligne->cell = cell;
            }
        }
    }
}

void insertcellcol(MatriceInfo *ligne, MatriceCell *cell, int pos)
{
    int index;
    MatriceCell *prevcell;
    if (ligne->cell == NULL)
    {
        cell->precCellcol = NULL;
        cell->nextCellcol = NULL;
        ligne->cell = cell;
    }
    else
    {
        prevcell = ligne->cell;
        for (index = 0; index < pos && prevcell->nextCellcol != NULL; index++)
        {
            prevcell = prevcell->nextCellcol;
        }
        if (prevcell->nextCellcol == NULL && index < pos)
        {
            prevcell->nextCellcol = cell;
            cell->precCellcol = prevcell;
            cell->nextCellcol = NULL;
        }
        else
        {
            cell->precCellcol = prevcell->precCellcol;
            cell->nextCellcol = prevcell;
            prevcell->precCellcol = cell;
            if (cell->precCellcol == NULL)
            {
                ligne->cell = cell;
            }
        }
    }
}

void freeAll(Matrice *matrice)
{
    MatriceInfo *nextM = matrice->row;
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
    current = matrice->col;
    for (int i = 0; i < matrice->y; i++)
    {

        nextM = current->next;
        free(current);
        current = nextM;
    }

    free(matrice);
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
                if (cell->x == x && cell->y == y)
                {
                    printf(" %d |", cell->value);
                    cell = cell->nextCellrow;
                }
                else
                {
                    printf(" 0 |");
                }
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
    printf("\n");
}

Matrice *addMatrice(Matrice *A, Matrice *B)
{
    MatriceCell *cA;
    MatriceCell *cB;
    MatriceInfo *ligneA = A->row;
    MatriceInfo *ligneB = B->row;

    Matrice *matrice;
    int add;
    int x;

    if (A->x == B->x && A->y == B->y)
    {
        matrice = createMatrice(A->x, A->y, 0);

        for (int l = 0; l < A->y; l++)
        {

            cA = ligneA->cell;
            cB = ligneB->cell;

            while (cA || cB != NULL)
            {
                if (cA != NULL && cB != NULL)
                {
                    if (cA->x == cB->x)
                    {
                        add = cA->value + cB->value;
                        x = cA->x;
                        cA = cA->nextCellrow;
                        cB = cB->nextCellrow;
                    }
                    else if (cA->x < cB->x)
                    {
                        add = cA->value;
                        x = cA->x;
                        cA = cA->nextCellcol;
                    }
                    else
                    {
                        x = cB->x;
                        add = cB->value;
                        cB = cB->nextCellcol;
                    }
                }
                else
                {
                    if (cB == NULL)
                    {
                        add = cA->value;
                        x = cA->x;
                        cA = cA->nextCellcol;
                    }
                    else
                    {
                        x = cB->x;
                        add = cB->value;
                        cB = cB->nextCellcol;
                    }
                }

                insertElement(x, l, add, matrice);
            }
            ligneA = ligneA->next;
            ligneB = ligneB->next;
        }
    }
    return matrice;
}

int produitLC(MatriceInfo *ligne, MatriceInfo *colonne)
{
    MatriceCell *cellA = ligne->cell;
    MatriceCell *cellB = colonne->cell;
    int resutlt = 0;

    while (cellA != NULL && cellB != NULL)
    {
        if (cellA->x == cellB->y)
        {
            resutlt += cellA->value * cellB->value;
            cellA = cellA->nextCellrow;
            cellB = cellB->nextCellcol;
        }
        else if (cellA->x < cellB->y)
        {
            cellA = cellA->nextCellrow;
        }
        else
        {
            cellB = cellB->nextCellcol;
        }
    }

    return resutlt;
}

Matrice *produitMatrice(Matrice *A, Matrice *B)
{
    Matrice *result;
    MatriceInfo *ligne = A->row;
    MatriceInfo *colonne = B->col;

    if (A->y == B->x)
    {
        result = createMatrice(A->y, B->x, 0);

        for (int l = 0; l < A->y; l++)
        {

            for (int c = 0; c < B->x; c++)
            {

                insertElement(c, l, produitLC(ligne, colonne), result);
                colonne = colonne->next;
            }
            ligne = ligne->next;
            colonne = B->col;
        }
    }
    return result;
}
