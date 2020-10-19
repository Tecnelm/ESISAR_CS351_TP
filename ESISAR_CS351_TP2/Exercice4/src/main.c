#include "graphlib.h"
#include "dessine.h"
int main(int argc, char const *argv[])
{
    gr_inits_w(500,500,"mosaique");
    dessineMosaiqueAvecSouris(50,5,5);
    return 0;
}
