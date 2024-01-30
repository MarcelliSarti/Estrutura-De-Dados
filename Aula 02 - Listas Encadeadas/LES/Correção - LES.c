
/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES
------------------------------------------------------------------------------*/

struct no_ls {
	int dado;
	struct no_ls *prox;
};

typedef struct no_ls Tno_ls;


/* Tabela de codigo de erros
// 0 - sem erro
// 1 - Lista Vazia // Dado Não encontrado
// 2 - Posicao invalida para insercao -> Menor que 0
// 3 - Posicao invalida -> Acima do tamanho da lista
*/

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS     (Tno_ls **p_inicio);                     // None
int Inicializar2_LS    (Tno_ls **p_inicio);                     // 1
int Inserir_inicio_LS  (Tno_ls **p_inicio, int info);           // 2
int Inserir_meio_LS    (Tno_ls **p_inicio, int info, int pos);  // 3
int Inserir_fim_LS     (Tno_ls **p_inicio, int info);           // 4
int Remover_inicio_LS  (Tno_ls **p_inicio);                     // 5
int Remover_meio_LS    (Tno_ls **p_inicio, int pos);            // 6 - trab     
int Remover_fim_LS     (Tno_ls **p_inicio);                     // 7 - trab
int Listar_LS          (Tno_ls *c_inicio);                      // 8
int Obter_Pos_LS       (Tno_ls *c_inicio, int dado, int *pos);  // 9
int Obter_Tamanho_LS   (Tno_ls *c_inicio, int *tam);            // 10
int Inverter_LS        (Tno_ls **p_inicio);                     // 11
int Inverter_LS_2      (Tno_ls **p_inicio);                     // 12
int Ver_Repete_Dado_LS (Tno_ls *inicio, int info, int *resp);   // 13 - trab
int Maiorque_Dado_LS   (Tno_ls *inicio, int info, int *quant);  // 14 - trab

/* Variaveis global */


