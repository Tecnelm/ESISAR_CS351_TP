#include "dessine.h"
#include "graphlib.h"

int dessineCarre(int x, int y, int taille)
{
    // on trace les 4 lignes du carre  
    line(x, y, x + taille / 2, y - taille / 2);
    line(x + taille / 2, y - taille / 2, x, y - taille);
    line(x, y, x - taille / 2, y - taille / 2);
    line(x - taille / 2, y - taille / 2, x, y - taille);
    return 0;
}

int dessineCarreDiagonale(int x, int y, int taille)
{
    // on trace un carre puis les diagonal 
    dessineCarre(x, y, taille);
    
    line(x, y, x, y - taille);
    line(x - taille / 2, y - taille / 2, x + taille / 2, y - taille / 2);
    return 0;
}

int dessineMosaique(int x, int y, int taille, int largeur, int hauteur)
{
    // on trace un carré decalé celon le nombre de carré en largeur et en hauteur 
    for(int xl = 0 ; xl < largeur ; xl++)
    {
        for(int yl = 0 ;yl <hauteur ; yl++ )
        {
            dessineCarre(taille/2+(xl * taille)+ x,-yl*taille +y,taille);
        }
    }
    return 0;
}

int dessineMosaiqueAvecSouris(int taille, int largeur ,int hauteur)
{
    int x , y;
    cliquer_xy(&x , &y); // attente du clique de souris pour avoir les coordonnée x et y;
    dessineMosaique(x , y ,taille, largeur,hauteur);
    cliquer(); // on attend un nouveau clique pour suprimer la fenetre
    clear_screen();
    gr_close();// libération de la mémoire prise par la fenetre 
    return 0 ;

}