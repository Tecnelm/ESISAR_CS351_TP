#include <stdio.h>
#include <stdlib.h>
#include "evaluation.h"
#include "pile.h"

int main()
{
char* exp = "4 2 + 5 x 6 7 -/";

printf("Le résultat de \"4 2 + 5 x 6 7 -/\" est : %d \n",evaluationPI(exp));
    return 0;
}