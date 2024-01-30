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