/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info;
	int resp, pos, tam, quant;
	int erro; /* valor de erro retornado pelas funcoes */
	Tno_ls *inicio;
	int q;  /* receber a opcao do usuario */
	erro=Inicializar_LS (&inicio);
	printf("Tamanho do no: %ld\n\n" , sizeof(Tno_ls));
	getchar();
	do {
	    system("clear");
	    printf("LISTA ENCADEADA SIMPLES - LES");
		printf("\n\nOpcoes: \n\n");
		printf("1 -> Inicializar a lista (versao 2)\n");
		printf("2 -> Inserir no inicio\n");
		printf("3 -> Inserir no meio\n");
		printf("4 -> Inserir no final\n");
		printf("5 -> Remover no inicio\n");
		printf("6 -> Remover no meio\n");
		printf("7 -> Remover no final \n");
		printf("8 -> Mostrar toda a lista \n");
        printf("9 -> Obter Posição de um valor \n");
		printf("10 -> Obter tamanho da lista \n");
		printf("11 -> Inverter a lista \n");
        printf("12 -> Inverter a lista (versao 2) \n");
        printf("13 -> Ver se um dado é repetido \n");
		printf("14 -> Ver quantidade de dados maior que x \n");
		printf("-1 -> Sair \n\n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: 
                erro=Inicializar2_LS (&inicio);
                printf("\nInicializacao realizada com sucesso !\n");
                printf("\nLISTA VAZIA !\n");
                getchar();
                break;

			case 2: 
                printf("Dado para insercao na lista: ");
                scanf("%d",&info);
                erro=Inserir_inicio_LS (&inicio, info);
                if (erro == 0) printf("\nInsercao realizada com sucesso\n");
                getchar();
                break;

            case 3: 
                printf("Dado para insercao na lista: ");
                scanf("%d",&info);
                printf("Posicao de insercao: ");
                scanf("%d",&pos);
                erro=Inserir_meio_LS (&inicio, info, pos);
                if (erro == 0) printf("\nInsercao realizada com sucesso\n");
                getchar();
                break;

			case 4: 
                printf("Dado para insercao na lista: ");
                scanf("%d",&info);
                Inserir_fim_LS (&inicio, info);
                break;

            case 5: 
                erro = Remover_inicio_LS (&inicio);
                erro == 1 ? printf("\nLista vazia. Impossivel remover") : printf("\nRemoção bem sucedida!\n");
                getchar();
                break;

            case 6:
                printf("Posição da remoção: ");
                scanf("%d", &pos);
                erro = Remover_meio_LS(&inicio, pos);
                erro != 0? printf("\nOcorreu um erro durante a remoção\n") : printf("\nRemoção bem sucedida!\n");
                getchar();
                break;

            case 7:
                erro = Remover_fim_LS(&inicio);
                erro == 1? printf("\nOcorreu um erro durante a remoção\n") : printf("\nRemoção bem sucedida!\n");
                getchar();
                break;

			case 8: 
                erro=Listar_LS (inicio);
                if (erro==1)
                {
                    printf("\nLista vazia. Impossivel listar\n");
                }
                getchar();
                break;

            case 9:
                printf("Qual o valor que deseja buscar na lista?: ");
                scanf("%d", &info);
                Obter_Pos_LS(inicio, info, &pos);
                pos != 0? printf("\nNão foi possivel encontrar o valor na lista!\n"): printf("\nValor encontrado na posição: %d\n", pos);
                getchar();
                break;

            case 10:
                Obter_Tamanho_LS(inicio, &tam);
                tam == 0? printf("\nLista Vazia!\n"): printf("\nA lista possui %d elementos.\n", tam);
                getchar();
                break;

            case 11:
                erro=Inverter_LS (&inicio);
                if (erro == 1)
                    printf("\nLista vazia. Inversao nao realizada !\n");
                else
                    printf("\nInversao realizada !\n");
                getchar();
                break;

			case 12: 
                erro=Inverter_LS_2 (&inicio);
                if (erro == 1)
                    printf("\nLista vazia. Inversao nao realizada !\n");
                else
                    printf("\nInversao realizada !\n");
                getchar();
                break;

			case 13:
                printf("Dado para fazer a comparação: ");
                scanf("%d",&info);
                Ver_Repete_Dado_LS(inicio, info, &resp);
                resp ? printf("\nHá repetições do dado (%d) na lista\n", info) : printf("\nNão há repetições do dado (%d) na lista!\n", info);
                getchar();
                break;

            case 14:
                printf("Dado para fazer a comparação: ");
                scanf("%d",&info);
                Maiorque_Dado_LS(inicio, info, &quant);
                1 ? printf("\nHá %d dados maiores que %d na lista!\n", quant, info) : printf("\nNão há dados maiores que %d na lista!\n", info);
                getchar();
                break;

			case -1: 
                break;

			default: 
                printf("\n\n Opcao nao valida");
                getchar();
                break;
		}
        getchar();   /* Limpa o buffer de entrada */
	} while ((q != -1) );

}


 /* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS (Tno_ls *c_inicio)
{
	int i;
	if (c_inicio == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");
	while (c_inicio != NULL) {
		   printf("%d  ",c_inicio->dado);
		   c_inicio = c_inicio->prox;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da fun��o de MOSTRAR */



int Inicializar_LS (Tno_ls **p_inicio)
{
	*p_inicio= NULL;
	return 0; /* sem erro */
}

/* ================================================= */

int Inicializar2_LS(Tno_ls **p_inicio)
{
    Tno_ls *percorre, *aux;
	if(*p_inicio != NULL)
	{
       percorre = *p_inicio;
	   while (percorre != NULL)
	   {
             aux = percorre;
	         percorre = percorre -> prox;
	         free(aux);
	   }
	   *p_inicio = NULL;
	   return 1; /* inicializa apagando tudo da listsa */
	}
}


/* ================================================= */
int Obter_Tamanho_LS(Tno_ls *c_inicio, int *tam)
{
    Tno_ls *percorre;
    *tam = 0;
	if(c_inicio != NULL)
	{
       percorre = c_inicio;
       while (percorre != NULL)
	   {
         (*tam)++;
         percorre = percorre -> prox;
	   }
     }
    else
    {
         *tam = 0;
    }
}

/* -------------------------------------------------------------------------------------
INSER��O
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **p_inicio, int info)
{
    Tno_ls *no_novo;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

	if (*p_inicio==NULL)
	{    /* insercao em lista vazia */
	    no_novo -> prox = NULL;
	    *p_inicio = no_novo;
	}
	else { /* insercao em lista nao vazia */
	     no_novo -> prox = *p_inicio;
	    *p_inicio = no_novo;
	}
    return 0;
}

