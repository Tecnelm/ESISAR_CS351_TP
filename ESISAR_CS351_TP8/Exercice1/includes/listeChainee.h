#ifndef __LISTECHAINNEE_H__
#define __LISTECHAINEE_H__

typedef struct elem
{
    int val;
    struct elem* next;
} Element;

void insertElement(int value,Element* list);
void delElement(int position,Element* list);
void affList(Element* list);
void freeAll(Element* list);



#endif