#include "math.h"
#include <assert.h>

int quotientTest()
{
    assert(quotient(20, 10) == 2);
    assert(quotient(1, 0) == -1);
    assert(quotient(254, 7) == 36);
    assert(quotient(4, 2) == 2);
    assert(quotient(2, 4) == 0);
    assert(quotient(0, 10) == 0);
    return 1;
}

int quotient(int a, int b)
{
    int q = 0;

    if (!(b == 0 || a < 0 || b < 0))
    {
        while (a - b >= 0)
        {
            q++;
            a -= b; // on soustrait la valer de b  à a tant que a n'est pas négatif si l'on soustrait b, on garde en mémoire le nombre de fois ou l'action a été réalisé
        }
    }
    else
    {
        q = -1;
    }

    return q;
}

int resteTest()
{
    assert(reste(19, 15) == 4);
    assert(reste(5, 5) == 0);
    assert(reste(10, 0) == -1);
    assert(reste(0, 10) == 0);

    assert(reste(5, 6) == 5);

    return 1;
}

int reste(int a, int b)
{

    if (!(b == 0 || a < 0 || b < 0))
    {
        while (a - b >= 0)
        {
            a -= b; /// même principe que pour le quotient mais on donne la valeur de restante final de a 
        }
    }
    else
    {
        a = -1;
    }

    return a;
}

int valeurAbsolue(int a)
{
    return a < 0 ? -a : a; 
}

int valeurAbsolueTest()
{
    assert(valeurAbsolue(-10) == 10);
    assert(valeurAbsolue(10) == 10);
    return 1;
}

int ppcm(int a, int b)
{

    return quotient(valeurAbsolue(a * b), pgcd(a, b));
}
int pgcd(int n1, int n2)
{
    int result = 0;/// Utilisation de l'algorithme d'euclide
    int reste = 0;
    int a, b;
    a = n1;
    b = n2;

    if (n1 == 0)
    {
        result = n2;
    }
    else if (n2 == 0)
    {
        result = n1;
    }
    else
    {
        do
        {
            reste = a % b;
            if (reste)
            {
                a = b;
                b = reste;
            }
            else
            {
                result = b;
            }

        } while (reste != 0);
    }

    return result;
}
int ppcmTest()
{
    assert(ppcm(2, 3) == 6);
    assert(ppcm(4, 3) == 12);
    assert(ppcm(4, 6) == 12);
    return 1;
}

int puissanceMB(int x, int pow)
{
    int N = pow, Y = 1, Z = x; // calcul de la puissance en utilisant les nombres binaires 

    while (N != 0)
    {
        if (N % 2 != 0)
        {
            Y *= Z;
        }
        N = N / 2;
        Z *= Z;
    }

    return Y;
}

int puissanceTestMB()
{
    assert(puissanceMB(10, 0) == 1);
    assert(puissanceMB(2, 4) == 16);
    return 1;
}

int puissance(int x, int pow)
{
    int result = 1;
    for (int i = 0; i < pow; i++) /// réalisation de la puissance en multipliant n fois le nombre x
    {
        result *= x;
    }
    return result;

    /**
     * La complexité de la focntion est en n en effet dans le cas ou l'on augmente de n la puissance on devra réaliser n opération supplémentaire
     */
}

int puissanceTest()
{
    assert(puissance(10, 0) == 1);
    assert(puissance(2, 4) == 16);
    return 1;
}

int sommeDesImpaires(int d, int f)
{
    int result = 0;
    int indice = 0;
    if (f < d)
    {
        result = -1;
    }
    else
    {
        while ((d + indice) <= f)
        {
            result += d + indice;
            indice += 2;
        }
    }
    return result;
}

int sommeDesImpairesTest()
{
    assert(sommeDesImpaires(13, 19) == 64);
    assert(sommeDesImpaires(31, 33) == 64);
    assert(sommeDesImpaires(1, 15) == 64);

    return 1;
}

int estUneDecompositionDe(int d, int f)
{
    int result = -1;
    int cube = 1;
    int indice = 0;

    result = sommeDesImpaires(d, f);

    while (cube < result){
        indice++;
        cube = puissanceMB(indice, 3);
        
        }

    result = cube == result ? indice : -1;

    return result;

    return result = -1;
}

int estUneDecompositionDeTest()
{
    assert(estUneDecompositionDe(7, 13) == -1);
    assert(estUneDecompositionDe(7, 11) == 3);
    return 1;
}

int testBibliotheque()
{
    if (quotientTest())
    {
        printf("ALL TEST QUOTIENT PASSED\n");
    }

    if (resteTest())
    {
        printf("ALL TEST RESTE PASSED\n");
    }

    if (valeurAbsolueTest())
    {
        printf("ALL TEST ABS PASSED\n");
    }
    if (ppcmTest())
    {
        printf("ALL TEST PPCM PASSED\n");
    }

    if (puissanceTest())
    {
        printf("ALL TEST POWER PASSED\n");
    }
    if (puissanceTestMB())
    {
        printf("ALL TEST POWER BINARY PASSED\n");
    }

    if (sommeDesImpairesTest())
    {
        printf("ALL TEST SOMME IMPAIREPASSED\n");
    }

    if(estUneDecompositionDeTest())
    {
        printf("ALL TEST COMPOSITION PASSED");
    }

    return 1;
}