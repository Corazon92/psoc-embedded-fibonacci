/* Projet académique PSoC 5LP - programmation C embarquée */
#include "fonction.h"

uint8 envoi_donnees = 0;

void fibonacci_iteratif(uint8 n, uint16 tableau[])
{
    uint8 i;
    static uint8 compteur;

    tableau[0] = 0;
    tableau[1] = 1;

    for (i = 2; i < n; i++)
        tableau[i] = tableau[i-1] + tableau[i-2];

    compteur = compteur + 1;

    if (compteur == 100)
    {
        envoi_donnees = 1;
        compteur = 0;
    }
}

uint32 calcul_fibonacci_recursif(uint8 n)
{
    if (n <= 1)
        return n;

    return calcul_fibonacci_recursif(n-1)
         + calcul_fibonacci_recursif(n-2);
}

void fibonacci_recursif(uint8 n, uint16 tableau[])
{
    uint8 i;
    for (i = 0; i < n; i++)
        tableau[i] = calcul_fibonacci_recursif(i);
}