/* ================================================= */
int Inserir_meio_LS (Tno_ls **p_inicio, int info, int pos)
{
    int tam;
    Tno_ls *no_novo, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
       return 2;  /*) posicao invalida para insercao */

    Obter_Tamanho_LS(*p_inicio, &tam);
    if (pos > tam+1)
       return 3;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */

    /* Alocacao do novo no */
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    /* procura pela posicao de insercao */
    if (pos==1)
    {   /* insercao no inicio */
        Inserir_inicio_LS (p_inicio, info);
    }
    else
    {   if (pos == tam+1)
        {
            Inserir_fim_LS (p_inicio, info);
        }
        else {
                int pos_aux=1;
                percorre = *p_inicio;
                while (pos_aux!=pos-1) /* parar uma posicao antes */
                {
                   percorre = percorre -> prox;
                   pos_aux++;
                }
                no_novo -> prox = percorre -> prox;
                percorre -> prox = no_novo;
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tno_ls **p_inicio, int info)
{
    Tno_ls *no_novo, *percorre;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> prox = NULL;

    if (*p_inicio==NULL)
	{ /* lista vazia. */
	    *p_inicio = no_novo;
	}
	else { /* lista nao vazia */
	     percorre = *p_inicio;
	     while (percorre->prox != NULL)
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;
	}
	return 0;
}

/* ================================================= */
int Obter_Pos_LS (Tno_ls *c_inicio, int valor, int *pos)
{
    *pos = 0;
    while (c_inicio != NULL)
    {
        (*pos)++;
        if (valor == c_inicio->dado)
        return 0;     /* dado encontrado */
        c_inicio = c_inicio -> prox;
    }
    if (c_inicio != NULL)
        *pos = 0;
    return 1;  /* dado nao encontrado */
}


/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_inicio_LS (Tno_ls **p_inicio)
{
    Tno_ls *aux;
    if (*p_inicio == NULL)
    {
        // printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *p_inicio;
        *p_inicio = (*p_inicio)->prox;
        free(aux);
        return 0;
    }
}

int Remover_meio_LS (Tno_ls **p_inicio, int pos) {
    int tam;
    Tno_ls *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
       return 2;  /*) posicao invalida para insercao */

    Obter_Tamanho_LS(*p_inicio, &tam);
    
    if (pos > tam+1)
       return 3;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */

    /* procura pela posicao de remoção */
    if (pos==1) {   /* Remove no inicio */
        Remover_inicio_LS(p_inicio);
    } else{
        if (pos == tam) {
            Remover_fim_LS (p_inicio);
        } else {
                // Contador de posições
                int pos_aux=1;
                // Ponteiro para percorrer a lista
                percorre = *p_inicio;

                while (pos_aux != pos-1) /* parar uma posicao antes */
                {
                   percorre = percorre -> prox;
                   pos_aux++;
                }

                // Variavel para armazenar o item a ser removido
                Tno_ls *rm = percorre -> prox;
                // Atribui o item pos + 1 como prox do 
                percorre -> prox = rm -> prox;
                // Libera a memória alocada para o valor deletado
                free(rm);
        }
    }
    return 0;
}

int Remover_fim_LS (Tno_ls **p_inicio) {
    Tno_ls *percorre;
    if (*p_inicio==NULL) { 
        /* lista vazia. */
	    return 1;
	} else { /* lista nao vazia */
	    percorre = *p_inicio;
        if (percorre -> prox == NULL) {
            Remover_inicio_LS(p_inicio);
        } else {
            while (percorre->prox->prox != NULL)
	        {
	            percorre = percorre -> prox;
	        }
            Tno_ls * aux = percorre -> prox;
	        percorre -> prox = NULL;
            free(aux);
        }
	}
	return 0;
}

/* -------------------------------------------------------------------------
INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverter_LS (Tno_ls **p_inicio)
{
    Tno_ls *percorre,*aux_1,*aux_2,*aux_3;
    percorre=*p_inicio;
    if(percorre==NULL)
    {
        return 1;/*Caso a lista esteja vazia. */
    }
    else if(percorre->prox==NULL)
    {
        return 0;/*Caso a lista tenha apenas um n�. */
    }
    else
    {
        aux_1       = *p_inicio;        /*O ponteiro aux_a aponta para o primeiro n�, uma vez que o ponteiro "ini" passar� a apontar para o �ltimo. */
        aux_2       = aux_1->prox;    /*O ponteiro aux_p passa a apontar para o segundo n� da lista.*/
        aux_3       = aux_2->prox;    /*O ponteiro aux_v passa a apontar para o terceiro n� da lista.*/
        aux_1->prox = NULL;           /*O primeiro n� da lista passa a ser o �ltimo, apontando para NULL.*/
        aux_2->prox = aux_1;          /*O segundo n� da lista passa a apontar para o primeiro, come�ando a invers�o da lista.*/
                                      /*In�cio - Processo de invers�o.*/
        while(aux_3!=NULL)
        {
            aux_1 = aux_2;             /*O ponteiro aux_a pega o valor do n� a sua frente na lista.*/
            aux_2 = aux_3;             /*O ponteiro aux_p pega o valor do n� a sua frente na lista.*/
            aux_3 = aux_3->prox;       /*O ponteiro aux_v pega o valor do n� a sua frente na lista.*/
            aux_2->prox=aux_1;         /*O n� para o qual aux_p est� apontado passa a apontar para o n� anterior a ele na lista.*/
        }
                                       /*Fim - Processo de invers�o. */
        *p_inicio = aux_2;               /* atualiza��o do ponteiro de inicio */
    }

    return 0;

}

