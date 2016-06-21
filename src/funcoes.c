//
//  funcoes.c
//  AED-TRABALHO-1
//
//  Created by Andre Victor on 18/06/16.
//  Copyright © 2016 Andre Victor. All rights reserved.
//

#include "funcoes.h"
#include <stdlib.h>
/**
 *  <#Description#>
 *
 *  @param livro      <#livro description#>
 *  @param prateleira <#prateleira description#>
 *  @param cod        <#cod description#>
 *  @param autor      <#autor description#>
 *  @param titulo     <#titulo description#>
 *  @param num_prat   <#num_prat description#>
 *  @param num_est    <#num_est description#>
 *
 *  @return <#return value description#>
 */
int inserir_livro_prat(FILE *livro,FILE *prateleira, int cod, char *autor, char *titulo, int num_prat, int num_est) {
    cabecalho cab_prat = *le_cabecalho(prateleira);
    Prateleira *prat;
    int pos,nump,nume;
    int pos_prat = cab_prat.pos_cabeca;
    if (busca_end_livro(livro, cod, &nume, &nump, &pos) != -1) {
        return 0;
    }
    int pos_livro = inserir_livro(livro, cod, autor, titulo, num_prat, num_est);
    while (pos_prat != -1) {
        prat = le_prateleira(prateleira, pos_prat);
        
        if (num_est == prat->num_est) {
            if (num_prat == prat->num) {
                int aux = cod;
                int cod_aux = cod;
                int aux2 = pos_livro;
                int i = 0;
                for (i = 0; i < prat->quant_livro; i++) {
                    if (cod < prat->cod_livro[i]) {
                        aux = prat->cod_livro[i];
                        prat->cod_livro[i] = cod_aux;
                        cod_aux = aux;
                        aux2 = prat->end_livro[i];
                        prat->end_livro[i] = pos_livro;
                        pos_livro = aux2;
                    }
                    
                }
                prat->quant_livro++;
                prat->cod_livro[i] = aux;
                prat->end_livro[i] = aux2;
                if (prat->quant_livro == 0) {
                    prat->cod_livro[0] = cod;
                    prat->end_livro[0] = pos_livro;
                }
                escreve_prateleira(prateleira, prat, pos_prat);
                free(prat);
                return 1;
            }
        }
        pos_prat = prat->prox;
    }
    return 0;
}

void delete_livro(FILE *arq, int pos_ant, int pos) {
    cabecalho* cab = le_cabecalho(arq);
    Livro *liv_ant = le_livro(arq, pos_ant);
    Livro *liv = le_livro(arq, pos);
    if (cab->pos_cabeca == pos) //Remoção na cabeça
        cab->pos_cabeca = liv->prox;
    else
        liv_ant->prox = liv->prox;
    liv->prox = cab->pos_livre;
    cab->pos_livre = pos;
    escreve_cabecalho(arq, cab);
    escreve_livro(arq, liv_ant,pos_ant);
    escreve_livro(arq, liv, pos);
    free(cab);
    free(liv);
    free(liv_ant);
}

void delete_livro_prat(FILE *prateleira, int num_prat, int num_est, int cod_livro) {
    cabecalho cab_prat = *le_cabecalho(prateleira);
    Prateleira *prat = NULL;
    int pos_prat = cab_prat.pos_cabeca;
    int aux = 0;
    while (pos_prat != -1) {
        prat = le_prateleira(prateleira, pos_prat);
        if (num_est == prat->num_est) {
            if (num_prat == prat->num) {
                for (int i = 0; i < prat->quant_livro; i++) {
                    if (prat->cod_livro[i] >= cod_livro) {
                        prat->cod_livro[i] = prat->cod_livro[i + 1];
                        aux = pos_prat;
                        
                    }
                    
                }
                prat->quant_livro--;
                escreve_prateleira(prateleira, prat, aux);
                free(prat);
                return;
            }
        }
        pos_prat = prat->prox;
    }
    free(prat);
}
/**
 *  Retira um livro da biblioteca permanentemente
 *
 *  @pre  Arquivos abertos
 *
 *  @param cod        codigo do livro a ser removido
 *  @param livro      Arquivo do livro
 *  @param prateleira Arquivo da prateleira
 */
