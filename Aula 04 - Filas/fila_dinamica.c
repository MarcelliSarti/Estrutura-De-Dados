#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct est {
    int dado;
    struct est *prox;  
} T_EST;

typedef struct fila {
   struct est *inicio, *fim;
} T_FILA;


int inicializa (T_FILA *f);
int insere(T_FILA *f, int x);
int remover(T_FILA *f);
int listar(T_FILA f);
int obter_primeiro(T_FILA f, int *dado);

int inicializa (T_FILA *f){
    f -> inicio = NULL;
    f -> fim = NULL;
    
    return 0;
}

int insere(T_FILA *f, int x) {
    T_EST *est_aux = (T_EST *)malloc(sizeof(T_EST));

    est_aux -> dado = x;
    est_aux -> prox = NULL;
    
    if (f -> inicio == NULL) {
        // fila vazia, insere no começo
        f -> inicio = est_aux;
    } else {
        // fila com dados, insere no fim
        f -> fim -> prox = est_aux;
    }

    f -> fim = est_aux;
    return 0;
}

int remover(T_FILA *f){
    T_EST *est_aux = (T_EST *)malloc(sizeof(T_EST));

    est_aux = f -> inicio -> prox;
    f -> inicio = est_aux;    
   
    // fila ficou vazia 
    if (f -> inicio == NULL) {
        f -> fim = NULL;
    }

    return 0;
}

int listar(T_FILA f){
    struct est *aux;
    aux = f.inicio;
    
    while (aux != NULL){
        printf("%d\n", aux -> dado);
        aux = aux -> prox;
    }
    
    return 0;
}

int obter_primeiro(T_FILA f, int *dado){
    *dado = f.inicio->dado;
    
    return 0;
}


int main() {
    int erro;
    T_FILA fila;
    int dado;

    erro = inicializa(&fila);
    if (erro != 0) {
        printf("Erro ao inicializar fila\n");
    }

    erro = insere(&fila, 0);
    if (erro != 0) {
        printf("Erro ao inserir na fila\n");
    }
    
    erro = insere(&fila, 1);
    if (erro != 0) {
        printf("Erro ao inserir na fila\n");
    }
    
    erro = insere(&fila, 2);
    if (erro != 0) {
        printf("Erro ao inserir na fila\n");
    }
    
    erro = remover(&fila);
    if (erro != 0) {
        printf("Erro ao remover da fila\n");
    }
    
    erro = listar(fila);
    if (erro != 0) {
        printf("Erro ao lista fila\n");
    }
    
    erro = obter_primeiro(fila, &dado);
    if (erro != 0) {
        printf("Erro ao obter primeiro dado da fila\n");
    } else {
        printf("Primeiro dado da fila: %d\n", dado);    
    }
}