#include <stdlib.h>
#include <stdio.h>

struct no_ls
{
    int dado;
    struct no_ls *prox;
};

typedef struct no_ls Tno_ls;

int Inicializar_LS(Tno_ls **p_inicio);
int Inicializar2_LS(Tno_ls **p_inicio); // Inicializa apagando tudo da lista (implementar)
int Inserir_inicio_LS(Tno_ls **p_inicio, int info);
int Inserir_fim_LS(Tno_ls **p_inicio, int info);
int Inserir_meio_LS(Tno_ls **p_inicio, int info, int pos);
int Remover_inicio_LS(Tno_ls **p_inicio);
int Remover_fim_LS(Tno_ls **p_inicio);
int Remover_meio_LS(Tno_ls **p_inicio, int pos);
int Listar_LS(Tno_ls *c_inicio);
int Obter_pos_LS(Tno_ls *c_inicio, int dado, int *pos);
int Obter_Tamanho_LS(Tno_ls *c_inicio, int *tam);
int Inverte_LS(Tno_ls **p_inicio);   // gambiarra (não vou utilizar)  implementar
int Inverte_LS_2(Tno_ls **p_inicio); 
int Ver_Repete_Dado_LS(Tno_ls *inicio, int info, int *resp);
int Maiorque_Dado_LS(Tno_ls *inicio, int info, int *quant);

int Inicializar_LS(Tno_ls **p_inicio)
{
    *p_inicio = NULL;
    return 0;
}

