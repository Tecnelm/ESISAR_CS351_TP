#ifndef __FRACTION_H__
#define __FRACTION_H__

typedef struct {
int num;
int den;
} Fraction;

Fraction addFraction(Fraction* frac1 , Fraction *frac2);
Fraction subbFraction(Fraction* frac1 , Fraction *frac2);
Fraction mulFraction(Fraction* frac1 , Fraction *frac2);
Fraction divFraction(Fraction* frac1 , Fraction *frac2);
void afficherFraction(Fraction *frac);
int PGCD(int n1, int n2);

#endif