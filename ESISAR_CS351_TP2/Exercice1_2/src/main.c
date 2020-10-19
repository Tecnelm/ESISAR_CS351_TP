#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    // fibonacciMain();
    PGCDMain();
    //factorielMain();
    //jeuMultiPoint();

    return 0;
}

void flushScanf()
{
    char c;

    while ((c = getchar()) != EOF && c != '\n')
        ;
}

int fibonacciMain()
{
    int res;
    int indice;
    do
    {
        printf("Donnez l'indice de fibonacci souhaité : \n");
        flushScanf();
        res = scanf("%d", &indice);
    } while (res != 1 && indice < 0);

    printf("Le resultat est : %d\n", fibonacci(indice));
    return 0;
}

/**
 * pour bien tester le code l'utilisateur doit tester les cas 0 et 1 voir si les valeurs sont correct ainsi que des valeurs dont le résultat est connu, 
 * vérifier avec une valeurs négative egalement 
 */
int fibonacci(int n)
{
    int i0 = 0;
    int i1 = 1;
    int current = 0;
    if (n == 1)
        current = 1;

    for (int i = 0; i < n - 1; i++)
    {
        current = i1 + i0;
        i0 = i1;
        i1 = current;
    }

    return current;
}
//Nous allons utiliser l'algorithme d'euclide
int PGCDMain()
{
    int res;
    int n1;
    int n2;
    do
    {
        printf(" Donnez les deux nombre à vérifier PGCD a la suite : \n");
        res = scanf("%d %d", &n1, &n2);
        flushScanf();
    } while (res != 2);

    printf("Le resultat est : %d\n", PGCD(n1, n2));
    return 0;
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
#ifdef MISEAUPOINT
            printf("valeur courante de b = %d\n", b);
#endif

        } while (reste != 0);
    }

    return result;
}

/**
 * Pour vérifier que mon code fonctionnait correctement nous avons réalisé divers test:
 *  Valeur négative, positive avec résultat connu erreur de format ...,
 * La réalisation de la première fonction a été util pour rapidement faire des tests aléatoire et vérifier le résultat grace au code de la fonction factoriel
 */
int factorielMain()
{
    int res;
    int indice;
    do
    {
        printf(" Donnez l'indice factoriel souhaité : \n");
        res = scanf("%d", &indice);
        flushScanf();
    } while (res != 1);

    printf("Le resultat est : %d\n", factoriel(indice));

    do
    {
        printf(" Donnez le nombre recherché : \n");
        res = scanf("%d", &indice);
        flushScanf();
    } while (res != 1);

    printf("Le resultat est : %d!\n", factorielBis(indice));

    return 0;
}

int factoriel(int indice)
{
    int result = 1;
    for (int i = 1; i <= indice; i++)
        result *= i;
    return result;
}

int factorielBis(int m)
{
    int result = 1;
    int indice = 1;

    while (result <= m)
    {
        indice++;
        result *= indice;
    }

    return indice - 1;
}

/**
 * pour les deux fonctions suivante les tests réalisé on été vérifier que l'intervalle de selection était correct que les le nombre erreur était correct
 * que les résultat donné était correct 
 */
int jeuMulti()
{
    int res;
    int nbTable;
    int resultat;
    do
    {
        printf(" Donnez la table de multiplaction souhaité entre 2 et 9: \n");
        res = scanf("%d", &nbTable);
        flushScanf();
    } while (res != 1 || nbTable > 9 || nbTable < 2);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = ", i, nbTable);

        res = scanf("%d", &resultat);
        printf("\n");
        if (res != 1)
        {
            printf("ERROR FORMAT\n ");
            exit(1);
        }
        if (resultat != i * nbTable)
        {
            printf("erreur la bonne réponse était : %d et non %d !!!!!!!!!!! \n", i * nbTable, resultat);
            return 0;
        }
    }
    printf("Félicitation tu n'as commis aucune erreur \n");
    return 0;
}

int jeuMultiPoint()
{
    int res;
    int nbTable;
    int resultat;
    int nberreur = 0;
    do
    {
        printf(" Donnez la table de multiplaction souhaité entre 2 et 9: \n");
        res = scanf("%d", &nbTable);
        flushScanf();
    } while (res != 1 || nbTable > 9 || nbTable < 2);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = ", i, nbTable);

        res = scanf("%d", &resultat);
        printf("\n");
        if (res != 1)
        {
            printf("ERROR FORMAT\n ");
            exit(1);
        }
        if (resultat != i * nbTable)
        {
            nberreur++;
        }
    }
    if (!nberreur)
        printf("Félicitation tu n'as commis aucune erreur \n");
    else
    {
        printf("Tu as fais %d erreur(s) retourne réviser\n", nberreur);
    }

    return 0;
}