int Inverter_LS_2 (Tno_ls **p_inicio)
{
    int i, erro, tam, info;
    Tno_ls *inicio_lista_aux;      /* lista auxiliar */

    erro = Obter_Tamanho_LS(*p_inicio, &tam);
    if(tam==0)
    {
        return 1;/*Caso a lista esteja vazia.*/
    }
    else if(tam==1)
    {
        return 0;/*Caso a lista tenha apenas um n�.*/
    }
    else
    {
       Inicializar_LS (&inicio_lista_aux);
       for (i = 1; i<=tam; i++)
       {
          info = (*p_inicio)->dado; /* obtendo o dado do 1o. n� */
          //Obter_Dado_LS (p_inicio, 1, &info);
          Remover_inicio_LS (p_inicio);
          Inserir_inicio_LS (&inicio_lista_aux, info);
       }
       *p_inicio = inicio_lista_aux;
    }
    return 0;
}

/* -------------------------------------------------------------------------
Tarefa
-------------------------------------------------------------------------*/
int Ver_Repete_Dado_LS (Tno_ls *inicio, int info, int *resp) {
    Tno_ls *percorre = inicio;
    
    int vezes_info_na_lista = 0;
    
    while (percorre != NULL && vezes_info_na_lista < 2) {
        percorre -> dado == info ? vezes_info_na_lista++ : 0;
        percorre = percorre -> prox;
    }

    *resp = ((vezes_info_na_lista > 1) ? 1 : 0);
    /*  
        // Mesmo que a linha acima:
        if (vezes_info_na_lista > 1) {
            *resp = 1;
        } else {
            *resp = 0;
        } 
    */
}

int Maiorque_Dado_LS (Tno_ls *inicio, int info, int *quant) {
    Tno_ls *percorre = inicio;

    *quant = 0;

    while (percorre != NULL) {
        if ((percorre -> dado) > info) {
            (*quant)++;
        } 
       
        percorre = percorre -> prox;
    }
}
/* -----------------------------------------------------------------------------
EXERCICIOS - Lista Encadeada Simples (Completar o código disponível)

1 - int Remover_meio_LS (Tno_ls **p_inicio, int pos);

2 - int Remover_fim_LS (Tno_ls **p_inicio);

3 - int Ver_Repete_Dado_LS (Tno_ls *inicio, int info, int *resp);
verifica se o dado esta repetido na estrutura
resp = 1 - sim
resp = 0 - nao

4 - int Maiorque_Dado_LS (Tno_ls *inicio, int info, int *quant);
obtem a quantidade de dados maior que info

------------------------------------------------------------------------------*/


