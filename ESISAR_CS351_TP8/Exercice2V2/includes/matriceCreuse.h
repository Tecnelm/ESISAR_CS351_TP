#ifndef __MATRICECREUSE_H__
#define __MATRICECREUSE_H__

typedef struct matriceCell MatriceCell;
typedef struct matriceinfo MatriceInfo;

struct matriceCell
{
    int x;
    int y;
    MatriceCell *nextCellrow;
    MatriceCell *nextCellcol;

    MatriceCell *precCellRow;
    MatriceCell *precCellcol;

    int value;
};

struct matriceinfo
{
    int id;
    MatriceInfo *next;
    MatriceCell *cell;
};
typedef struct matrice
{
    int x;
    int y;
    MatriceInfo *row;
    MatriceInfo *col;
} Matrice;

Matrice *createMatrice(int x, int y, int initVal);
void insertElement(int x, int y, int value, Matrice *matrice);
void freeAll(Matrice *matrice);
void affMatrice(Matrice *matrice);
void insertcellrow(MatriceInfo *ligne, MatriceCell *cell, int pos);
void insertcellcol(MatriceInfo *ligne, MatriceCell *cell, int pos);
Matrice *addMatrice(Matrice *A, Matrice *B);

int produitLC(MatriceInfo *ligne, MatriceInfo *colonne);
Matrice *produitMatrice(Matrice *A, Matrice *B);

#endif