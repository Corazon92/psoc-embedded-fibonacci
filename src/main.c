/* Projet académique PSoC 5LP - programmation C embarquée */
#include "project.h"
#include "fonction.h"
#include <stdio.h>
#define N 10

int main(void)
{
    CyGlobalIntEnable;
    UART_1_Start();
    UART_1_PutString("connexion UART\r\n");
    uint16 resultat_iteratif[N];

    char choix;
    printf("Entrez un caractere : \r\n");
    scanf("%c", &choix);
    printf("\r\nVous avez entre : %c\r\n", choix);

    for(;;)
    {
        if (choix == 'F')
        {
            fibonacci_iteratif(N, resultat_iteratif);

            if (envoi_donnees == 1)
            {
                printf("Fibonnaci iteratif : \r\n");
                for (int i = 0; i < N; i++)
                    printf("F(%u) = %u\r\n", i, resultat_iteratif[i]);

                uint8 tmpStat;
                do {
                    tmpStat = UART_1_ReadTxStatus();
                } while ((tmpStat & UART_1_TX_STS_COMPLETE) == 0);

                envoi_donnees = 0;
                printf("Entrez un caractere : \r\n");
                scanf("%c", &choix);
                printf("\r\nVous avez entre : %c\r\n", choix);
            }
        }
        else
        {
            printf("Caractere incorrect, entrez F : \r\n");
            scanf("%c", &choix);
            printf("\r\nVous avez entre : %c\r\n", choix);
        }
    }
}
