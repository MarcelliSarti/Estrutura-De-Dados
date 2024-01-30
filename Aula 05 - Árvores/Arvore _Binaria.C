#include <stdio.h>
#include <stdlib.h>
/* Implementa��o de Arvore Binaria */

typedef int Tipo_Dado;

typedef struct bloco_ab
{
    Tipo_Dado Dado;
    struct bloco_ab *FilhoEsq, *FilhoDir;
    struct bloco_ab *Pai; /* adicionalmente foi incluido o ponteiro para pai */
} Nodo_AB;

FILE *saida;

int inicializa_arvbin(Nodo_AB **AB);
int insere_ord_arvbin(Nodo_AB **AB, Tipo_Dado Dado);
int remove_dado_arvbin(Nodo_AB **AB, Tipo_Dado Dado);
int exibe_ab_infixado(Nodo_AB *AB);
int exibe_ab_prefixado(Nodo_AB *AB);
int exibe_ab_posfixado(Nodo_AB *AB);
int maior_arvbin(Nodo_AB *AB, Tipo_Dado *Dado_out);

int apaga_arvbin(Nodo_AB **AB);
int conta_nodos_arvbin(Nodo_AB *AB);
int pesquisa_arvbin(Nodo_AB *AB, Tipo_Dado Dado, int *resp);
int menor_arvbin(Nodo_AB *AB, Tipo_Dado Dado, Tipo_Dado *menor);
int maior_arvbin(Nodo_AB *AB, Tipo_Dado Dado, Tipo_Dado *maior);
int sucessor_arvbin(Nodo_AB *AB, Tipo_Dado Dado_in, Tipo_Dado *Dado_out);
int predecessor_arvbin(Nodo_AB *AB, Tipo_Dado Dado_in, Tipo_Dado *Dado_out);

// Gerador aleatorio de dados
int gera_dado(int min, int max)
{
    int k;
    double d;
    d = (double)rand() / ((double)RAND_MAX + 1);
    k = d * (max - min + 1);
    return min + k;
}

// =============================
void imprimeNo(int d, int p, int b)
{
    int i;
    // em tela
    for (i = 1; i < b; i++)
        printf("|------");
    printf("%d(%d)\n", d, p);
    // em arquivo
    for (i = 1; i < b; i++)
        fprintf(saida, "|------");
    fprintf(saida, "%d(%d)\n", d, p);
}

void mostraArvore(Nodo_AB *Pai, Nodo_AB *AB, int b)
{
    if (AB == NULL)
    {
        // imprimeNo(0, Pai->Dado, b);  // n�o mostra os filhos nulos
        return;
    }
    mostraArvore(AB, AB->FilhoDir, b + 1);
    if ((AB->Pai) != NULL) // se estive nao esta na raiz
        imprimeNo(AB->Dado, (AB->Pai)->Dado, b);
    else
        imprimeNo(AB->Dado, 0, b);
    mostraArvore(AB, AB->FilhoEsq, b + 1);
}
// ==========================================

void calc_largura(Nodo_AB *AB, int *larg)
{
    if (AB->FilhoEsq != NULL)
    {
        calc_largura(AB->FilhoEsq, larg);
        (*larg)++;
    }
    if (AB->FilhoDir != NULL)
    {
        calc_largura(AB->FilhoDir, larg);
        (*larg)++;
    }
}

int inicializa_arvbin(Nodo_AB **AB)
{
    *AB = NULL;
    return 0;
}

int apaga_arvbin(Nodo_AB **AB)
{
    if (*AB == NULL)
        return 1;

    apaga_arvbin(&(*AB)->FilhoDir);
    apaga_arvbin(&(*AB)->FilhoEsq);
    (*AB)->Dado = NULL;
    return 0;
}

int conta_nodos_arvbin(Nodo_AB *AB)
{
    if (AB == NULL)
        return 0; // erro

    return 1 + conta_nodos_arvbin(AB->FilhoDir) + conta_nodos_arvbin(AB->FilhoEsq);
}

int pesquisa_arvbin(Nodo_AB *AB, Tipo_Dado Dado, int *resp)
{
    (*resp) = 0; // não encontrou o dado
    if (AB == NULL)
        return 1; // erro

    if (AB->Dado == Dado)
    {
        (*resp) = 1; // encontrou o dado
        return 0;    // acaba aqui a função
    }

    // Se o item não está no nó atual, verifica nos filhos
    if (pesquisa_arvbin(AB->FilhoDir, Dado, resp) == 0)
        return 0; // item encontrado, interrompe a busca

    if (pesquisa_arvbin(AB->FilhoEsq, Dado, resp) == 0)
        return 0; // item encontrado, interrompe a busca
}

int menor_arvbin(Nodo_AB *AB, Tipo_Dado Dado, Tipo_Dado *menor)
{
    // verifica nós a esquerda
    // retorna primeiro dado menor que Dado
    if (AB == NULL)
        return 1; // erro

    if (AB->Dado < Dado)
    {
        (*menor) = AB->Dado;
        return 0; // sucesso
    }

    if ((menor_arvbin(AB->FilhoEsq, Dado, menor)) == 0)
        return 0; // para a execução pq encontrou
}

