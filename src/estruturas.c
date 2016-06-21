/**
 *@authors Andre Victor e Khadije El Zein
 */

#include "estruturas.h"
#include <stdlib.h>

/**
 * @brief le cabecalho do arquivo
 * @param arq arquivo
 * @return  cabecalho
 */
cabecalho* le_cabecalho(FILE * arq) {
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    fseek(arq,0,SEEK_SET);
    fread(cab,sizeof(cabecalho),1,arq);
    return cab;
}
/**
 * @brief escreve cabecalho do arquivo
 * @param arq arquivo
 * @param cab cabecalho
 */
void escreve_cabecalho(FILE* arq, cabecalho* cab){
    fseek(arq,0,SEEK_SET);
    fwrite(cab,sizeof(cabecalho),1,arq);
}

/**
 * @brief le cabecalho do tipo fila
 * @param arq arquivo
 * @return cabecalho
 */
cab_fila* le_cab_fila(FILE * arq) {
    cab_fila * cab = (cab_fila*) malloc(sizeof(cab_fila));
    fseek(arq,sizeof(cabecalho),SEEK_SET);
    fread(cab,sizeof(cab_fila),1,arq);
    return cab;
}
/**
 * @brief escreve cabecalho do tipo fila
 * @param arq arquivo
 * @param cab cabecalho
 */
void escreve_cab_fila(FILE* arq, cab_fila* cab){
    fseek(arq,sizeof(cabecalho),SEEK_SET);
    fwrite(cab,sizeof(cab_fila),1,arq);
}
/**
 * @brief le livro do arquivo
 * @param arq arquivo
 * @param pos posicao
 * @return struct livro
 */
Livro* le_livro(FILE* arq, int pos) {
    Livro* x = malloc(sizeof(Livro));
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Livro),SEEK_SET);
    fread(x,sizeof(Livro),1,arq);
    return x;
}
/**
 * @brief escreve livro no arquivo
 * @param arq arquivo
 * @param x livro
 * @param pos posicao
 */
void escreve_livro(FILE* arq, Livro* x, int pos) {
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Livro),SEEK_SET);
    fwrite(x,sizeof(Livro),1,arq);
}
/**
 * @brief le prateleira do arquivo
 * @param arq arquivo
 * @param pos posicao
 * @return struct prateleira
 */
Prateleira* le_prateleira(FILE* arq, int pos) {
    Prateleira* x = malloc(sizeof(Prateleira));
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Prateleira),SEEK_SET);
    fread(x,sizeof(Prateleira),1,arq);
    return x;
}
/**
 * @brief escreve prateleira no arquivo
 * @param arq arquivo
 * @param x prateleira
 * @param pos posicao
 */
void escreve_prateleira(FILE* arq, Prateleira* x, int pos) {
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Prateleira),SEEK_SET);
    fwrite(x,sizeof(Prateleira),1,arq);
}

/**
 * @brief le estante do arquivo
 * @param arq arquivo
 * @param pos posicao
 * @return struct estante
 */
Estante* le_estante(FILE* arq, int pos) {
    Estante* x = malloc(sizeof(Estante));
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Estante),SEEK_SET);
    fread(x,sizeof(Estante),1,arq);
    return x;
}

/**
 * @brief escreve estante no arquivo
 * @param arq arquivo
 * @param x estante
 * @param pos posicao
 */
void escreve_estante(FILE* arq, Estante* x, int pos) {
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Estante),SEEK_SET);
    fwrite(x,sizeof(Estante),1,arq);
}
/**
 * @brief le sala de estudos do arquivo
 * @param arq arquivo
 * @param pos posicao
 * @return struct sala de estudos
 */
Sala* le_sala(FILE* arq, int pos) {
    Sala* x = malloc(sizeof(Sala));
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Sala),SEEK_SET);
    fread(x,sizeof(Sala),1,arq);
    return x;
}
/**
 * @brief escreve sala de estudos no arquivo
 * @param arq arquivo
 * @param x sala de estudos
 * @param pos posicao
 */
void escreve_sala(FILE* arq, Sala* x, int pos) {
    fseek(arq,sizeof(cabecalho) + pos*sizeof(Sala),SEEK_SET);
    fwrite(x,sizeof(Sala),1,arq);
}

/**
 * @brief le fila de espera do arquivo
 * @param arq arquivo
 * @param pos posicao
 * @return struct fila de espera
 */
Fila* le_fila(FILE* arq, int pos) {
    Fila* x = malloc(sizeof(Fila));
    fseek(arq,sizeof(cabecalho) + sizeof(cab_fila) + pos*sizeof(Fila),SEEK_SET);
    fread(x,sizeof(Fila),1,arq);
    return x;
}
/**
 * @brief escreve fila de espera no arquivo
 * @param arq arquivo
 * @param x fila de espera
 * @param pos posicao
 */
void escreve_fila(FILE* arq, Fila* x, int pos) {
    fseek(arq,sizeof(cabecalho) + sizeof(cab_fila) + pos*sizeof(Fila),SEEK_SET);
    fwrite(x,sizeof(Fila),1,arq);
}
/**
 * @brief le pilha de livros do arquivo
 * @param arq arquivo
 * @param pos posicao
 * @return struct pilha de livros
 */
Pilha_Livro* le_pilha(FILE* arq, int pos) {
    Pilha_Livro* x = malloc(sizeof(Pilha_Livro));
    fseek(arq,sizeof(cabecalho) + sizeof(cab_fila) + pos*sizeof(Pilha_Livro),SEEK_SET);
    fread(x,sizeof(Pilha_Livro),1,arq);
    return x;
}
/**
 * @brief escreve pilha de livros no arquivo
 * @param arq arquivo
 * @param x pilha de livros
 * @param pos posicao
 */
void escreve_pilha(FILE* arq, Pilha_Livro* x, int pos) {
    fseek(arq,sizeof(cabecalho) + sizeof(cab_fila) + pos*sizeof(Pilha_Livro),SEEK_SET);
    fwrite(x,sizeof(Pilha_Livro),1,arq);
}
