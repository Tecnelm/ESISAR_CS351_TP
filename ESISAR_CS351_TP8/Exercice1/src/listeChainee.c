#include <stdio.h>
#include <stdlib.h>
#include "listeChainee.h"



void insertElement(int value,Element* list)
{
    Element* currentAdd = list;
    Element* newElem;
    while (currentAdd ->next != NULL)
    {
        currentAdd= currentAdd->next;
    }
    newElem=malloc(sizeof(Element)/sizeof(char));
    newElem->next = NULL;
    newElem->val = value;
    currentAdd->next = newElem;
    
}
void delElement(int position,Element* list)
{
    int index =0;
    Element *prevadd = list;
    Element *nextID=prevadd->next;
    while (nextID->next != NULL && index <position)
    {
        index++;
        prevadd = nextID;
        nextID = nextID->next;
    }

    if(index == position)
    {
        prevadd->next = nextID->next;
        free(nextID);
    }

}
void affList(Element* list)
{
    Element* elem = list;
    while(elem->next !=NULL)
    {
        elem = elem->next;
        printf("%d ",elem->val);
    }
    printf("\n");
}

void freeAll(Element* list)
{
    Element* nextElem = list;
    Element* current = list;
    while (current!= NULL)
    {
        nextElem = current->next;
        free(current);
        current = nextElem;
    }
}