#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"

produto_t *cadastraProdutoNovo(produto_t produto_novo)
{
    produto_t *lista = (produto_t *)malloc(sizeof(*lista));
    if (lista == NULL)
    {
        // Tratar o retorno da função de cadastro de produto novo
        return NULL;
    }

    lista[0] = produto_novo;

    return lista;
}

// Passa um ponteiro que vai conter o endereço de outro ponteiro da lista
ERROR_TYPE_T cadastraProduto(produto_t **lista, int tamanho, produto_t produto_novo)
{
    if(tamanho < 1 || lista == NULL)
    {
        return tamanho_ERROR;
    }

    produto_t *tmp = (produto_t *)realloc(*lista, (tamanho + 1) * sizeof(**lista));
    if (tmp == NULL)
    {
        return ALLOCATION_ERROR;
    }

    *lista = tmp;

    (*lista)[tamanho] = produto_novo;

    return SUCCESS;
}

produto_t buscaProduto(produto_t *lista, unsigned int id, int tamanho)
{
    produto_t produto_null;
    char *null = "NULL_STRUCT";
    strncpy(produto_null.nome, null, sizeof(produto_null.nome) - 1);

    if(lista[tamanho-1].id == id)
    {
        return lista[tamanho-1];
    }

    if(tamanho <= 0)
    {
        return produto_null;
    }

    return buscaProduto(lista, id, tamanho - 1);
}

// Passa o vetor de produtos, o id do produto a ser removido e o tamanho do vetor
ERROR_TYPE_T removeProduto(produto_t **lista, unsigned int id, int *tamanho)
{
    
    for(int i = 0; i < *tamanho; i++)
    {   
        if((*lista)[i].id == id)
        {   
            // Caso especial, onde só há 1 elemento no vetor
            if(*tamanho == 1)
            {
                free(*lista);
                *lista = NULL;
                printf("\nProduto de ID %d removido com sucesso!\n", id);
                *tamanho--;
                return SUCCESS;
            }
        
            // Caso normal
            for(int j = i; j < *tamanho - 1; j++)
            {
                (*lista)[j] = (*lista)[j+1];  
            }
            
            *tamanho--;
            produto_t *temp = (produto_t *)realloc(*lista, *tamanho * sizeof(*temp));
            if(temp == NULL)
            {
                return ALLOCATION_ERROR;
            }

            *lista = temp;
            printf("\nProduto de ID %d removido com sucesso!\n", id);
            return SUCCESS;
        }
      }
    
    printf("\nNão foi encontrado nenhum produto com este ID\n");
    return ID_NOTFOUND;
} 

// Calcula recursivamente o valor do estoque
float calculaEstoque(produto_t *lista, int tamanho, int base)
{
  if(tamanho == base)
  {
      return 0;
  }

  return calculaEstoque(lista, tamanho, base + 1) + lista[base].preco * lista[base].quantidade;;
}

void listaProdutos(produto_t *lista, int tamanho, int base)
{
    if(base == tamanho) return;

    if(base == 0)
    {
        printf("\nProdutos cadastrados: ");
    }

    printf("\nid: %d\n", lista[base].id);
    printf("produto: %s\n", lista[base].nome);
    printf("preco: %.2f\n", lista[base].preco);
    printf("quantidade: %d\n", lista[base].quantidade);

    listaProdutos(lista, tamanho, base + 1);
}

void ordenaLista(produto_t *lista, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < tamanho; j++)
        {
            produto_t aux;

            if (lista[i].preco < lista[j].preco)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

// Passa um vetor de vetores dinâmicos para a limpeza 
void encerraPrograma(produto_t **listas, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        free(listas[i]);
        listas[i] = NULL;
    }
}