/* Projet académique PSoC 5LP - programmation C embarquée */
#ifndef FONCTION_H
#define FONCTION_H

#include "project.h"

extern uint8 envoi_donnees;

void fibonacci_iteratif(uint8 n, uint16 tableau[]);
uint32 calcul_fibonacci_recursif(uint8 n);
void fibonacci_recursif(uint8 n, uint16 tableau[]);

#endif
