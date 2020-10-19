#include <stdio.h>
#include <stdlib.h>
#include "listeTableau.h"

int main()
{
    /* déclaration du tableau contenant la liste */
    element maListe[TAILLEMAX];

    creerListeVide(maListe);

    afficherListe(maListe);
    insererElement(3, maListe);
    insererElement(4, maListe);
    insererElement(5, maListe);
    insererElement(6, maListe);
    insererElement(7, maListe);

    afficherListe(maListe);
    supprimerElement(1, maListe);
    afficherListe(maListe);
    supprimerElement(2, maListe);
    afficherListe(maListe);
    compacterListe(maListe);
    afficherListe(maListe);
    afficherListe(maListe);

    return 0;
}
