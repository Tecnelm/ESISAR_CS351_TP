#include <stdio.h>
#include "fraction.h"

int main(int argc, char const *argv[])
{
    Fraction f1, f2, f3;
    printf("Entrer deux fractions:");
    scanf("%d/%d %d/%d", &f1.num, &f1.den, &f2.num, &f2.den);

    afficherFraction(&f1);
    afficherFraction(&f2);
    printf("ADDITION:\n");
    f3 = addFraction(&f1, &f2);
    afficherFraction(&f3);
    printf("SUBBSTRACTION:\n");
    f3 = subbFraction(&f1, &f2);
    afficherFraction(&f3);
    printf("MULTIPLICATION:\n");
    f3 = mulFraction(&f1, &f2);
    afficherFraction(&f3);
    printf("DIVISION:\n");
    f3 = divFraction(&f1, &f2);
    afficherFraction(&f3);
    return 0;
}
