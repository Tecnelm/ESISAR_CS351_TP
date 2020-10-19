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
    int x;
    int y;
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





Matrice* createMatrice(int x , int y , int initVal);
void insertElement(enum position pos,int id, int value, Matrice* matrice);
void freeAll(Matrice* matrice);

/*void fillMatrice(Matrice* mat);


void delElement(int x ,int y, Matrice* matrice);
void affList(Matrice * matrice);
*/

#endif