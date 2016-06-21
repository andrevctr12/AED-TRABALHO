/**
 * Autores: Andre Victor e Khadije El Zein
 */


 #ifndef arquivos_h
 #define arquivos_h
 
 #include <stdio.h>
 #include "estruturas.h"
 #include "inserir_arquivo.h"
 
 /**
 *  Funcao que inicializa o arquivo sala de estudos
 *  pre-condicao:Arquivo precisa estar aberto
 *  pos-condicao:nenhuma
 */
void inicializacao_sala_fila_pilha(FILE *sala, FILE *fila, FILE *pilha1, FILE *pilha2, FILE *pilha3);

/**
 *  Funcao que cria uma lista vazia de determinada lista, modificando seu cabeçalho
 *  pre-condicao:Arquivo precisa estar aberto
 *  pos-condicao:nenhuma
 */
void cria_lista_vazia(FILE* arq);

/**
 *  Funcao que cria uma fila vazia, modificando seu cabeçalho
 *  pre-condicao:Arquivo precisa estar aberto
 *  pos-condicao:nenhuma
 */
void cria_fila_vazia(FILE *arq);

/**
 *  funcao que remove espaço no inicio da string
 *  pre-condicao: nenhuma
 *  pos-condicao:retorna a string sem o espaço no inicio
 */
char* remover_espaco(char *s);


/**
 *  funcao que carrega os dados do arquivo informado com determinado tipo de sintaxe
 *  pre-condicao: arquivos precisam estar abertos
 *  pos-condicao: dados sao carregados no arquivo
 */
void carregar_arquivos(FILE *info, FILE *estante, FILE *prateleira, FILE *livro);



#endif /* arquivos_h */
