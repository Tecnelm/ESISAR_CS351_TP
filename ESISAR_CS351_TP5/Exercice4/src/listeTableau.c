/*********************************************************************/
/* Realisation d'une Liste chainee dans un tableau                   */
/* ioannis.parissis@grenoble-inp.fr                                  */
/* Sep 2012                                                          */
/*********************************************************************/
#include "listeTableau.h"

int elementLibre(Liste l)
{
    int index = 0;

    while (l[index].suivant != -1 && index < TAILLEMAX)
    {
        index++;
    }

    return index;
}

void creerListeVide(Liste l)
{
    l[0].suivant = 0;
    l[0].valeur = 0;
    for (int i = 1; i < TAILLEMAX; i++)
    {
        l[i].suivant = -1;
    }
}
void insererElement(int x, Liste l)
{
    int index = 0;
    do
    {
        index = l[index].suivant;
    } while (l[index].suivant != 0); /// récupère l'index du dernier élément

    l[index].suivant = elementLibre(l); ///lie la nouvelle case a l'ancienne
    index = l[index].suivant;
    l[index].suivant = 0;
    l[index].valeur = x;
}

void supprimerElement(int x, Liste l)
{
    if (x >= 0) // on ne peut pas enlever un indice négatif
    {
        x++;
        int index = 0;
        int previndex; // on garde en mémoire les la precédente case mémoire pour pouvoir racorder les cases mémoires
        for (int i = 0; i < x && index != -1; i++)
        {
            previndex = index;
            index = l[index].suivant; /// la case mémoire correspondant a la x eme valeur, dans le cas ou elle existe pas on ne fait rien
            if (index == 0)
            {
                index = -1;
            }
        }
        if (index >= 0) // si l'indice existe alors on fait le racordement des indices et on libère la case mémoire
        {
            l[previndex].suivant = l[index].suivant;
            l[index].suivant = -1;
        }
    }
}

void afficherListe(Liste l)
{
    int index = 0;
    do
    {
        index = l[index].suivant;
        if (index != 0)
            printf("%d ", l[index].valeur);
    } while (l[index].suivant != 0); // on affiche toutes les case mémoire a la suite
    printf("\n");
}

void compacterListe(Liste l)
{
    int index = 0;
    int freeplace = 0;
    int precIndex = 0;
    while (l[index].suivant != 0) //tant qu'il y a des élément dans la liste on va changer la case mémoire pour rapprocher la valeur
    {
        precIndex = index;
        index = l[index].suivant;
        freeplace = elementLibre(l); // prend la case libre à gauche  la plus proche
        if (index > freeplace)       /// remplacement des cases pour raprocher l'élément
        {
            l[freeplace].suivant = l[index].suivant;
            l[freeplace].valeur = l[index].valeur;
            l[index].suivant = -1; ///libere la case
            l[precIndex].suivant = freeplace;
            index = freeplace;
        }
    }
}