#include "folder.h"
#include "stdlib.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    const char *nameData;
    const char *nameResult;
#ifdef TEST
    nameData = "/home/clement/Workspace/VsCodeProject/ESISAR_CS/3A/CS351/ESISAR_CS351_TP4/Exercice1/data/donnee.txt";
    nameResult = "/home/clement/Workspace/VsCodeProject/ESISAR_CS/3A/CS351/ESISAR_CS351_TP4/Exercice1/data/resultat.txt";
#else
    if (argc == 3)
    {
        nameData = argv[1];
        nameResult = argv[2];
    }
    else
    {
        fprintf(stderr, "ERROR ARGUMENTS MISSING\n");
        exit(0);
    }

#endif

    int T[1000];
    int nbValue;

    nbValue = lireDonnee(nameData, T);

    afficherTableau(T, nbValue);
    

    triABulle(T, nbValue);

    afficherTableau(T, nbValue);

    enregistrerDonnees(nameResult, T, nbValue);

    return 0;
}
