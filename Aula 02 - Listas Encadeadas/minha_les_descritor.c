#include <stdlib.h>
#include <stdio.h>

typedef struct no_ls
{
    int dado;
    struct no_ls *prox;
} Tno_ls;

typedef struct descritor_ls
{
    int tam;
    struct no_ls *prim;
    struct no_ls *ult;
} Tdescritorno_ls;

int Inicializar_LS(Tdescritorno_ls *pdesc);
int Inserir_inicio_LS(Tdescritorno_ls *pdesc, int info);
int Inserir_fim_LS(Tdescritorno_ls *pdesc, int info);
int Inserir_meio_LS(Tdescritorno_ls *pdesc, int info, int pos);
int Remover_inicio_LS(Tdescritorno_ls *pdesc);
int Remover_meio_LS(Tdescritorno_ls *pdesc, int pos);
int Remover_fim_LS(Tdescritorno_ls *pdesc);
int Listar_LS(Tdescritorno_ls cdesc);
int Obter_dado_LS(Tdescritorno_ls cdesc, int pos, int *dado);
int Obter_pos_LS(Tdescritorno_ls cdesc, int dado, int *pos);
int Obter_Tamanho_LS(Tdescritorno_ls cdesc, int *tam);

int Inicializar_LS(Tdescritorno_ls *pdesc)
{
    pdesc->prim = NULL;
    pdesc->ult = NULL;
    pdesc->tam = 0;

    return 0;
}

int Inserir_inicio_LS(Tdescritorno_ls *pdesc, int info)
{
    Tno_ls *novo_no;
    novo_no = (Tno_ls *)malloc(sizeof(Tno_ls));

    novo_no->dado = info;

    if (pdesc->prim == NULL)
    {
        // lista vazia
        pdesc->prim = novo_no;
        pdesc->ult = novo_no;
        pdesc->tam = 1;
    }
    else
    {
        novo_no->prox = pdesc->prim;
        pdesc->prim = novo_no;
        pdesc->tam += 1;
    }

    return 0;
}

int Inserir_fim_LS(Tdescritorno_ls *pdesc, int info)
{
    Tno_ls *novo_no;
    novo_no = (Tno_ls *)malloc(sizeof(Tno_ls));

    novo_no->dado = info;

    if (pdesc->prim == NULL)
    {
        // lista vazia
        pdesc->prim = novo_no;
        pdesc->ult = novo_no;
        pdesc->tam = 1;
    }
    else
    {
        (pdesc->ult)->prox = novo_no;
        pdesc->ult = novo_no;
        pdesc->tam += 1;
    }

    return 0;
}

int Inserir_meio_LS(Tdescritorno_ls *pdesc, int info, int pos)
{
    Tno_ls *novo_no;
    novo_no = (Tno_ls *)malloc(sizeof(Tno_ls));

    novo_no->dado = info;

    if (pdesc->prim == NULL)
    {
        // lista vazia
        pdesc->prim = novo_no;
        pdesc->ult = novo_no;
        pdesc->tam = 1;
    }
    else
    {
        int cont = 1;
        Tno_ls *aux;
        aux = (Tno_ls *)malloc(sizeof(Tno_ls));

        aux = pdesc->prim;
        while (cont != pos - 1)
        {
            aux = aux->prox;
            cont++;
        }
        novo_no->prox = aux->prox;
        aux->prox = novo_no;
        pdesc->tam += 1;
    }

    return 0;
}

int Remover_inicio_LS(Tdescritorno_ls *pdesc)
{
    Tno_ls *aux;
    aux = (Tno_ls *)malloc(sizeof(Tno_ls));

    if (pdesc->prim == NULL)
    {
        return 1; // lista vazia;
    }

    aux = pdesc->prim;
    pdesc->prim = aux->prox;
    pdesc->tam -= 1;

    return 0;
}

int Remover_fim_LS(Tdescritorno_ls *pdesc)
{
    Tno_ls *aux, *percorre;
    aux = (Tno_ls *)malloc(sizeof(Tno_ls));
    percorre = (Tno_ls *)malloc(sizeof(Tno_ls));

    if (pdesc->prim == NULL)
    {
        return 1; // lista vazia;
    }

    aux = pdesc->prim;

    while (aux->prox != NULL)
    {
        percorre = aux;
        aux = aux->prox;
    }
    percorre->prox = NULL;
    pdesc->ult = percorre;
    pdesc->tam -= 1;

    return 0;
}

