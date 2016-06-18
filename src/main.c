#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"

void menu() {
	FILE *info = NULL;
	FILE *estante = NULL;
	FILE *prateleira = NULL;
	FILE *livro = NULL;
    abrir_arquivo_leitura(info, "info.txt");
    abrir_arquivo_escrita(estante, "estante");
    abrir_arquivo_escrita(prateleira, "prateleira");
    abrir_arquivo_escrita(livro, "livro");
    int op = -1;
    while (op != 10) {
        printf("[0]Carregar arquivo de inicialização\n");
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
                carregar_arquivos(info, estante, prateleira, livro);
                break;
            case 1:
                printf("funcao1");
                break;
            case 2:
                printf("funcao2");
                break;
            case 3:
                printf("funcao3");
                break;
            case 4:
                printf("funcao4");
                break;
            case 5:
                printf("funcao5");
                break;
            case 6:
                printf("funcao6");
                break;
            case 7:
                printf("funcao7");
                break;
            case 8:
                printf("funcao8");
                break;
            case 9:
                printf("funcao9");
                break;
        }
        system("clear");
    }
}

int main()
{
    menu();
    return 0;
}
