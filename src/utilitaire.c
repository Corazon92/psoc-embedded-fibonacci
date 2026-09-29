/* Projet académique PSoC 5LP - programmation C embarquée */
#include "project.h"
#include <stdio.h>

int _write(int file, char *ptr, int len)
{
    int i;
    (void)file;

    for (i = 0; i < len; i++)
        UART_1_PutChar(*ptr++);

    return len;
}

int _read(int file, char *ptr, int len)
{
    int i;
    uint8 caractere;
    (void)file;

    for (i = 0; i < len; i++)
    {
        do {
            caractere = UART_1_GetChar();
        } while (caractere == 0);

        ptr[i] = caractere;
    }

    return len;
}
