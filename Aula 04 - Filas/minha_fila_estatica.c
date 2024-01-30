#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO 10

typedef struct fila
{
    int dado[TAMANHO];
    int inicio, fim;
} T_FILA;

int inicializa(T_FILA *f);
int estado(T_FILA fi);
int insere(T_FILA *f, int x);
int remover(T_FILA *f);
int listar(T_FILA f);
int obter_primeiro(T_FILA f, int *dado);

int inicializa(T_FILA *f)
{
    f->inicio = -1;
    f->fim = -1;
    return 0;
}

int estado(T_FILA fi)
{
    if (fi.inicio == -1)
    {
        // fila vazia
        return 0;
    }
    else if (fi.fim == TAMANHO - 1)
    {
        // fila cheia
        return 1;
    }
    else
    {
        // fila com espaço
        return 2;
    }
}

int insere(T_FILA *f, int x)
{
    int est = estado(*f);
    if (est == 1)
    {
        // fila cheia, retorna erro
        return 1;
    }
    else if (est == 0)
    {
        // fila vazia, insere no inicio também
        f->inicio += 1;
    }
    f->fim += 1;
    f->dado[f->fim] = x;
    return 0;
}

int remover(T_FILA *f)
{
    if (f->inicio == -1)
    {
        // fila vazia
        return 1;
    }
    f->inicio += 1;
    return 0;
}

int listar(T_FILA f) {
    int est = estado(f);
    if (est == 0) {
        // lista vazia
        return 1;
    }
    int inicio = f.inicio;
    for (inicio; inicio<=f.fim;inicio++) {
        printf("%d\n", f.dado[inicio]);
    }

    return 0;
}

int obter_primeiro(T_FILA f, int *dado){
    int est = estado(f);
    if (est == 0) {
        // lista vazia
        return 1;
    }
    *dado = f.dado[f.inicio];
    return 0;
}

int main()
{
    int erro;
    int dado;
    T_FILA fila;

    erro = inicializa(&fila);
    if (erro != 0)
    {
        printf("Erro ao inicializar fila");
    }

    erro = estado(fila);
    printf("O estado da fila é %d\n", erro);

    erro = insere(&fila, 0);
    if (erro != 0)
    {
        printf("Erro ao inserir na fila");
    }

    erro = insere(&fila, 1);
    if (erro != 0)
    {
        printf("Erro ao inserir na fila");
    }

    erro = insere(&fila, 2);
    if (erro != 0)
    {
        printf("Erro ao inserir na fila");
    }

    erro = insere(&fila, 3);
    if (erro != 0)
    {
        printf("Erro ao inserir na fila");
    }

    erro = remover(&fila);
    if (erro != 0)
    {
        printf("Erro ao remover da fila");
    }

    erro = listar(fila);
    if (erro != 0)
    {
        printf("Erro ao listar fila");
    }

    erro = obter_primeiro(fila, &dado);
    if (erro != 0)
    {
        printf("Erro ao obter primeiro dado");
    } else {
        printf("Primeiro dado: %d\n", dado);
    }
}