int Remover_meio_LS(Tdescritorno_ls *pdesc, int pos)
{
    Tno_ls *aux;
    int cont = 1;
    aux = (Tno_ls *)malloc(sizeof(Tno_ls));
    if (pdesc->prim == NULL)
    {
        return 1; // lista vazia;
    }

    aux = pdesc->prim;

    while (cont != pos - 1)
    {
        aux = aux->prox;
        cont++;
    }

    aux->prox = (aux->prox)->prox;

    pdesc->tam -= 1;

    return 0;
}

int Obter_dado_LS(Tdescritorno_ls cdesc, int pos, int *dado)
{
    Tno_ls *aux;
    int cont = 1;
    aux = (Tno_ls *)malloc(sizeof(Tno_ls));
    if (cdesc.prim == NULL)
    {
        return 1; // lista vazia;
    }

    aux = cdesc.prim;

    while (cont != pos)
    {
        aux = aux->prox;
        cont++;
    }

    (*dado) = aux->dado;
    return 0;
}

int Obter_pos_LS(Tdescritorno_ls cdesc, int dado, int *pos)
{
    Tno_ls *aux;
    (*pos) = 1;
    aux = (Tno_ls *)malloc(sizeof(Tno_ls));
    if (cdesc.prim == NULL)
    {
        return 1; // lista vazia;
    }

    aux = cdesc.prim;

    while (aux->dado != dado)
    {
        aux = aux->prox;
        (*pos)++;
    }
    return 0;
}

int Listar_LS(Tdescritorno_ls cdesc)
{
    Tno_ls *aux;
    aux = (Tno_ls *)malloc(sizeof(Tno_ls));
    aux = cdesc.prim;

    while (aux != NULL)
    {
        printf("Dado: %d\n", aux->dado);
        aux = aux->prox;
    }
    return 0;
}

int Obter_Tamanho_LS(Tdescritorno_ls cdesc, int *tam)
{
    (*tam) = cdesc.tam;
    return 0;
}

int main()
{
    int dado, pos, tam;
    int erro; /* valor de erro retornado pelas funcoes */
    Tdescritorno_ls desc;

    erro = Inicializar_LS(&desc);
    if (erro != 0)
    {
        printf("Erro ao inicilializar lista\n");
    }

    erro = Inserir_inicio_LS(&desc, 2);
    if (erro != 0)
    {
        printf("Erro ao inserir no início da lista\n");
    }

    erro = Inserir_inicio_LS(&desc, 1);
    if (erro != 0)
    {
        printf("Erro ao inserir no início da lista\n");
    }

    erro = Inserir_inicio_LS(&desc, 1);
    if (erro != 0)
    {
        printf("Erro ao inserir no início da lista\n");
    }

    erro = Inserir_fim_LS(&desc, 4);
    if (erro != 0)
    {
        printf("Erro ao inserir no fim da lista\n");
    }

    erro = Inserir_fim_LS(&desc, 5);
    if (erro != 0)
    {
        printf("Erro ao inserir no fim da lista\n");
    }

    erro = Inserir_fim_LS(&desc, 5);
    if (erro != 0)
    {
        printf("Erro ao inserir no fim da lista\n");
    }

    erro = Inserir_meio_LS(&desc, 3, 4);
    if (erro != 0)
    {
        printf("Erro ao inserir no meio da lista\n");
    }

    erro = Inserir_meio_LS(&desc, 3, 5);
    if (erro != 0)
    {
        printf("Erro ao inserir no meio da lista\n");
    }

    erro = Remover_inicio_LS(&desc);
    if (erro != 0)
    {
        printf("Erro ao remover no início da lista\n");
    }

    erro = Remover_fim_LS(&desc);
    if (erro != 0)
    {
        printf("Erro ao remover no fim da lista\n");
    }

    erro = Remover_meio_LS(&desc, 4);
    if (erro != 0)
    {
        printf("Erro ao remover no meio da lista\n");
    }

    erro = Listar_LS(desc);
    if (erro != 0)
    {
        printf("Erro ao listar lista\n");
    }

    erro = Obter_dado_LS(desc, 3, &dado);
    if (erro != 0)
    {
        printf("Erro ao obter posição do dado na lista\n");
    }
    else
    {
        printf("Dado da posição x: %d\n", dado);
    }

    erro = Obter_pos_LS(desc, 3, &pos);
    if (erro != 0)
    {
        printf("Erro ao obter dado na posição da lista\n");
    }
    else
    {
        printf("Posição do dado x: %d\n", pos);
    }

    erro = Obter_Tamanho_LS(desc, &tam);
    if (erro != 0)
    {
        printf("Erro ao obter tamanho da lista\n");
    }
    else
    {
        printf("Tamanho da lista: %d\n", tam);
    }
}