#ifndef __MATRICE_H__
#define __MATRICE_H__

typedef struct matrice Matrice;

Matrice *createMatrice(int sx,int sy,int iniVal);

void freeMatrice(Matrice* matrice);

void afficheMatrice(Matrice* matrice);

Matrice *additionnerMatrices(Matrice *m1 , Matrice* m2);

Matrice* transposeeMatrice(Matrice* m);

Matrice* produitMatrice(Matrice* m1, Matrice* m2);



#endif