
#include <stdlib.h>
#include "matriceCreuse.h"

int main(int argc, char const *argv[])
{

    Matrice *matrice = createMatrice(3, 3, 1);
    Matrice *m2 = createMatrice(3,3,0);
    Matrice *result;
    insertElement(1,0,1,matrice);
    insertElement(1,1,2,matrice);
    insertElement(2,0,3,matrice);
    insertElement(2,2,4,matrice);
    insertElement(0,0,5,matrice);
    affMatrice(matrice);

    insertElement(0,2,1,m2);
    insertElement(1,0,2,m2);
    insertElement(2,0,3,m2);
    insertElement(2,2,4,m2);
    insertElement(0,0,5,m2);
    affMatrice(m2);

    result =addMatrice(matrice,m2);
    affMatrice(result);
    freeAll(result);

    result = produitMatrice(matrice,m2);
    affMatrice(result);
    freeAll(result);




    
   /* for (int i = 1; i < 4; i++)
    {
    }
    for (int i = 1; i < 4; i++)
    {
        insertElement(COL, 1, i, matrice);
    }
*/
    freeAll(matrice);
    freeAll(m2);

    return 0;
}
