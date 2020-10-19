#include "sort.h"


int inter1(int val, struct interv *inter)
{
    return val >= inter->valmin && val < inter->valmax;
}

struct interv createInter(int a, int b)
{
    struct interv c = {a, b};
    return c;
}


void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int *T, int size, struct interv *interL, int nbInter)
{
    int index = 0;
    for (int a = 0; a < nbInter; a++)
    {
        for (int i = 0; i < size; i++)
        {
            if (inter1(T[i],interL+a))
            {
                swap(T + i, T + index);
                index++;
            }
        }
    }
}
