#include <stdio.h>

#include "main.h"

int main(int argc, char const *argv[])
{
    char note;
    int res;

    do
    {
        printf("Rentrez la note de l'étudiant entre A et E \n");
        res = scanf("%c", &note);
        flushScanf();
    } while (note < 'A' || note > 'E' || res != 1);
    // dans le cas ou la note n'est pas compris dans l'intervalle ceci nous évite de devoir gerer le cas plus tard
    // la variable res sers a gerer le cas d'erreur de lecture de scanf
    V1(note);
    V2(note);
    V3(note);

    /**
     * Nous utilisons un tableau de chaine de caractère stockant les valeurs des note dans l'ordre décroissant, ainsi qu'une enum qui contient toute les
     * note de manière ordonnée pour que le code soit plus lisible lors de la lecture dans le tableau
     * 
     * Nous aurions pu réaliser une Version4, en enlevant la valeur 'A' à la note rentré nous aurions eu directement la case de l'appréciation
     * ainsi nous n'aurions pas eu besoin de if ou switch
     */

    return 0;
}
void flushScanf()
{
    char c;

    while ((c = getchar()) != EOF && c != '\n')
        ;
}
//nous allons utiliser des if imbriqué nous avons un avantage en performance car des qu'un if est validé nous ne vérifions pas les suivants
void V1(char note)
{
    if (note == 'A')
    {
        printf("%s\n", appreciation[A]);
    }
    else if (note == 'B')
    {
        printf("%s\n", appreciation[B]);
    }
    else if (note == 'C')
    {
        printf("%s\n", appreciation[C]);
    }
    else if (note == 'D')
    {
        printf("%s\n", appreciation[D]);
    }
    else if (note == 'E')
    {
        printf("%s\n", appreciation[E]);
    }
    else
    {
        printf("Note incorrect\n");
    }
}
// même principe que précédement mais tous les if sont vérifié, fonctionne car la note ne peux pas être égale à deux différente
void V2(char note)
{

    if (note == 'A')
    {
        printf("%s\n", appreciation[A]);
    }
    if (note == 'B')
    {
        printf("%s\n", appreciation[B]);
    }
    if (note == 'C')
    {
        printf("%s\n", appreciation[C]);
    }
    if (note == 'D')
    {
        printf("%s\n", appreciation[D]);
    }
    if (note == 'E')
    {
        printf("%s\n", appreciation[E]);
    }
}

//le switch fonctione globalement de la même manière que la V1, une légère optimisation à été réalisé, il n'y a plus qu'un printf dans le code à la fin.
void V3(char note)
{
    char *ttp;
    switch (note)
    {
    case 'A':
        ttp = appreciation[A];
        break;
    case 'B':
        ttp = appreciation[B];
        break;
    case 'C':
        ttp = appreciation[C];
        break;
    case 'D':
        ttp = appreciation[D];
        break;
    case 'E':
        ttp = appreciation[E];
        break;

    default:
        break;
    }
    printf("%s\n", ttp);
}