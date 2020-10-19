#include "stdio.h"
#include "gestionNote.h"


double  note[] = {
    12.0,
    13.5,
    8.5,
    14.7,
    6, 0};

 int size = 5;
int main(int argc, char const *argv[])
{
    printf("Les notes sont : \n");
    afficherNotes(note, size);

    printf("note min :\t%f\n", minimumNote(note, size));
    printf("note max :\t%f\n", maximumNote(note, size));
    printf("note moyenne :\t%f\n", calculeMoyenne(note, size));
    printf("note variance :\t%f\n", calculeVariance(note, size));
    printf("note Ecart Type:\t%f\n", calculeEcartType(note, size));
    printf("rang 13,5:\t%d\n", rechercherValeur(note, size,13.5));
    printf("rang 10,5 :\t%d\n", rechercherValeur(note, size,10.5));

    afficherHistogrammeHO(note ,size);

    return 0;
}