void retirar_livro(int cod, FILE *livro, FILE *prateleira) {
    int num_est, num_prat, pos_ant, pos;
    if ((pos_ant = busca_end_livro(livro, cod, &num_est, &num_prat, &pos) != -1)) {
        delete_livro(livro, pos_ant, pos);
        delete_livro_prat(prateleira, num_prat, num_est, cod);
    }
}
/**
 *  Busca o endereço do livro físico e virtual no arquivo livro
 *
 *  @param livro Arquivo de livros
 *  @param cod   codigo do livro
 *  @param est   endereço da variavel numero da estante
 *  @param prat  endereço da variavel numero da prateleira
 *  @param pos   endereço da variavel posição do livro no arquivo
 *
 *  @return retorna -1 se não achar, retorna a posição do livro anterior
 */
int busca_end_livro(FILE *livro, int cod, int *est, int *prat, int *pos) {
    cabecalho cab = *le_cabecalho(livro);
    Livro liv;
    *pos = cab.pos_cabeca;
    int pos_ant = *pos;
    fseek(livro, 0, SEEK_SET);
    while (!feof(livro) && *pos != -1) {
        liv = *le_livro(livro, *pos);
        
        
        if (cod == liv.cod) {
            if (liv.status) {
                *est = liv.num_est;
                *prat = liv.num_prat;
            }
            return pos_ant;
        }
        pos_ant = *pos;
        *pos = liv.prox;
    }
    return -1;
}



/**
 *  Pega o livro da prateleira e coloca na pilha em uma sala
 *
 *  @param pilha1 Arquivo de pilha num 1
 *  @param pilha2 Arquivo de pilha num 2
 *  @param pilha3 Arquivo de pilha num 3
 *  @param sala   Arquivo da sala
 *  @param livro  Arquivo dos livros
 *  @param cod    codigo do livro a ser emprestado
 *  @param ra     RA do aluno
 *
 *  @return retorna 0 caso n posso emprestar o livro, se sim retorna 1
 */
int emprestar_livro(FILE *pilha1, FILE *pilha2,FILE *pilha3, FILE *sala, FILE* livro, int cod, int ra) {
    int pos_sala = 0;
    int num_sala;
    if ((num_sala = verificar_sala_ra(sala, ra, &pos_sala))) {
        int aux = 0;
        if (num_sala == 1) {
            aux = verificar_livro(pilha1, livro, cod, ra, pos_sala);
        }
        if (num_sala == 2) {
            aux = verificar_livro(pilha2, livro, cod, ra, pos_sala);
        }
        if (num_sala == 3) {
            aux = verificar_livro(pilha3, livro, cod, ra, pos_sala);
        }
        return aux;
    }
    return 0;
}

/**
 *  Verifica se o aluno com determinado RA esta em alguma sala e em qual sala ele esta
 *
 *  @pre            Arquivos abertos
 *
 *  @param sala     Arquivo de sala
 *  @param ra       numero do RA do aluno
 *  @param pos_sala endereço de memoria da pos_sala
 *
 *  @return retorna o número da sala caso tenha algum aluno com determinado ra nela, se não retorna 0
 */
int verificar_sala_ra(FILE *sala, int ra, int *pos_sala) {
    cabecalho cab_sala = *le_cabecalho(sala);
    Sala sl;
    int pos = cab_sala.pos_livre;
    int num_sala = 0;
    while (pos != -1) {
        sl = *le_sala(sala, pos);
        if(sl.ra == ra) {
            *pos_sala = pos;
            num_sala = sl.num;
        }
        pos = sl.prox;
    }
    if (num_sala == 0) {
        printf("Esse aluno não está em nenhuma sala\n");
        return 0;
    }
    return num_sala;
}

