#include <stdio.h>


int main()
{
    int i = 2, j = 3, k = 4;
    printf("%d %d %d \n",i & j, i | 1, k | j);
    if ((i & k) || (i & j))
        printf("ok\n");
    return (0);

    /**
     * le code agit directement sur  les bit et fait les opérations avec 
     */
    
}