#include <stdlib.h>
#include <stdio.h>

#define tamanho 10 // Tamanho máximo da pilha

typedef struct no_pilha
{
    int dado[tamanho];
    int topo;
} Tno_pilha;

int Inicializar_pilha(Tno_pilha *pilha);
int Inserir_topo(Tno_pilha *pilha, int info);
int Remover_topo(Tno_pilha *pilha);
int Obter_topo(Tno_pilha *pilha, int *dado);
int Verifica_vazio(Tno_pilha *pilha, int *resp);

int Inicializar_pilha(Tno_pilha *pilha)
{
    pilha->topo = -1;
    return 0; /* sem erro */
}

int Inserir_topo(Tno_pilha *pilha, int info)
{
    // Verificar se a pilha está cheia
    if (pilha->topo == tamanho - 1)
    {
        printf("A pilha está cheia.\n");
        return 1;
    }
    pilha->dado[++pilha->topo] = info;
    return 0;
}

int Remover_topo(Tno_pilha *pilha)
{
    int resp;
    Verifica_vazio(&pilha, &resp);
    if (resp == 0)
    {
        printf("Pilha já está vazia.\n");
        return 1;
    }
    --pilha->topo;
    return 0;
}

int Obter_topo(Tno_pilha *pilha, int *dado)
{
    int resp;
    Verifica_vazio(&pilha, &resp);
    if (resp == 0)
    {
        printf("Pilha está vazia.\n");
        return 1;
    }
    *dado = pilha->dado[pilha->topo];
    return 0;
}

Verifica_vazio(Tno_pilha *pilha, int *resp)
{
    // 0 - lista vazia
    // 1 - lista não vazia
    if (pilha->topo == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int dado = -1, erro = 0;
    Tno_pilha pilha;

    erro = Inicializar_pilha(&pilha);
    if (erro != 0)
    {
        printf("Erro ao inicializar pilha.\n");
    }

    for (int i = 1; i < 12; i++)
    {
        erro = Inserir_topo(&pilha, i);
        if (erro != 0)
        {
            printf("Erro ao inserir dado: %d na pilha.\n", i);
        }
    }

    Obter_topo(&pilha, &dado);
    if (erro != 0)
    {
        printf("Erro ao obter topo da pilha.\n");
    }
    else
    {
        printf("Dado no topo: %d.\n", dado);
    }

    erro = Remover_topo(&pilha);
    if (erro != 0)
    {
        printf("Erro ao remover dado na pilha.\n");
    }

    Obter_topo(&pilha, &dado);
    if (erro != 0)
    {
        printf("Erro ao obter topo da pilha.\n");
    }
    else
    {
        printf("Dado no topo: %d.\n", dado);
    }
}