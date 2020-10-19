#include <math.h>
#include <stdio.h>
#include "gestionNote.h"

void afficherNotes(double *table, int size)
{
    printf("Les notes sont : \n");
    for (int i = 0; i < size; i++)
    {
        printf("\t %f \n", table[i]);
    }
}

double minimumNote(double *table, int size)
{
    double min = 20;

    for (int i = 0; i < size; i++)
    {
        if (table[i] < min)
        {
            min = table[i];
        }
    }
    return min;
}
double maximumNote(double *table, int size)
{
    double max = 0;

    for (int i = 0; i < size; i++)
    {
        if (table[i] > max)
        {
            max = table[i];
        }
    }
    return max;
}
double calculeMoyenne(double *table, int size)
{
    double sum;
    for (int i = 0; i < size; i++)
    {
        sum += table[i];
    }
    sum /= size;
    return sum;
}
double calculeVariance(double *table, int size)
{
    double variance = 0;
    double moy = calculeMoyenne(table, size);

    for (int i = 0; i < size; i++)
    {
        variance += ((table[i] - moy) * (table[i] - moy));
    }
    return variance / size;
}
double calculeEcartType(double *table, int size)
{
    double variance = calculeVariance(table, size);

    return sqrt(variance);
}

int rechercherValeur(double *table, int size, double value)
{
    int result = -1;

    for (int i = 0; i < size; i++)
    {
        if (value == table[i])
            result = i;
    }
    return result;
}

void afficherHistogrammeHO(double *table, int size)
{
    for(int n = 2 ; n <20 ; n ++ )
    {
        if(n == 2)
            printf("[ %d; %d ]\t: ",n-2 , n);
        else
            printf("] %d; %d ]\t: ",n-2 , n);
        
        for(int i = 0 ; i <size ; i++ )
        {
            if (table[i] <= n  && table [i] >n-2)
                printf("\t *");
        }
        printf("\n");
    }
}