int verificar_livro(FILE* pilha, FILE* livro,int cod, int ra, int pos_sala){
    Livro *liv;
    int est, prat;
    int pos_livro;
    
    if(busca_end_livro(livro, cod, &est, &prat, &pos_livro) != -1) {
        liv = le_livro(livro, pos_livro);
        if(liv->status == -1) {
            printf("livro indisponível\n");
            free(liv);
            return 0;
        }
    
        push_pilha(pilha, ra, pos_livro, pos_sala);
        liv->status = -1;
        escreve_livro(livro, liv, pos_livro);
        
    }else {
        printf("Livro inexistente");
        return 0;
    }
    free(liv);
    return 1;
}

void imprime_estante(FILE* livro, FILE *estante, FILE *prateleira) {
    int pos_est;
    cabecalho cab_est;
    Estante est;
    Prateleira prat;
    Livro liv;
    cab_est = *le_cabecalho(estante);
    pos_est = cab_est.pos_cabeca;
    while (pos_est != -1) {
        est = *le_estante(estante, pos_est);
        pos_est = est.prox;
        printf("\nEstante: %d\n",est.num);
        for (int i = 0; i < est.quant_prat; i++) {
            prat = *le_prateleira(prateleira, est.end_prat[i]);
            printf("Prateleira: %d\n",prat.num);
            for (int j = 0; j < prat.quant_livro; j++) {
                liv = *le_livro(livro, prat.end_livro[j]);
                printf("%d, ",liv.cod);
                printf("%s, ",liv.autor);
                printf("%s\n",liv.titulo);
            }
        }
    }
}

/**
 *
 *
 *  @param sala <#sala description#>
 *  @param fila <#fila description#>
 *  @param ra   <#ra description#>
 *
 *  @return retorna o número da sala locada ou 0 se estiver na lista de espera
 */
int locar_sala(FILE* sala, FILE *fila, int ra){
    cabecalho* cab = le_cabecalho(sala);
    Sala *sl;
    int aux;
    if(cab->pos_cabeca == -1) {
        enqueue_fila_espera(fila, ra);
        return 0;
    }
    else {
        sl = le_sala(sala,cab->pos_cabeca);
        int num = sl->num;
        sl->ra = ra;
        aux = cab->pos_cabeca;
        cab->pos_cabeca = sl->prox;
        sl->prox = cab->pos_livre;
        cab->pos_livre = aux;
        escreve_sala(sala,sl,cab->pos_livre);
        escreve_cabecalho(sala, cab);
        return num;
        
    }

}


/**
 *  Remove o aluno da sala em que ele esta e libera a sala pra ser usada por outro
 *
 *  @param sala     Arquivo de sala
 *  @param num_sala numero da sala
 *  @param pos_sala posição da sala no arquivo
 */
void remover_aluno_sala(FILE *sala, int num_sala, int pos_sala) {
    cabecalho *cab_sala = le_cabecalho(sala);
    Sala *sl = le_sala(sala, pos_sala);
    Sala *aux;
    sl->ra = 0;
    int pos_ant = 0;
    int pos = cab_sala->pos_livre;
    if (cab_sala->pos_livre == pos_sala) { //remoção na cabeça
        cab_sala->pos_livre = sl->prox;
    }
    else {
        
        while (pos != -1 && pos != pos_sala) {
            aux = le_sala(sala, pos);
            pos_ant = pos;
            pos = aux->prox;
        }
        aux = le_sala(sala, pos_ant);
        aux->prox = sl->prox;
        
    }
    sl->prox = cab_sala->pos_cabeca;
    cab_sala->pos_cabeca = pos_sala;

    escreve_sala(sala, sl, pos_sala);
    escreve_sala(sala, aux, pos_ant);
    escreve_cabecalho(sala, cab_sala);
    free(cab_sala);
    free(sl);
    free(aux);
    
}
/**
 *  Desempilha toda a pilha de livro
 *
 *  @pre  Arquivos abertos
 *
 *  @param pilha Arquivo de pilha
 *  @param livro Arquivo de livro
 */
void desempilhar_pilha(FILE *pilha, FILE *livro) {
    int aux = 1;
    do {
        aux = pop_pilha(pilha, livro);
    }while (aux);
}

