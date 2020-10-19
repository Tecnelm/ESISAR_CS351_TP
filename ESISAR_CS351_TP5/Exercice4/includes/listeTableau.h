/*********************************************************************/
/* Realisation d'une Liste chainee dans un tableau                   */
/* ioannis.parissis@grenoble-inp.fr                                  */
/* Sep 2012                                                          */
/*********************************************************************/

#ifndef __ListeTABLEAU_H__
#define __ListeTABLEAU_H__

#include <stdio.h>

#define TAILLEMAX 100

typedef struct {
	int valeur ;
	int suivant ;
} element ;

/* le type Liste permet de ne pas utiliser de pointeurs */
typedef element* Liste;




/* Retourne un element libre du tableau
   (suivant = -1). On suppose qu'il y en a toujours un */
int elementLibre(Liste l);

/* Initialise le tableau de sorte que tous les éléments soient libres (suivant = -1)
   sauf celui d'indice 0 où suivant == 0*/
void creerListeVide(Liste l);

/* Affiche les elements de la Liste dans l'ordre */
void afficherListe(Liste l);

/* Ajoute x dans la Liste triee l */
void insererElement(int x, Liste l);

/* Supprime le i-ème élément de l, i = 1,2... */
void supprimerElement(int i, Liste l);

void compacterListe(Liste l);


#endif
