#ifndef __MATRICECREUSE_H__
#define __MATRICECREUSE_H__

typedef struct matriceCell MatriceCell;
typedef struct matriceinfo MatriceInfo;

struct matriceCell
{
    int x;
    int y;
    MatriceCell* nextCellrow;
    MatriceCell* nextCellcol;

    MatriceCell* precCellRow;
    MatriceCell* precCellcol;
    
    int value;
};

struct matriceinfo
{
    int id;
    MatriceInfo* next;
    MatriceCell* cell;
};
typedef struct matrice 
{
    int x;
    int y;
    MatriceInfo* row;
    MatriceInfo* col;
}Matrice;

enum position
{
    ROW,
    COL
};

enum relativPos{
    UP,
    DOWN,
    RIGHT,
    LEFT
};





Matrice* createMatrice(int x , int y , int initVal);
void insertElement(enum position pos,int id, int value, Matrice* matrice);
void freeAll(Matrice* matrice);
void affMatrice(Matrice *matrice);
void fillAddCel(MatriceCell *cell, Matrice *matrice);
MatriceCell *getFirstElement(enum relativPos pos, Matrice *matrice, int x, int y);
/*void fillMatrice(Matrice* mat);


void delElement(int x ,int y, Matrice* matrice);
*/

#endif