int maior_arvbin(Nodo_AB *AB, Tipo_Dado Dado, Tipo_Dado *maior)
{
    // verifica nós a direita
    // retorna primeiro dado menor que Dado
    if (AB == NULL)
        return 1; // erro

    if (AB->Dado > Dado)
    {
        (*maior) = AB->Dado;
        return 0; // sucesso
    }

    if ((maior_arvbin(AB->FilhoDir, Dado, maior)) == 0)
        return 0; // para a execução pq encontrou
}

int sucessor_arvbin(Nodo_AB *AB, Tipo_Dado Dado_in, Tipo_Dado *Dado_out)
{
    if (AB == NULL)
        return 1; // erro

    if (AB->Dado == Dado_in)
    {
        (*Dado_out) = (AB->FilhoDir)->Dado;
        return 0;
    }

    if ((sucessor_arvbin(AB->FilhoDir, Dado_in, Dado_out)) == 0)
        return 0; // encontrou, encerra execução
    if ((sucessor_arvbin(AB->FilhoEsq, Dado_in, Dado_out)) == 0)
        return 0; // encontrou, encerra execução
}

int predecessor_arvbin(Nodo_AB *AB, Tipo_Dado Dado_in, Tipo_Dado *Dado_out)
{   
    (*Dado_out) = -1000;
    if (AB == NULL)
        return 1; // erro

    if ((AB->FilhoDir != NULL) && (AB->FilhoDir->Dado == Dado_in) || ((AB->FilhoEsq != NULL) && (AB->FilhoEsq->Dado == Dado_in)))
    {
        (*Dado_out) = AB->Dado;
        return 0;
    }

    // Caso o valor não esteja no nó atual, continua a busca nos filhos
    if (Dado_in <= AB->Dado)
        return predecessor_arvbin(AB->FilhoEsq, Dado_in, Dado_out); // busca à esquerda
    else
        return predecessor_arvbin(AB->FilhoDir, Dado_in, Dado_out); // busca à direita
}

int insere_ord_arvbin(Nodo_AB **AB, Tipo_Dado Dado)
{
    /* Arvore binaria onde os n�s sao inseridos de maneira ordenada:   */
    /* - Os n�s a esquerda de um n� pai sao sempre menores que ele   */
    /* - Os n�s a direita de um n� pai sao sempre maiores que ele    */

    Nodo_AB *novo, *aux, *temp;

    novo = (Nodo_AB *)malloc(sizeof(Nodo_AB));
    if (novo == NULL)
        return 1;

    novo->Dado = Dado;
    novo->FilhoEsq = NULL;
    novo->FilhoDir = NULL;
    aux = *AB;

    while (aux != NULL) /* Acha o ponto onde vai inserir */
    {

        temp = aux;
        if (Dado == (aux->Dado))
            return 1; // inser��o nao realizada - dado j� existe na �rvore
        if (Dado > (aux->Dado))
            aux = aux->FilhoDir; /*  insere_ord_arvbin (aux -> FilhoDir, Dado)  */
        else
            aux = aux->FilhoEsq; /*  insere_ord_arvbin (aux -> FilhoEsq, Dado)  */
    }

    if (aux == *AB) // arvore vazia
    {
        novo->Pai = NULL;
        *AB = novo;
    }
    else
    {
        novo->Pai = temp;
        if (Dado > temp->Dado)
            temp->FilhoDir = novo;
        else
            temp->FilhoEsq = novo;
    }
    // chamar verifica balanceamento
    // chamar balacear
    return 0; // inser��o realizada
}

int exibe_ab_infixado(Nodo_AB *AB)
{
    if (AB != NULL)
    {
        exibe_ab_infixado(AB->FilhoEsq); // 1
        printf("%d ", AB->Dado);         // 2
        exibe_ab_infixado(AB->FilhoDir); // 3
    }
}

int exibe_ab_prefixado(Nodo_AB *AB)
{
    if (AB != NULL)
    {
        printf("%d ", AB->Dado);
        exibe_ab_prefixado(AB->FilhoEsq);
        exibe_ab_prefixado(AB->FilhoDir);
    }
}

int exibe_ab_posfixado(Nodo_AB *AB)
{
    if (AB != NULL)
    {
        exibe_ab_posfixado(AB->FilhoEsq);
        exibe_ab_posfixado(AB->FilhoDir);
        printf("%d ", AB->Dado);
    }
}

void exibe_maiores(Nodo_AB *AB, int x, int *total)
{
    if (AB != NULL)
    {
        exibe_maiores(AB->FilhoEsq, x, total);
        exibe_maiores(AB->FilhoDir, x, total);
        if (AB->Dado > x)
            (*total)++;
    }
}

