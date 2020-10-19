
#include <stdio.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    int res;
    int year;
    do
    {
        printf("Rentrée l'année que vous souhaitez vérifier\n");
        res = scanf("%d", &year);
        flushScanf(); // on vide le buffer du scanf 
    } while (res == 0);

    if (checkBissextile(year))
    {
        printf("l'année %d est bissextile :D\n ", year);
    }
    else
        printf("L'année %d n'est pas bissextile :(\n", year);

    return 0;
}

void flushScanf()
{
    char c;

    while ((c = getchar()) != EOF && c != '\n')
        ;
}

char checkBissextile(int year)
{
    char result = 0;
    if (year % 100 == 0 && year % 400 == 0)
    {
        result = 1;
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        result = 1;
    }

    return result;
}
