#include "polynome.h"

float valeurPolynome(float A[], int N, float x0)
{
    float evaluation = 0;
    
    for(int i = N-1 ; i >=0 ; i --)
    {
        evaluation*= x0;
        evaluation += A[i];

    }

    return evaluation;
}