void ver_balanc(Nodo_AB *AB, int *resp, int *alt)
{
    int resp_e, resp_d;
    int alt_e, alt_d;
    if (AB != NULL)
    {
        ver_balanc(AB->FilhoEsq, &resp_e, &alt_e);
        ver_balanc(AB->FilhoDir, &resp_d, &alt_d);

        /* Calculando a altura do n�vel */
        if (alt_e >= alt_d)
            *alt = alt_e + 1;
        else
            *alt = alt_d + 1;

        /* Calculando o balenceamento */
        if (((alt_e == alt_d) || (alt_e == alt_d + 1) || (alt_e + 1 == alt_d)) && (resp_e == 1) && (resp_d == 1))
            *resp = 1; /* sim - balanceado */
        else
            *resp = 0; /* n�o balanceado */
    }
    else
    {
        *resp = 1; /* sim - balanceado */
        *alt = 0;
    }
}

int main()
{
    int i, q, quant, min, max, dado, erro, larg = 1;
    Nodo_AB *Arvore;
    int resp, alt;
    int x, total = 0;

    do
    {
        system("cls");
        printf("Arvore Binaria de Busca\n\n");
        printf("\n\nOpcoes: \n\n");
        printf("0 -> Inicializa\n");
        printf("1 -> Insere quant. de dados aleatorios\n");
        printf("2 -> Insere um unico dado\n");
        printf("3 -> Mostra Arvore em forma hierarquica\n");
        printf("4 -> Mostra Dados da Arvore em Ordem\n");
        printf("5 -> Mostra Dados da Arvore em Pre-Ordem\n");
        printf("6 -> Mostra Dados da Arvore em Pos-Ordem\n");
        printf("7 -> Verifica balanceamento, altura e largura\n");
        printf("8 -> Exibe total de maiores que um dado\n");
        printf("9 -> Sair \n:");
        scanf("%d", &q); /* Ler a opcao do usuario */
        switch (q)
        {
        case 0:
            inicializa_arvbin(&Arvore);
            break;
        case 1: /* inser��o de dados aleatorios para teste */
            printf("Quantidade de Dados desejados: ");
            scanf("%d", &quant);
            printf("Valor MINIMO no intervalo de geracao do inteiro aleatorio: ");
            scanf("%d", &min);
            printf("Valor MAXIMO no intervalo de geracao do inteiro aleatorio: ");
            scanf("%d", &max);
            // sugestoes
            // quant = 20
            // min = 6;
            // max = 500;

            dado = gera_dado(min, max); // desprezando o primeiro gerado

            for (i = 1; i <= quant; i++)
            {
                dado = gera_dado(min, max);
                printf("dado = %d\n", dado);
                insere_ord_arvbin(&Arvore, dado);
            }
            system("pause");
            break;

        case 2: /* insere um dado */
            printf("Dado = \n");
            scanf("%d", &dado);
            erro = insere_ord_arvbin(&Arvore, dado);
            if (erro == 1)
                printf("Insercao nao realizada - Dado ja existente\n\n");
            else
                printf("Insercao realizada com sucesso\n\n");
            system("pause");
            break;

        case 3: /* mostra arvore em forma de �rvore*/
            // preparando arquivo
            saida = fopen("c:\\luiz\\saida.txt", "wt");
            if (saida == NULL)
            {
                printf("\nImpossivel abrir arquivo de saida.\n");
                system("pause");
            }
            fprintf(saida, "\nMostra Arvore Ordenada\n\n\n");
            printf("\nMostra Arvore Binaria Ordenada\n\n\n");
            mostraArvore(NULL, Arvore, 1);
            printf("\n\n");
            fclose(saida);
            system("pause");
            break;

        case 4: /* mostra dados em ordem */
            printf("\nMostra Arvore: modo infixado (ordem)\n");
            exibe_ab_infixado(Arvore);
            system("pause");
            printf("\n\n");
            break;

        case 5: /* mostra dados em pre-ordem */
            printf("\n\nMostra Arvore: modo prefixado (pre-ordem)\n");
            exibe_ab_prefixado(Arvore);
            system("pause");
            printf("\n\n");
            break;

        case 6: /* mostra dados em pos-ordem */
            printf("\n\nMostra Arvore: modo posfixado (pos-ordem)\n");
            exibe_ab_posfixado(Arvore);
            printf("\n\n");
            system("pause");
            break;
        case 7: /* verifica balanceamento e altura */
            larg = 0;
            ver_balanc(Arvore, &resp, &alt);
            calc_largura(Arvore, &larg);
            printf("Balanceado (0-nao 1-sim) : %d\n", resp);
            printf("Altura da Arvore : %d\n", alt);
            printf("Largura da Arvore: %d\n", larg);
            system("pause");
            break;

        case 8: /* exibe maiores que um dado */
            printf("Digite dado: ");
            scanf("%d", &x);
            exibe_maiores(Arvore, x, &total);
            printf("Total de Dados maiores que %d : %d\n\n", x, total);
            system("pause");
            break;
        case 9:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
        getchar(); /* Limpa o buffer de entrada */
    } while ((q != 9));
    system("pause");
}
