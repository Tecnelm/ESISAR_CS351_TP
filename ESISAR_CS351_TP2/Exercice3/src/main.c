#include <stdio.h>
#include <assert.h>
#include "math.h"

int main(int argc, char const *argv[])
{

    if (quotientTest())
    {
        printf("ALL TEST PASSED\n");
    }

    if (resteTest())
    {
        printf("ALL TEST PASSED\n");
    }

    if (valeurAbsolueTest())
    {
        printf("ALL TEST PASSED\n");
    }
    if (ppcmTest())
    {
        printf("ALL TEST PASSED\n");
    }

    if (puissanceTest())
    {
        printf("ALL TEST PASSED\n");
    }
    if (puissanceTestMB())
    {
        printf("ALL TEST PASSED\n");
    }

    if (sommeDesImpairesTest())
    {
        printf("ALL TEST PASSED\n");
    }

    if(estUneDecompositionDeTest())
    {
        printf("ALL TEST PASSED");
    }

    return 0;
}
