#include "evaluation.h"
#include "pile.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>

int evaluationPI(const char *chaine)
{
    pileInt number = creerPile();
    int size = strlen(chaine);
    char c;
    int opa, opb;
    for (int i = 0; i < size; i++)
    {
        c = chaine[i];
        if (c >= '0' && c <= '9')
        {
            empiler(number, c - '0');
        }
        else
        {
            switch (c)/// on gère chaque cas en fonction de l'opérateur,
                        /// dans le  cas 'un opérateur on dépile les deux derier élément puis on effectue l'opération
                        /// une fois l'opération réalisé on empile le résultat
            {
            case '+':
                opb = depiler(number);
                opa = depiler(number);
                empiler(number, opa + opb);

                break;
            case '/':
                opb = depiler(number);
                opa = depiler(number);
                empiler(number, opa / opb);
                break;
            case '-':
                opb = depiler(number);
                opa = depiler(number);
                empiler(number, opa - opb);
                break;
            case 'x':
                opb = depiler(number);
                opa = depiler(number);
                empiler(number, opa * opb);
                break;
            case ' ': break; // gerer les cas si les opérateur et nombre on un espace entre eux 
            default:
                fprintf(stderr, "ERROR FORMAT EXPRESSION");
                exit(1);
            }
        }
    }
    return depiler(number); // on dépile le dernier élément qui est le résulat
}