#include "polynome.h"

int main(int argc, char const *argv[])
{
    Polynome p = {createTerme(1, 4), createTerme(5, 3), createTerme(8, 1), createTerme(8, 0), createTerme(1, -1)};
    Polynome p2 = {createTerme(1, 5), createTerme(5, 3), createTerme(8, 1), createTerme(5, -1)};
    Polynome p3;

    affPolynome(p);
    affPolynome(p2);

    addPolynome(p, p2, p3);

    affPolynome(p3);

    return 0;
}
