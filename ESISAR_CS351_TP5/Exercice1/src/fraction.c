#include <stdio.h>
#include "fraction.h"

Fraction addFraction(Fraction *frac1, Fraction *frac2)
{
    Fraction frac;
    int temp_den = frac1->den * frac2->den;
    int pgcd;
    if (frac1->den != 0 && frac2->den != 0)
    {
        frac.num = frac1->num * frac2->den + frac2->num * frac1->den;
        pgcd = PGCD(frac.num, temp_den);
        frac.num = frac.num / pgcd;
        frac.den = temp_den / pgcd;
    }
    else
    {
        frac.num = 0;
        frac.den = 0;
        fprintf(stderr, "ERROR FRACTION INVALID \n");
    }

    return frac;
}
Fraction subbFraction(Fraction *frac1, Fraction *frac2)
{
    Fraction frac;
    int temp_den = frac1->den * frac2->den;
    int pgcd;
    if (frac1->den != 0 && frac2->den != 0)
    {
        frac.num = frac1->num * frac2->den - frac2->num * frac1->den;
        pgcd = PGCD(frac.num, temp_den);
        frac.num = frac.num / pgcd;
        frac.den = temp_den / pgcd;
    }
    else
    {
        frac.num = 0;
        frac.den = 0;
        fprintf(stderr, "ERROR FRACTION INVALID \n");
    }
    return frac;
}
Fraction mulFraction(Fraction *frac1, Fraction *frac2)
{
    Fraction frac;
    if (frac1->den != 0 && frac2->den != 0)
    {

        frac.num = frac1->num * frac2->num;
        frac.den = frac1->den * frac2->den;
    }
    else
    {
        frac.num = 0;
        frac.den = 0;
        fprintf(stderr, "ERROR FRACTION INVALID \n");
    }

    return frac;
}

Fraction divFraction(Fraction *frac1, Fraction *frac2)
{
    Fraction frac;
    if (frac1->den != 0 && frac2->den != 0 && frac2->den !=0)
    {
        frac.num = frac1->num * frac2->den;
        frac.den = frac1->den * frac2->num;
    }
    else
    {
        frac.num = 0;
        frac.den = 0;
        fprintf(stderr, "ERROR FRACTION INVALID \n");
    }

    return frac;
}

void afficherFraction(Fraction *frac)
{
    printf("%d/%d\n", frac->num, frac->den);
}

int PGCD(int n1, int n2)
{
    int result = 0;
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