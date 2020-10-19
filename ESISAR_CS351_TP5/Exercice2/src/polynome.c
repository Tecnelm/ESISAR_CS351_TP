#include <stdio.h>
#include "polynome.h"

void addPolynome(Polynome p1, Polynome p2, Polynome res)
{
    int sizeP1 = polynomeSize(p1);
    int sizeP2 = polynomeSize(p2); //donne la taille du polynome( son nombre d'élément de terme non nul)
    int indexP1 = 0; // ces indices servent à savoir ou l'on est dans le polynome les degrés peuvent avancer de manière non syncrone 
    int indexP2 = 0;
    int indexPres = 0;
    while (indexP1 < sizeP1 && indexP2 < sizeP2) /// on execute tant que les deux polynomes sont en dessous de leur taille
    {
        if (p1[indexP1].degre == p2[indexP2].degre) // si les deux degré sont égaux on les additionnes et on incremente tous les compteurs (avance syncrone)
        {
            res[indexPres].degre = p1[indexP1].degre;
            res[indexPres++].coeff = p1[indexP1++].coeff + p2[indexP2++].coeff;
        }
        else if (p1[indexP1].degre > p2[indexP2].degre) // si le degré du polynome 1 est suppérieur au p3, alors on ajoute au résultat le terme et on incremente les deux compteurs
        {
            res[indexPres].degre = p1[indexP1].degre;
            res[indexPres++].coeff = p1[indexP1++].coeff;
        }
        else
        {
            res[indexPres].degre = p2[indexP2].degre; // on est dans le cas ou  c'est le degré de P2 est suppérieur 
            res[indexPres++].coeff = p2[indexP2++].coeff;
        }
    };
    /// dans le cas ou  l'un des deux polynome n'a pas été encore copier dans le résultat on termine de le copier 
    if (indexP1 < sizeP1)
    {
        while (indexP1 < sizeP1)
        {
            res[indexPres].degre = p1[indexP1].degre;
            res[indexPres++].coeff = p1[indexP1++].coeff;
        }
    }
    else if (indexP2 < sizeP2)
    {
        while (indexP2 < sizeP2)
        {
            res[indexPres].degre = p2[indexP2].degre;
            res[indexPres++].coeff = p2[indexP2++].coeff;
        }
    }
    res[indexPres].coeff= 0;
    res[indexPres].degre = -1;
}
// cette fonction permet de savoir le nombre de terme dans le polynome 
int polynomeSize(Polynome p)
{
    int index = 0;
    while (p[index].degre >= 0)
    {
        index++;
    }

    return index;
}
/// afficher un polynome 
void affPolynome(Polynome p)
{
    int size = polynomeSize(p);

    for (int i = 0; i < size; i++)
    {
        printf("%fx^%d + ", p[i].coeff, p[i].degre);
    }
    printf("0\n");
}
/// permet de crée un terme 
Terme createTerme(float coeff, int degree)
{
    Terme terme = {coeff, degree};
    return terme;
}