/**
 * Autores:Andre Victor e Khadije El Zein
 */

#ifndef funcoes_h
#define funcoes_h

#include <stdio.h>
#include "arquivos.h"
#include "inserir_arquivo.h"
/**
 *  Funcao que insere um livro em uma prateleira
 *  pre-condicoes: arquivos abertos
 *  pos-condicao: isere livro na prateleira
 */
int inserir_livro_prat(FILE *livro,FILE *prateleira, int cod, char *autor, char *titulo, int num_prat, int num_est);
/**
 *  Funcao que retira um livro de um arquivo de livros
 *  pre-condicoes: arquivo aberto
 *  pos-condicao: remove o livro do arquivo
 *  retorno:nenhum
 */
void delete_livro(FILE *arq, int pos_ant, int pos);

/**  Funcao que retira um livro de uma prateleira
 *  pre-condicoes: arquivo aberto
 *  pos-condicao: remove o livro do arquivo de prateleiras
 *  retorno:nenhum
 */
void delete_livro_prat(FILE *prateleira, int num_prat, int num_est, int cod_livro);

/**
 *  Retira um livro da biblioteca permanentemente
 *  pre-condicao:  Arquivos abertos
 *  pos-condicao: remove o livro permanentemente
 *
 */
void retirar_livro(int cod, FILE *livro, FILE *prateleira);
/**
 *  Funcao que busca o endereço do livro físico e virtual no arquivo livro
 *  pre-condicao: arquivo aberto
 *  pos-condicao: retorna o livro do arquivo
 *  retorno:retorna -1 se não achar, retorna a posição do livro anterior
 */
int busca_end_livro(FILE *livro, int cod, int *est, int *prat, int *pos);
/**
 *  Funcao que empresta o livro para um aluno que ira usar a sala de estudos
 *  pre-condicao: arquivos abertos
 *  pos-condicao: empilha o livro
 */
int emprestar_livro(FILE *pilha1, FILE *pilha2,FILE *pilha3, FILE *sala, FILE* livro, int cod, int ra);
/**
 *  Verifica se o aluno com determinado RA esta em alguma sala e em qual sala ele esta
 *
 *  pre-condicao: Arquivos abertos
 *
 *  retorno: retorna o número da sala caso tenha algum aluno com determinado ra nela, se não retorna 0
 */
int verificar_sala_ra(FILE *sala, int ra, int *pos_sala);
/**
 *  Funcao que verifica a disponilidade do livro para ser emprestado
 *  pre-condicao: arquivos abertos
 *  retorno: retorna 0 se o livro estiver indisponivel para emprestimo ou nao existir, retorna 1 caso contrario
 */
int verificar_livro(FILE* pilha, FILE* livro,int cod, int ra, int pos_sala);
/**
 *  Funcao que imprime o mapa de estantes na tela e as informacoes de suas prateleiras e livros
 *  pre-condicao: arquivos abertos
 *  pos-condicao: mostra o mapa de estantes no console
 */
void imprime_estante(FILE* livro, FILE *estante, FILE *prateleira);
/**
 *  Funcao que loca a sala de estudos para algum aluno
 *  pre-condicao: arquivos abertos
 *  pos-condicao: loca a sala
 */
int locar_sala(FILE* sala, FILE *fila, int ra);

/**
 *  Remove o aluno da sala em que ele esta e libera a sala pra ser usada por outro
 *  pre-condicao: arquivos abertos
 *  pos-condicao: remove aluno da sala
 */
void remover_aluno_sala(FILE *sala, int num_sala, int pos_sala);

/**
 *  Desempilha toda a pilha de livro
 *  pre-condicao: arquivos abertos
 *  pos-condicao: desempilha as pilhas na determinada sala
 */
void desempilhar_pilha(FILE *pilha, FILE *livro);
/**
 *  Ocupa a sala vazia com a fila
 *  pre-condicao: arquivos abertos
 *  pos-condicao: ocupa a sala vazia com alguem da fila
 */
void ocupar_sala_fila(FILE *fila, FILE *sala);

/**
 *  Libera a sala ocupado
 *  pre-condicao: arquivos abertos
 *  pos-condicao: libera a sala ocupada e retira as pilhas de livro e aceita um novo aluno da fila
 *  retorno: retorna 1 se bem sucedido em liberar sala ou 0 se não
 */
int liberar_sala(FILE *sala, FILE *pilha1, FILE *pilha2, FILE *pilha3, FILE *livro, FILE *fila, int ra);

/**
 *  Funcao que imprime o mapa de salas de estudo na tela e as informacoes da pilha de livros emprestados
 *  pre-condicao: arquivos abertos
 *  pos-condicao: mostra o mapa de sala no console
 */
void imprime_mapa_sala(FILE *sala, FILE *livro, FILE *pilha1, FILE *pilha2, FILE *pilha3);
/**
 *  Funcao que imprime a pilha de livros emprestados
 *  pre-condicao: arquivos abertos
 *  pos-condicao: mostra a pilha de livros no console
 */
void imprime_pilha_livro(FILE *pilha, FILE *livro);
/**
 *  Funcao que imprime a fila de espera para salas de estudo
 *  pre-condicao: arquivo aberto
 *  pos-condicao: mostra a fila de espera no console
 */
void imprime_fila(FILE *arq);






#endif /* funcoes_h */