void ocupar_sala_fila(FILE *fila, FILE *sala) {
    int ra;
    if ((ra = dequeue_fila_espera(fila))) {
        locar_sala(sala, fila, ra);
        printf("Novo aluno da fila ocupando a sala, com RA: %d\n", ra);
    }
}

/**
 *  Libera a sala ocupada
 *
 *  @param sala   Arquivo de sala
 *  @param pilha1 Arquivo da pilha 1
 *  @param pilha2 Arquivo da pilha 2
 *  @param pilha3 Arquivo da pilha 3
 *  @param livro  Arquivo de livro
 *  @param pilha  Arquivo de fila
 *  @param ra     RA do aluno
 *
 *  @return retorna 1 se bem sucedido em liberar sala ou 0 se não
 */
int liberar_sala(FILE *sala, FILE *pilha1, FILE *pilha2, FILE *pilha3, FILE *livro, FILE *fila, int ra) {
    int pos_sala;
    int num_sala;
    if ((num_sala = verificar_sala_ra(sala, ra, &pos_sala))) {
        remover_aluno_sala(sala, num_sala, pos_sala);
        if (num_sala == 1) {
            desempilhar_pilha(pilha1, livro);
        }
        if (num_sala == 2) {
            desempilhar_pilha(pilha2, livro);
        }
        if (num_sala == 3) {
            desempilhar_pilha(pilha3, livro);
        }
        ocupar_sala_fila(fila, sala);
        return 1;
    }
    return 0;
}

/**
 *  Imprime o mapa de salas
 * 
 *  @pre         Arquivo aberto
 *
 *  @param sala  Arquivo contendo as salas
 *  @param pilha Arquivo contendo a pilha de livros emprestados
 */
void imprime_mapa_sala(FILE *sala, FILE *livro, FILE *pilha1, FILE *pilha2, FILE *pilha3) {
    cabecalho cab = *le_cabecalho(sala);
    Sala sl;
    int pos_sala_ocupada = cab.pos_livre;
    int pos_sala_livre = cab.pos_cabeca;
    printf("Salas livres:\n");
    while (pos_sala_livre != -1) {
        sl = *le_sala(sala, pos_sala_livre);
        printf("Sala %d, ", sl.num);
        pos_sala_livre = sl.prox;
    }
    printf("\nSalas ocupadas:\n");
    while (pos_sala_ocupada != -1) {
        sl = *le_sala(sala, pos_sala_ocupada);
        printf("Sala %d:\n", sl.num);
        printf("RA: %d\n", sl.ra);
        pos_sala_ocupada = sl.prox;
        printf("Livros:\n");
        if (sl.num == 1) {
            imprime_pilha_livro(pilha1, livro);
        }
        if (sl.num == 2) {
            imprime_pilha_livro(pilha2, livro);
        }
        if (sl.num == 3) {
            imprime_pilha_livro(pilha3, livro);
        }
    }
}

void imprime_pilha_livro(FILE *pilha, FILE *livro) {
    cabecalho cab = *le_cabecalho(pilha);
    Pilha_Livro pil;
    Livro liv;
    int pos = cab.pos_cabeca;
    while (pos != -1) {
        pil = *le_pilha(pilha, pos);
        liv = *le_livro(livro, pil.pos_livro);
        printf("%d, ",liv.cod);
        printf("%s, ",liv.autor);
        printf("%s\n",liv.titulo);
        pos = pil.prox;
    }
}


void imprime_fila(FILE *arq) {
    int pos_fila;
    Fila fila;
    cab_fila *cab = le_cab_fila(arq);
    pos_fila = cab->pos_final;
    printf("Fila:\n");
    int n = 0;
    while (pos_fila != -1) {
        fila = *le_fila(arq, pos_fila);
        n++;
        pos_fila = fila.prox;
    }
    pos_fila = cab->pos_final;
    while (pos_fila != -1) {
        fila = *le_fila(arq, pos_fila);
        printf("%do RA: %d\n",n,fila.ra);
        pos_fila = fila.prox;
        n--;
    }
    free(cab);
}


