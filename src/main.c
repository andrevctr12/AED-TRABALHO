/**
 *@authors Andre Victor e Khadije El Zein
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
/**
 * @brief verifica se arquivo pode ser aberto
 * @param caminho caminho para chegar no arquivo
 * @param tipo_abertura tipo de abertura
 * @return arquivo
 */
FILE* verificar_arquivo(char *caminho, char *tipo_abertura) {
    FILE *f;
    if((f = fopen(caminho, tipo_abertura)) == NULL) {
        printf("Arquivo com falha na abertura");
        exit(0);
    }
    return f;
}

/**
 * @brief menu
 */
void menu() {
    FILE *info = verificar_arquivo("info.txt", "r");
    FILE *estante = verificar_arquivo("estante", "w+b");
    FILE *prateleira = verificar_arquivo("prateleira", "w+b");
    FILE *livro = verificar_arquivo("livro", "w+b");
    FILE *sala = verificar_arquivo("sala", "w+b");
    FILE *fila = verificar_arquivo("fila", "w+b");
    FILE *pilha1 = verificar_arquivo("pilha1", "w+b");
    FILE *pilha2= verificar_arquivo("pilha2", "w+b");
    FILE *pilha3 = verificar_arquivo("pilha3", "w+b");
    FILE *usuario;
    
    inicializacao_sala_fila_pilha(sala, fila, pilha1, pilha2, pilha3);
    carregar_arquivos(info, estante, prateleira, livro);
    fclose(info);
    int op = -1;
    int cod, ra;
    char titulo[MAX], autor[MAX];
    int num_prat, num_est;
    char *caminho;
    while (op != 10) {
        printf("\n[0]Carregar arquivo de inicialização\n");
        printf("[1]Inserir livro\n");
        printf("[2]Retirar livro\n");
        printf("[3]Busca endereço do livro\n");
        printf("[4]Locar sala\n");
        printf("[5]Emprestar livro\n");
        printf("[6]Liberar sala\n");
        printf("[7]Imprimir mapa de estantes\n");
        printf("[8]Imprimir mapa de salas\n");
        printf("[9]Imprimir fila de espera da sala\n");
        printf("[10]Sair\n");
        printf("> ");
        scanf("%d",&op);
        switch(op)
        {
            case 0:
                printf("Qual o caminho do arquivo texto?\n> ");
                scanf("%s", caminho);
                usuario = verificar_arquivo(caminho, "r");
                carregar_arquivos(usuario, estante, prateleira, livro);
                fclose(usuario);
                break;
            case 1:
                printf("Qual o codigo do livro?\n> ");
                scanf("%d", &cod);
                printf("Qual o titulo do livro?\n> ");
                gets(titulo);
                printf("Qual o autor do livro?\n> ");
                gets(autor);
                printf("Qual a estante do livro?\n> ");
                scanf("%d", &num_est);
                printf("Qual a prateleira do livro?\n> ");
                scanf("%d", &num_prat);
                if(inserir_livro_prat(livro, prateleira, cod, autor, titulo, num_prat, num_est))
                    printf("Livro inserido com sucesso!\n");
                else
                    printf("Livro já existente ou prateleira/estante não existe\n");
                break;
            case 2:
                printf("Qual o codigo do livro a ser retirado?\n> ");
                scanf("%d", &cod);
                retirar_livro(cod, livro, prateleira);
                break;
            case 3:
                printf("Qual o codigo do livro?\n> ");
                scanf("%d", &cod);
                int prat, est, pos;
                if (busca_end_livro(livro, cod, &est, &prat, &pos) != -1) {
                    printf("Estante: %d\n", est);
                    printf("Prateleira: %d\n", prat);
                }
                else
                    printf("Livro indisponível");
                break;
            case 4:
                printf("Insira o RA do aluno:\n> ");
                scanf("%d", &ra);
                int num;
                if((num = locar_sala(sala, fila, ra)))
                    printf("Sala %d locada\n", num);
                else printf("Aluno na Lista de espera\n");
                break;
            case 5:
                printf("Insira o RA do aluno:\n> ");
                scanf("%d", &ra);
                printf("Qual o codigo do livro a ser emprestado?\n> ");
                scanf("%d", &cod);
                if(emprestar_livro(pilha1, pilha2, pilha3, sala, livro, cod, ra)) {
                    printf("Livro %d Emprestado com sucesso para RA: %d\n", cod, ra);
                }
                break;
            case 6:
                printf("Insira o RA do aluno:\n> ");
                scanf("%d", &ra);
                if(liberar_sala(sala, pilha1, pilha2, pilha3, livro, fila, ra)) {
                    printf("Sala liberada!\n");
                }
                else {
                    printf("Não foi possível liberar a sala :(\n");
                }
                break;
            case 7:
                imprime_estante(livro, estante, prateleira);
                break;
            case 8:
                imprime_mapa_sala(sala, livro, pilha1, pilha2, pilha3);
                break;
            case 9:
                imprime_fila(fila);
                break;
            case 10:
                fclose(livro);
                fclose(estante);
                fclose(prateleira);
                fclose(sala);
                fclose(fila);
                fclose(pilha1);
                fclose(pilha2);
                fclose(pilha3);
                
        }
        
    }
}
/**
 * @brief programa principal
 * @return 0 ao final
 */
int main()
{
    menu();
    return 0;
}
