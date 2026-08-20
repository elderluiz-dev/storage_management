#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"

produto_t *cadastra_produto_novo(produto_t produto_novo)
{
    produto_t *lista_produto = (produto_t *)malloc(sizeof(*lista_produto));
    if (lista_produto == NULL)
    {
        // Tratar o retorno da função de cadastro de produto novo
        return NULL;
    }

    lista_produto[0] = produto_novo;

    return lista_produto;
}

// Passa um ponteiro que vai conter o endereço de outro ponteiro da lista
int cadastra_produto(produto_t **lista_produto, int size_lista, produto_t produto_novo)
{
    if(size_lista < 1 || lista_produto == NULL)
    {
        return EXIT_FAILURE;
    }

    produto_t *tmp = (produto_t *)realloc(*lista_produto, (size_lista + 1) * sizeof(**lista_produto));
    if (tmp == NULL)
    {
        //! Tratar o retorno da função de cadastro de produto
        return EXIT_FAILURE;
    }

    *lista_produto = tmp;

    (*lista_produto)[size_lista] = produto_novo;

    return EXIT_SUCCESS;
}

produto_t busca_produto_id(produto_t *lista_lista_item, unsigned int search_id, int size_lista)
{
    produto_t produto_null;
    char *null = "NULL_STRUCT";
    strncpy(produto_null.nome, null, sizeof(produto_null.nome) - 1);

    if(lista_lista_item[size_lista-1].id == search_id)
    {
        return lista_lista_item[size_lista-1];
    }

    if(size_lista <= 0)
    {
        return produto_null;
    }

    return busca_produto_id(lista_lista_item, search_id, size_lista - 1);
}

// Passa o vetor de produtos, o id do produto a ser removido e o size_lista do vetor
ERROR_TYPE_T remove_produto(produto_t **lista_lista_item, int id, int *size_lista)
{
    
    for(int i = 0; i < *size_lista; i++)
    {   
        if((*lista_lista_item)[i].id == id)
        {   
            // Caso especial, onde só há 1 elemento no vetor
            if(*size_lista == 1)
            {
                free(*lista_lista_item);
                *lista_lista_item = NULL;
                printf("\nProduto de ID %d removido com sucesso!\n", id);
                *size_lista -= 1;
                return SUCCESS;
            }
        
        
            // Caso normal
            for(int j = i; j < *size_lista - 1; j++)
            {
                (*lista_lista_item)[j] = (*lista_lista_item)[j+1];  
            }
            
            *size_lista -= 1;
            produto_t *temp = (produto_t *)realloc(*lista_lista_item, *size_lista * sizeof(*temp));
            if(temp == NULL)
            {
                return ALLOCATION_ERROR;
            }

            *lista_lista_item = temp;
            printf("Produto de ID %d removido com sucesso!", id);
            return SUCCESS;
        }
      }
    
    printf("Não foi encontrado nenhum produto com este ID");
    return SUCCESS;
} 

// Calcula recursivamente o valor do estoque
float calc_estoque(produto_t *lista_lista_item, int size_lista, int i)
{
  if(size_lista == i)
  {
      return 0;
  }

  float calc = calc_estoque(lista_lista_item, size_lista, i + 1) + lista_lista_item[i].preco * lista_lista_item[i].quantidade;
  return calc;
}

// Passa um vetor estático de vetores dinâmicos para a limpeza 
void encerra_programa(produto_t **listas, int size_listas)
{
    for(int i = 0; i < size_listas; i++)
    {
        free(listas[i]);
        listas[i] = NULL;
    }
}

void listar_produto(produto_t *lista_item, int size_lista, int base)
{
    if(base == size_lista) return;
    if(base == 0) printf ("\nProdutos cadastrados: ");

    printf("\nid: %d\n", lista_item[base].id);
    printf("produto: %s\n", lista_item[base].nome);
    printf("preco: %.2f\n", lista_item[base].preco);
    printf("quantidade: %d\n", lista_item[base].quantidade);

    listar_produto(lista_item, size_lista, base + 1);
}

void ordenacao(produto_t *lista_item, int size_lista)
{
    for(int i = 0; i < size_lista; i++)
    {
        for(int j = 0; j < size_lista; j++)
        {
            produto_t aux;

            if (lista_item[i].preco < lista_item[j].preco)
            {
                aux = lista_item[i];
                lista_item[i] = lista_item[j];
                lista_item[j] = aux;
            }
        }
    }
}
