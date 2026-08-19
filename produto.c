#include <stdlib.h>
#include "produto.h"

produto_t *cadastra_produto_novo(produto_t produto_novo)
{
    produto_t *lista_produto = (produto_t *)malloc(sizeof(*lista_produto));
    if (lista_produto == NULL)
    {
        // Tratar o retorno da função de cadastro de produto novo
        return NULL;
    }
    
    return lista_produto;
}

int cadastra_produto(produto_t *lista_produto, int size_lista, produto_t produto_novo)
{
    if(size_lista < 1) return EXIT_FAILURE;

    produto_t *tmp = realloc(lista_produto, (size_lista + 1) * sizeof(*lista_produto));
    if (lista_produto == NULL) return EXIT_FAILURE; // Tratar o retorno da função de cadastro de produto

    tmp = lista_produto;

    lista_produto[size_lista] = produto_novo;

    return EXIT_SUCCESS;
}