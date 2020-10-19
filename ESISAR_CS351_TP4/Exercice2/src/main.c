#include "str.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
    char str[] = "-12345";
    //mettreEnMajuscule(str);
   // printf("%s \n",str);
    //mettreEnMinuscule(str);
  //  printf("%s \n",str);
    afficherEnDecimal(str);
    afficherEnHexa(str);
    //retournerMot(str);
    //printf("%s \n",str);

    printf("%d\n",comparerChaine("1234","1334"));

    char st[10];
    intVersChaine(-1235,st);
    printf("%s \n",st);

    return 0;
}
