
#include <stdio.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    int res;
    int number;
    do
    {
        printf("Rentrée le nombre les N combien d'entier voulez vous compter \n");
        res = scanf("%d", &number);
        flushScanf();
    } while (res == 0);

    printf("La somme fait %d \n", sumCalc1(number));
    printf("La somme fait %d \n", sumCalc2(number));

    return 0;
}

void flushScanf()
{
    char c;

    while ((c = getchar()) != EOF && c != '\n')
        ;
}

/**
 * dans le cas d'un indice négatif la somme fait 0;
 */

int sumCalc1(int number)
{
    int a = 0;
    int result = 0;
    do
    {
        result += a;
    } while (a++ < number);

    return result;
}
int sumCalc2(int number)
{
    int a = 0;
    int result = 0;

    while (a++ < number)
        result += a;

    return result;
}
