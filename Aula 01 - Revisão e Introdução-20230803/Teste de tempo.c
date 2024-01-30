#include <stdlib.h>
#include <stdio.h>
#include <time.h>

main( )
{
    int vet[100000];
    int i;
    clock_t t_inicio, t_fim;
    long long int Tempo_usado;  // em milisegundos

    t_inicio = clock(); // ======================================

    for (i=1;i<=100000;i++)
    {
            printf("Vetor[%d] = %d\n",i,vet[i]);
    }

    t_fim = clock(); // ==================================


    // resultado do tempo
    Tempo_usado = (t_fim - t_inicio) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nTempo usado: %d ms.", Tempo_usado);


}







