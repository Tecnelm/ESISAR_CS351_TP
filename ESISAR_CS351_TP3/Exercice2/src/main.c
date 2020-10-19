#include "polynome.h"
#include <stdio.h>
#include "assert.h"

float A [] = {
    1,
    3,
    5,
    6
};

int main(int argc, char const *argv[])
{
    float a = valeurPolynome(A , 4, 2);

    printf("%f \n",a );
    assert(valeurPolynome(A , 4, 1) == 15);
    assert(valeurPolynome(A,4,2) == 75);
    return 0;
}
