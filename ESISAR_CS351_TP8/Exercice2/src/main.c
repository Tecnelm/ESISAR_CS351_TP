
#include <stdlib.h>
#include "matriceCreuse.h"

int main(int argc, char const *argv[])
{
    /* Element* elem = malloc(sizeof(Element)/sizeof(char));
    elem->next = NULL;
    elem->val = 0;
    affList(elem);

    for(int i = 0 ; i< 10 ; i++)
    {
        insertElement(i,elem);
        affList(elem);
    }

    for(int i = 0 ; i< 5 ; i++)
    {
        delElement(i,elem);
        affList(elem);
    }

    freeAll(elem);
*/

    Matrice *matrice = createMatrice(3, 3, 1);
    affMatrice(matrice);
    insertElement(COL, 0, 3, matrice);
    affMatrice(matrice);
    
   /* for (int i = 1; i < 4; i++)
    {
    }
    for (int i = 1; i < 4; i++)
    {
        insertElement(COL, 1, i, matrice);
    }
*/
    freeAll(matrice);

    return 0;
}
