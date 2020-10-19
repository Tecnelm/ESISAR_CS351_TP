
#include <stdlib.h>
#include "listeChainee.h"

int main(int argc, char const *argv[])
{
    Element* elem = malloc(sizeof(Element)/sizeof(char));
    elem->next = NULL;
    elem->val = 0;
    affList(elem);

    for(int i = 0 ; i< 10 ; i++)
    {
        insertElement(i,elem);
        affList(elem);
    }

    for(int i = 0 ; i< 5 ; i++)
    {
        delElement(i,elem);
        affList(elem);
    }

    freeAll(elem);

    return 0;
}
