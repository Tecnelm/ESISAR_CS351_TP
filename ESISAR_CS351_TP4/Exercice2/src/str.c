#include "str.h"
#include <stdio.h>
#include <stdlib.h>

int myStrlen(const char *str)
{
    int nbchar = 0;

    while (str[nbchar] != '\0')
        nbchar++;

    return nbchar;
}

char *myStrcpy(char *dest, const char *src)
{
    int pos = 0;
    if (dest != NULL && src != NULL)
    {
        while (src[pos] != '\0')
        {
            dest[pos] = src[pos];
            pos++;
        }
        dest[pos] = '\0';
    }
    return dest;
}

void afficherEnHexa(const char *str)
{
    int len = myStrlen(str);
    for (int i = 0; i < len; i++)
    {
        printf("%x ", str[i]);
    }
    printf("\n");
}

void afficherEnDecimal(const char *str)
{
    int len = myStrlen(str);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", str[i]);
    }
    printf("\n");
}

void mettreEnMajuscule(char *str)
{
    int len = myStrlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void mettreEnMinuscule(char *str)
{
    int len = myStrlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 'a' - 'A';
        }
    }
}

void transformerMinMaj(char *str)
{
    int len = myStrlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 'a' - 'A';
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void retournerMot(char *str)
{
    int len = myStrlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int rechercherCaractereG(const char *str, char c)
{
    int len = myStrlen(str);
    int index = 0;

    while (str[index] != c && index < len)
    {

        index++;
    }

    if (index == len)
    {
        index = 0;
    }
    return index;
}

int rechercherCaractereD(const char *str, char c)
{
    int len = myStrlen(str);
    int index = len - 1;

    while (str[index] != c && index >= 0)
    {

        index--;
    }

    if (index == len)
    {
        index = 0;
    }
    return index;
}

int estPalindrome(const char *str, int d, int f)
{
    int len = myStrlen(str);
    len = f > len ? len : f;
    int result = 1;

    for (int i = d; i < len && result; i++)
    {
        if (str[len - 1 - i] != str[i])
        {
            result = 0;
        }
    }

    return result;
}

int comparerChaine(const char *str, const char *str1)
{
    int result = 0;
    int len1 = myStrlen(str);
    int len2 = myStrlen(str1);
    int index = 0;

    if (len1 == len2)
    {
        while (str[index] == str1[index] && index < len1)
        {
            index++;
        }
        if (str[index] != str1[index])
        {
            result = str[index] > str1[index] ? 1 : -1;
        }
    }
    else
    {
        result = len1 > len2 ? 1 : -1;
    }
    return result;
}

int valeurDecimale(const char *str)
{
    int len = myStrlen(str);
    int result = 0;
    int neg = 1;
    for (int i = 0; i < len; i++)
    {
        if (i == 0 && str[i] == '-')
        {
            neg = -1;
        }
        else
        {
            if (str[i] >= '0' && str[i] <= '9')
                result = result * 10 + str[i] - '0';
            else
            {
                fprintf(stderr, "ERROR FORMAT NAME\n");
                exit(1);
            }
        }
    }
    return result * neg;
}

void intVersChaine(int nb, char *chaine)
{
    int index = 0;
    int n = nb < 0 ? -nb : nb;
    int neg = nb < 0 ? 1 : 0;
    while (n != 0)
    {
        chaine[index++] = n % 10 + '0';
        n /= 10;
    }
    if (neg)
        chaine[index++] = '-';

    chaine[index++] = '\0';

    retournerMot(chaine);
}