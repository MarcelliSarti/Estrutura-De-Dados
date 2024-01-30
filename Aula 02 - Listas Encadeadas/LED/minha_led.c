#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct no_ld
{
    int dado;
    struct no_ld *prox, *ant;
} Tno_ld;

int Inicializar_LD(Tno_ld **inicio);
int Inicializar2_LD(Tno_ld **p_inicio);
int Inserir_inicio_LD(Tno_ld **p_inicio, int info);
int Inserir_fim_LD(Tno_ld **p_inicio, int info);
int Inserir_meio_LD(Tno_ld **p_inicio, int info, int pos);
int Remover_inicio_LD(Tno_ld **p_inicio);
int Remover_meio_LD(Tno_ld **p_inicio, int pos);
int Remover_fim_LD(Tno_ld **p_inicio);
int Listar_LD(Tno_ld *c_inicio);
int Listar_Invertido_LD(Tno_ld *c_inicio);
int Obter_pos_LD(Tno_ld *c_inicio, int dado, int *pos);
int Obter_Tamanho_LD(Tno_ld *c_inicio, int *tam);
int Inverter_LD(Tno_ld **p_inicio);
int Remover_metade_LED(Tno_ld **p_inicio);

int Listar_LD(Tno_ld *c_inicio)
{
    if (c_inicio == NULL)
    {
        // lista vazia
        return 1;
    }
    while (c_inicio != NULL)
    {
        printf("Dado: %d\n", c_inicio->dado);
        c_inicio = c_inicio->prox;
    }
    return 0;
}

int Inicializar_LD(Tno_ld **inicio)
{
    *inicio = NULL;
    return 0;
}

int Inserir_inicio_LD(Tno_ld **p_inicio, int info)
{
    struct no_ld *novo_no;
    novo_no = (struct no_ld *)malloc(sizeof(struct no_ld));
    novo_no->ant = NULL;
    novo_no->dado = info;
    if (p_inicio == NULL)
    {
        novo_no->prox = NULL;
    }
    else
    {
        novo_no->prox = *p_inicio;
    }
    *p_inicio = novo_no;
    return 0;
}

int Inserir_fim_LD(Tno_ld **p_inicio, int info)
{
    struct no_ld *novo_no;
    novo_no = (struct no_ld *)malloc(sizeof(struct no_ld));

    Tno_ld *aux;
    aux = (Tno_ld *)malloc(sizeof(Tno_ld));
    aux = *p_inicio;

    novo_no->prox = NULL;
    novo_no->dado = info;

    if (*p_inicio == NULL)
    {
        novo_no->ant = NULL;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        novo_no->ant = aux;
    }

    aux->prox = novo_no;

    return 0;
}

int Inserir_meio_LD(Tno_ld **p_inicio, int info, int pos)
{
    struct no_ld *novo_no;
    novo_no = (struct no_ld *)malloc(sizeof(struct no_ld));
    novo_no->dado = info;

    Tno_ld *aux;
    aux = (Tno_ld *)malloc(sizeof(Tno_ld));

    aux = *p_inicio;

    if (*p_inicio == NULL)
    {
        novo_no->prox = NULL;
        novo_no->ant = NULL;
        *p_inicio = novo_no;
        return 0;
    }
    else
    {
        int cont = 1;
        while (cont != pos - 1)
        {
            aux = aux->prox;
            cont++;
        }
        novo_no->prox = aux->prox;
        aux->prox = novo_no;
        novo_no->ant = aux;
        (aux->prox)->ant = novo_no;
    }
    return 0;
}

int Inverter_LD(Tno_ld **p_inicio)
{
    Tno_ld *aux, *percorre;
    int dado;
    aux = (Tno_ld *)malloc(sizeof(Tno_ld));
    percorre = (Tno_ld *)malloc(sizeof(Tno_ld));

    aux = *p_inicio;
    percorre = *p_inicio;
    while (percorre != NULL)
    {
        dado = aux->dado;
        printf("%d\n", dado);
        // Inserir_fim_LD(&p_inicio, dado);
        // Remover_inicio_LD(&p_inicio);
        aux = aux->prox;
        percorre = percorre->prox;
    }
    return 0;
}

int Remover_inicio_LD(Tno_ld **p_inicio)
{
    if (*p_inicio == NULL)
    {
        return 1;
    }

    Tno_ld *aux;
    aux = (Tno_ld *)malloc(sizeof(Tno_ld));
    aux = (*p_inicio)->prox;
    aux->ant = NULL;
    *p_inicio = aux;
    return 0;
}