int Inicializar2_LS(Tno_ls **p_inicio) {
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

int Inserir_inicio_LS(Tno_ls **p_inicio, int info)
{
    struct no_ls *novo_no;
    novo_no = (struct no_ls *)malloc(sizeof(struct no_ls));
    novo_no->dado = info;
    if (*p_inicio == NULL)
    {
        novo_no->prox = NULL;
        *p_inicio = novo_no;
    }
    else
    {
        novo_no->prox = *p_inicio;
        *p_inicio = novo_no;
    }

    return 0;
}

int Inserir_fim_LS(Tno_ls **p_inicio, int info)
{
    struct no_ls *novo_no;
    novo_no = (struct no_ls *)malloc(sizeof(struct no_ls));
    novo_no->dado = info;
    novo_no->prox = NULL;
    if (*p_inicio == NULL)
    {
        *p_inicio = novo_no;    
    }
    else
    {
        Tno_ls *aux;
        aux = (Tno_ls *)malloc(sizeof(Tno_ls));
        aux = *p_inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo_no;
    }
    return 0;
}

int Inserir_meio_LS(Tno_ls **p_inicio, int info, int pos)
{
    struct no_ls *novo_no;
    novo_no = (struct no_ls *)malloc(sizeof(struct no_ls));
    novo_no->dado = info;
    if (*p_inicio == NULL)
    {
        novo_no->prox = NULL;
        *p_inicio = novo_no;    
    }
    else
    {
        int cont = 0;
        Tno_ls *aux;
        aux = (Tno_ls *)malloc(sizeof(Tno_ls));
        aux = *p_inicio;

        while (cont != pos - 1)
        {
            aux = aux->prox;
            cont++;
        }
        novo_no->prox = aux->prox;
        aux->prox = novo_no;
    }

    return 0;
}

int Remover_inicio_LS(Tno_ls **p_inicio)
{
    if (*p_inicio == NULL)
    {
        printf("Não há dados para remover\n");
        return 1;
    }
    else
    {
        struct no_ls *aux;
        aux = (struct no_ls *)malloc(sizeof(struct no_ls));

        aux = *p_inicio;
        aux = aux->prox;
        *p_inicio = aux;
    }
    return 0;
}

int Remover_fim_LS(Tno_ls **p_inicio)
{
    if (*p_inicio == NULL)
    {
        printf("Não há dados para remover\n");
        return 1;
    } else
    {
        struct no_ls *aux, *percorre;
        aux = (struct no_ls *)malloc(sizeof(struct no_ls));
        percorre = (struct no_ls *)malloc(sizeof(struct no_ls));

        aux = *p_inicio;
        while (aux->prox != NULL)
        {
            percorre = aux;
            aux = aux->prox;
        }
        percorre->prox = NULL;
    }
    return 0;
}

int Remover_meio_LS(Tno_ls **p_inicio, int pos)
{
    if (*p_inicio == NULL)
    {
        printf("Não há dados para remover\n");
        return 1;
    }
    else {
        int cont = 0;
        struct no_ls *aux;
        struct no_ls *percorre;
        aux = (struct no_ls *)malloc(sizeof(struct no_ls));
        percorre = (struct no_ls *)malloc(sizeof(struct no_ls));

        aux = *p_inicio;
        percorre = aux->prox;
        while (cont != pos - 1)
        {
            aux = aux->prox;
            percorre = aux->prox;
            cont++;
        }
        aux->prox = percorre->prox;
    }
    return 0;
}

int Listar_LS(Tno_ls *c_inicio)
{
    struct no_ls *aux;
    aux = (struct no_ls *)malloc(sizeof(struct no_ls));
    *aux = *c_inicio;
    while (aux != NULL)
    {
        printf("Dado: %d\n", aux->dado);
        aux = aux->prox;
    }
    return 0;
}

int Obter_pos_LS(Tno_ls *c_inicio, int dado, int *pos)
{
    *pos = 0;

    struct no_ls *aux;
    aux = (struct no_ls *)malloc(sizeof(struct no_ls));
    *aux = *c_inicio;

    while (aux->dado != dado)
    {
        (*pos)++;
        aux = aux->prox;
    }
    return 0;
}

int Obter_Tamanho_LS(Tno_ls *c_inicio, int *tam)
{
    if (c_inicio == NULL)
    {
        // lista vazia
        *tam = 0;
    }
    else
    {
        *tam = 0;
        struct no_ls *aux;
        aux = (struct no_ls *)malloc(sizeof(struct no_ls));
        aux = c_inicio;
        while (aux != NULL)
        {
            (*tam)++;
            aux = aux->prox;
        }
    }
    return 0;
}

int Ver_Repete_Dado_LS(Tno_ls *inicio, int info, int *resp)
{
    *resp = 0;
    if (inicio == NULL)
    {
        // lista vazia
        return 1;
    }
    struct no_ls *aux;
    aux = (struct no_ls *)malloc(sizeof(struct no_ls));
    aux = inicio;
    while (aux != NULL)
    {
        if (aux->dado == info)
        {
            (*resp)++;
        }
        aux = aux->prox;
    }
    return 0;
}

int Maiorque_Dado_LS(Tno_ls *inicio, int info, int *quant) {
    *quant = 0;
    if (inicio == NULL){
        // lista vazia
        return 1;
    }
    struct no_ls *aux;
    aux = (struct no_ls *) malloc(sizeof(struct no_ls));
    aux = inicio;
    while (aux != NULL){
        if (aux -> dado > info){
            (*quant)++;
        }
        aux = aux -> prox;
    }
    return 0;
}

int Inverte_LS_2(Tno_ls **p_inicio) {
    int i, erro, tam, info;
    
    struct no_ls *aux;
    aux = (struct no_ls *) malloc(sizeof(struct no_ls));
    aux = *p_inicio;

    Tno_ls *new_list;

    erro = Obter_Tamanho_LS(*p_inicio, &tam);
    if(tam==0) {
        return 1;/*Caso a lista esteja vazia.*/
    }
    else if(tam==1) {
        return 0;/*Caso a lista tenha apenas um n�.*/
    } else {
        Inicializar_LS (&new_list);
        for (i = 1; i<=tam; i++)
        {
            info = (*p_inicio)->dado; /* obtendo o dado do 1o. n� */
            //Obter_Dado_LS (p_inicio, 1, &info);
            Remover_inicio_LS (p_inicio);
            Inserir_inicio_LS (&new_list, info);
        }
        *p_inicio = new_list;
    }
    return 0;
}

int main(){
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
                Obter_pos_LS(inicio, info, &pos);
                pos != 0? printf("\nNão foi possivel encontrar o valor na lista!\n"): printf("\nValor encontrado na posição: %d\n", pos);
                getchar();
                break;

            case 10:
                Obter_Tamanho_LS(inicio, &tam);
                tam == 0? printf("\nLista Vazia!\n"): printf("\nA lista possui %d elementos.\n", tam);
                getchar();
                break;

            // case 11:
            //     erro=Inverte_LS (&inicio);
            //     if (erro == 1)
            //         printf("\nLista vazia. Inversao nao realizada !\n");
            //     else
            //         printf("\nInversao realizada !\n");
            //     getchar();
            //     break;

			case 12: 
                erro=Inverte_LS_2 (&inicio);
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
                resp > 1 ? printf("\nHá repetições do dado (%d) na lista\n", info) : printf("\nNão há repetições do dado (%d) na lista!\n", info);
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