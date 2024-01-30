#include <stdlib.h>
#include <stdio.h>

typedef struct no_pilha {
    int dado;
    struct Tno_pilha *prox;
} Tno_pilha;

int Inicializar_pilha(Tno_pilha **pilha);
int Inserir_topo(Tno_pilha **pilha, int info);
int Remover_topo(Tno_pilha **pilha);
int Obter_topo(Tno_pilha *pilha, int *dado);
int Verifica_vazio(Tno_pilha *pilha, int *resp);

int Inicializar_pilha(Tno_pilha **pilha){
    *pilha = NULL;
    return 0;
}

int Inserir_topo(Tno_pilha **pilha, int info) {
    Tno_pilha *novo_no;
    novo_no = (Tno_pilha *) malloc(sizeof(Tno_pilha));
    novo_no -> dado = info;

    if (*pilha == NULL){
        novo_no -> prox = NULL;
        *pilha = novo_no;
    } else {
        novo_no -> prox = *pilha;
        *pilha = novo_no;    
    }
    return 0;
}

int Remover_topo(Tno_pilha **pilha){
    if (pilha == NULL) {
        // pilha vazia
        return 1;
    }

    Tno_pilha *aux;
    aux = (Tno_pilha *) malloc(sizeof(Tno_pilha));
    aux = (*pilha) -> prox;
    *pilha = aux;

    return 0;    
}

int Obter_topo(Tno_pilha *pilha, int *dado){
    if (pilha == NULL) {
        // pilha vazia
        return 1;
    }
    *dado = pilha -> dado;
    return 0;
}

int Verifica_vazio(Tno_pilha *pilha, int *resp) {
    if (pilha == NULL){
        // pilha vazia
        *resp = 1;
    } else {
        *resp = 0;
    }
    return 0;
}

int main() {
    int dado, erro, resp;
    Tno_pilha *pilha;

    erro = Inicializar_pilha(&pilha);
    if (erro != 0) {
        printf("Erro ao inicilizar pilha\n");
    }

    erro = Verifica_vazio(pilha, &resp);
    if (erro != 0) {
        printf("Erro ao obter topo da pilha\n");
    } else {
        if (resp == 0) {
            printf("Pilha não vazia!\n");
        } else {
            printf("Pilha vazia!\n");
        }
    }

    erro = Inserir_topo(&pilha, 0);
    if (erro != 0) {
        printf("Erro ao inserir na pilha\n");
    }

    erro = Obter_topo(pilha, &dado);
    if (erro != 0) {
        printf("Erro ao obter topo da pilha\n");
    } else {
        printf("Topo da pilha: %d\n", dado);
    }

    erro = Inserir_topo(&pilha, 1);
    if (erro != 0) {
        printf("Erro ao inserir na pilha\n");
    }
    
    erro = Obter_topo(pilha, &dado);
    if (erro != 0) {
        printf("Erro ao obter topo da pilha\n");
    } else {
        printf("Topo da pilha: %d\n", dado);
    }

    erro = Inserir_topo(&pilha, 2);
    if (erro != 0) {
        printf("Erro ao inserir na pilha\n");
    }
    
    erro = Obter_topo(pilha, &dado);
    if (erro != 0) {
        printf("Erro ao obter topo da pilha\n");
    } else {
        printf("Topo da pilha: %d\n", dado);
    }

    erro = Inserir_topo(&pilha, 3);
    if (erro != 0) {
        printf("Erro ao inserir na pilha\n");
    }
    
    erro = Obter_topo(pilha, &dado);
    if (erro != 0) {
        printf("Erro ao obter topo da pilha\n");
    } else {
        printf("Topo da pilha: %d\n", dado);
    }

    erro = Remover_topo(&pilha);
    if (erro != 0) {
        printf("Erro ao remover da pilha\n");
    }
    
    erro = Obter_topo(pilha, &dado);
    if (erro != 0) {
        printf("Erro ao obter topo da pilha\n");
    } else {
        printf("Topo da pilha: %d\n", dado);
    }

    erro = Verifica_vazio(pilha, &resp);
    if (erro != 0) {
        printf("Erro ao obter topo da pilha\n");
    } else {
        if (resp == 0) {
            printf("Pilha não vazia!\n");
        } else {
            printf("Pilha vazia!\n");
        }
    }
}