#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int home(){
    int option;

    printf("\n=== Sistema de Estoque ===\n");
    printf("\nDIGITE A OPÇÃO QUE DESEJA\n");
    printf("1. Cadastrar produto\n");
    printf("2. Remover produto\n");
    printf("3. Listar produtos\n");
    printf("4. Buscar produtos\n");
    printf("5. Ordenar produtos\n");
    printf("6. Sair\n");

    printf("> ");
    scanf("%d", &option);

    return option;
}

void limpa_terminal()
{
    system("clear");
}