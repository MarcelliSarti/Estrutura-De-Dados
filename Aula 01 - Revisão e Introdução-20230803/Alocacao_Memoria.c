#include <stdlib.h>
#include <stdio.h>

typedef struct pessoa
{
    int peso;
    float altura;
    char nome[50];
    char endereco[100];
    struct pessoa *proxima;
} T_Pessoa;

main()
{
    /* =====================  Aloca��o est�tica */
    T_Pessoa p1, p2, p3;
    T_Pessoa vp[10];

    p1.peso = 89;
    p1.altura = 1.89;

    vp[0].peso = 90;
    vp[0].altura = 1.69;

    // printf("Tamanho da pessoa: %d bytes\n", sizeof(T_Pessoa));
    // printf("peso = %d\n",vp[0].peso);

    /* ======================= Aloca��o din�mica */

    T_Pessoa *py, *px, *pz;
    int i;

    // 1a pessoa
    px = (T_Pessoa *)malloc(sizeof(T_Pessoa));
    px->peso = 89;
    px->altura = 1.98;

    // 2a. pessoa
    py = (T_Pessoa *)malloc(sizeof(T_Pessoa));
    py->peso = 80;
    py->altura = 1.90;

    // 1a. pessoa aponta para a 2a. pessoa
    px->proxima = py; // liga��o / encadeamento

    // 3a. pessoa
    pz = (T_Pessoa *)malloc(sizeof(T_Pessoa));

    // 2a. pessoa aponta para a 3a. pessoa
    (px->proxima)->proxima = pz;
}