int Remover_fim_LD(Tno_ld **p_inicio)
{
    if (*p_inicio == NULL)
    {
        return 1;
    }

    Tno_ld *aux, *percorre;
    aux = (Tno_ld *)malloc(sizeof(Tno_ld));
    percorre = (Tno_ld *)malloc(sizeof(Tno_ld));
    aux = *p_inicio;
    while (aux->prox != NULL)
    {
        percorre = aux;
        aux = aux->prox;
    }
    percorre->prox = NULL;
    return 0;
}

int Remover_meio_LD(Tno_ld **p_inicio, int pos)
{
    struct no_ld *no_remover;

    Tno_ld *aux;
    aux = (Tno_ld *)malloc(sizeof(Tno_ld));

    aux = *p_inicio;

    int cont = 1;
    while (cont != pos - 1)
    {
        aux = aux->prox;
        cont++;
    }
    no_remover = aux->prox;
    aux->prox = no_remover->prox;
    (no_remover->prox)->ant = no_remover->ant;

    return 0;
}

int Obter_pos_LD(Tno_ld *c_inicio, int dado, int *pos)
{
    (*pos) = 1;
    while (c_inicio->dado != dado)
    {
        c_inicio = c_inicio->prox;
        (*pos)++;
    }
    return 0;
}

int Obter_Tamanho_LD(Tno_ld *c_inicio, int *tam)
{
    (*tam) = 0;
    while (c_inicio != NULL)
    {
        (*tam)++;
        c_inicio = c_inicio->prox;
    }
    return 0;
}

int Listar_Invertido_LD(Tno_ld *c_inicio)
{
    while (c_inicio->prox != NULL)
    {
        c_inicio = c_inicio->prox;
    }
    while (c_inicio->ant != NULL)
    {
        printf("Dado invertido: %d\n", c_inicio->dado);
        c_inicio = c_inicio->ant;
    }
    return 0;
}

int main()
{
    int erro;
    Tno_ld *inicio;
    struct no_ld *aux;
    int pos, tam;

    erro = Inicializar_LD(&inicio);
    if (erro != 0)
    {
        printf("Erro ao inicializar lista!\n");
    }

    erro = Inserir_inicio_LD(&inicio, 2);
    if (erro != 0)
    {
        printf("Erro ao inserir no início da lista!\n");
    }

    erro = Inserir_inicio_LD(&inicio, 1);
    if (erro != 0)
    {
        printf("Erro ao inserir no início da lista!\n");
    }

    erro = Inserir_inicio_LD(&inicio, 0);
    if (erro != 0)
    {
        printf("Erro ao inserir no início da lista!\n");
    }

    erro = Inserir_inicio_LD(&inicio, 0);
    if (erro != 0)
    {
        printf("Erro ao inserir no início da lista!\n");
    }

    erro = Inserir_fim_LD(&inicio, 4);
    if (erro != 0)
    {
        printf("Erro ao inserir no fim da lista!\n");
    }

    erro = Inserir_fim_LD(&inicio, 5);
    if (erro != 0)
    {
        printf("Erro ao inserir no fim da lista!\n");
    }

    erro = Inserir_fim_LD(&inicio, 5);
    if (erro != 0)
    {
        printf("Erro ao inserir no fim da lista!\n");
    }

    erro = Inserir_meio_LD(&inicio, 3, 5);
    if (erro != 0)
    {
        printf("Erro ao inserir no meio da lista!\n");
    }

    erro = Inserir_meio_LD(&inicio, 3, 6);
    if (erro != 0)
    {
        printf("Erro ao inserir no meio da lista!\n");
    }

    erro = Remover_inicio_LD(&inicio);
    if (erro != 0)
    {
        printf("Erro ao remover no início da lista!\n");
    }

    erro = Remover_fim_LD(&inicio);
    if (erro != 0)
    {
        printf("Erro ao remover no fim da lista!\n");
    }

    erro = Remover_meio_LD(&inicio, 4);
    if (erro != 0)
    {
        printf("Erro ao remover no meio da lista!\n");
    }

    erro = Listar_LD(inicio);
    if (erro != 0)
    {
        printf("Erro ao listar lista!\n");
    }

    erro = Obter_pos_LD(inicio, 1, &pos);
    if (erro != 0)
    {
        printf("Erro ao obter posição!\n");
    }
    else
    {
        printf("Posição do dado: %d\n", pos);
    }

    erro = Obter_Tamanho_LD(inicio, &tam);
    if (erro != 0)
    {
        printf("Erro ao obter tamanho!\n");
    }
    else
    {
        printf("Tamanho da lista: %d\n", tam);
    }

    // erro = Listar_Invertido_LD(inicio);
    // if (erro != 0)
    // {
    //     printf("Erro ao listar invertido!\n");
    // }

    // erro = Inverter_LD(inicio);
    // if (erro != 0)
    // {
    //     printf("Erro ao inverter lista!\n");
    // }

    erro = Listar_LD(inicio);
    if (erro != 0)
    {
        printf("Erro ao listar lista!\n");
    }
}