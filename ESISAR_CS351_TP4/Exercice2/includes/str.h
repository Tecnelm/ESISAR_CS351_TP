#ifndef __STR_H__
#define __STR_H__

int myStrlen(const char *str);
char *myStrcpy(char *dest, const char *src);

void afficherEnHexa(const char *str);
void afficherEnDecimal(const char *str);
void mettreEnMajuscule(char *str);
void mettreEnMinuscule(char *str);
void transformerMinMaj(char *str);
void retournerMot(char *str);
int rechercherCaractereG(const char *str, char c);
int rechercherCaractereD(const char *str, char c);

int estPalindrome(const char *str, int d, int f);
int comparerChaine(const char *str, const char *str1);

int valeurDecimale(const char *str);
void intVersChaine(int nb, char *chaine);

#endif
