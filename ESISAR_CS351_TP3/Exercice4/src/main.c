#include "matrice.h"


int main(int argc, char const *argv[])
{
    Matrice *matrice = createMatrice(3,3,2);
    Matrice *m = createMatrice(3,2,1);

    afficheMatrice(matrice);
    afficheMatrice(m);
    Matrice* result=produitMatrice(matrice,m);
    afficheMatrice(result);

    
    freeMatrice(result);
    freeMatrice(m);
    freeMatrice(matrice); 
    return 0;
}
