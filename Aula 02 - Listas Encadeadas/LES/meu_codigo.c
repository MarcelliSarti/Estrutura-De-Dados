#include <stdlib.h>
#include <stdio.h>

struct no_ls
{
  int dado;
  struct no_ls *prox;
};

typedef struct no_ls Tno_ls;

int Inserir_LS(Tno_ls **p_inicio, int info);
int Remover_inicio_LS(Tno_ls **p_inicio);
int Obter_Tamanho_LS(Tno_ls *c_inicio, int *tam);
/* Exercício 1 */
int Remover_meio_LS(Tno_ls **p_inicio, int pos);
int Remover_fim_LS(Tno_ls **p_inicio);
int Ver_Repete_Dado_LS(Tno_ls *inicio, int info, int *resp);
int Maiorque_Dado_LS(Tno_ls *inicio, int info, int *quant);

int Inserir_LS(Tno_ls **p_inicio, int info)
{
  Tno_ls *aux, *p_novo;
  // criando o nó
  p_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
  if (p_novo == 0)
    return 1; // n�o h� memoria disponivel
  p_novo->dado = info;
  p_novo->prox = NULL;

  aux = *p_inicio;         // 1
  *p_inicio = p_novo;      // 2   // estou fazendo o ini receber o endereço do nó criado
  (*p_inicio)->prox = aux; // 3

  return 0; // inserção realizada sem erros
}

int Remover_inicio_LS(Tno_ls **p_inicio)
{
  Tno_ls *aux;
  if (*p_inicio == NULL)
  {
    // printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
    return 1; /* lista vazia, impossivel remover primeiro */
  }
  else
  {
    aux = *p_inicio;
    *p_inicio = (*p_inicio)->prox;
    return 0;
  }
}

int Obter_Tamanho_LS(Tno_ls *c_inicio, int *tam)
{
  Tno_ls *percorre;
  *tam = 0;
  if (c_inicio != NULL)
  {
    percorre = c_inicio;
    while (percorre != NULL)
    {
      (*tam)++;
      percorre = percorre->prox;
    }
  }
  else
  {
    *tam = 0;
  }
}

int Remover_meio_LS(Tno_ls **p_inicio, int pos)
{
  Tno_ls *aux1, *percorre;
  int tam;
  Obter_Tamanho_LS(*p_inicio, &tam);
  aux1 = *p_inicio;

  if (pos == 0)
  {
    Remover_inicio_LS(p_inicio);
    // (*p_inicio) = aux1 -> prox;
  }
  else
  {
    for (int i = 0; i < tam; i++)
    {
      if (i == pos)
      {
        aux1 = aux1->prox;
        percorre->prox = aux1;
        break;
      }
      percorre = aux1;
      aux1 = aux1->prox;
    }
  }
  return 0;
}

int Remover_fim_LS(Tno_ls **p_inicio)
{
  Tno_ls *aux1, *percorre;
  aux1 = *p_inicio;
  while (aux1->prox != NULL)
  {
    percorre = aux1;
    aux1 = aux1->prox;
  }
  percorre->prox = NULL;

  return 0;
}

int Ver_Repete_Dado_LS(Tno_ls *inicio, int info, int *resp)
{
  int tam, cont = 0;
  Obter_Tamanho_LS(inicio, &tam);

  *resp = 0;

  for (int i = 0; i < tam; i++)
  {
    if (inicio->dado == info)
    {
      cont++;
    }
    inicio = inicio->prox;
  }

  if (cont > 1)
  {
    *resp = 1;
  }

  return 0;
}

int Maiorque_Dado_LS(Tno_ls *inicio, int info, int *quant)
{
  int tam;
  Obter_Tamanho_LS(inicio, &tam);

  *quant = 0;

  for (int i = 0; i < tam; i++)
  {
    if (inicio->dado > info)
    {
      (*quant)++;
    }
    inicio = inicio->prox;
  }
  return 0;
}

int main(void)
{
  int i, info, quant, resp;
  int erro; /* valor de erro retornado pelas funcoes */
  Tno_ls *inicio, *aux2;

  inicio = NULL; // indicar a lista vazia

  printf("Digite 1o. valor: \n");
  // scanf("%d", &info);
  erro = Inserir_LS(&inicio, 4);
  if (erro != 0)
    printf("Nao foi possivel a insercao. \n");

  printf("Digite 2o. valor: \n");
  // scanf("%d", &info);
  erro = Inserir_LS(&inicio, 3);
  if (erro != 0)
    printf("Nao foi possivel a insercao. \n");

  printf("Digite 3o. valor: \n");
  // scanf("%d", &info);
  erro = Inserir_LS(&inicio, 2);
  if (erro != 0)
    printf("Nao foi possivel a insercao. \n");

  printf("Digite 4o. valor: \n");
  // scanf("%d", &info);
  erro = Inserir_LS(&inicio, 1);
  if (erro != 0)
    printf("Nao foi possivel a insercao. \n");

  // erro = Remover_fim_LS(&inicio);
  // if (erro != 0) printf("Nao foi possivel a delecao. \n");

  // erro = Maiorque_Dado_LS(inicio, 2, &quant);
  // if (erro != 0) printf("Nao foi possivel ver quantididade de itens maior. \n");
  // printf("Qtd itens maior: %d\n", quant);

  // erro = Remover_meio_LS(&inicio, 0);
  // if (erro != 0) printf("Nao foi possivel a delecao. \n");

  erro = Ver_Repete_Dado_LS(inicio, 2, &resp);
  if (erro != 0)
    printf("Nao foi possivel ver se há itens repetidos. \n");
  printf("Há itens repetidos? %d\n", resp);

  // aux2 = inicio;
  // for (i=1;i<=4;i++)
  // {
  //     printf("Valor: %d\n", aux2->dado);
  //     aux2 = aux2 -> prox;
  // }
}
