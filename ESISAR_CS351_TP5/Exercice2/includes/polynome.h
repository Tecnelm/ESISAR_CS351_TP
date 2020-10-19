#ifndef __POLYNOME_H__
#define __POLYNOME_H__
#define NBMAX 100
typedef struct
{
    float coeff; /* coefficient du terme*/
    int degre;   /* degré du terme*/
} Terme;
typedef Terme Polynome[NBMAX];

/// cette fonction permet d'ajouter deux polynomes entre eux
void addPolynome(Polynome p1, Polynome p2, Polynome res);
/// permet de savoir le nombre de terme dans un polynome
int polynomeSize(Polynome p);
/// permet d'afficher un polynome
void affPolynome(Polynome p);

///permet de crée un terme
Terme createTerme(float coeff, int degree);
#endif