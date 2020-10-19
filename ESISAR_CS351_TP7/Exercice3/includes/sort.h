#ifndef __SORT_H__
#define __SORT_H__

struct interv
{
    int valmin;
    int valmax;
};


struct interv createInter(int a, int b);
int inter1(int val, struct interv *inter);

void sort(int *T, int size, struct interv *interL, int nbInter);
void swap(int *a, int *b);



#endif