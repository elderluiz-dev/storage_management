#include <stdlib.h>
#include <stdio.h>
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

// Passa um ponteiro que vai conter o endereço de outro ponteiro da lista
int cadastra_produto(produto_t **lista_produto, int size_lista, produto_t produto_novo)
{
    if(size_lista < 1) return EXIT_FAILURE;

    produto_t *tmp = realloc(*lista_produto, (size_lista + 1) * sizeof(**lista_produto));
    if (tmp == NULL) return EXIT_FAILURE; //! Tratar o retorno da função de cadastro de produto

    *lista_produto = tmp;

    (*lista_produto)[size_lista] = produto_novo;

    return EXIT_SUCCESS;
}

produto_t busca_produto_id(produto_t *lista_item, int search_id, int size_lista)
{
    produto_t produto_null;
    produto_null.id = -1;
    produto_null.nome = "NULL_STRUCT";

    if(lista_item[size_lista].id == search_id) return lista_item[size_lista];

    if(size_lista < 0) return produto_null;

    return busca_produto_id(lista_item, search_id, size_lista - 1);
}

// Passa o vetor de produtos, o id do produto a ser removido e o tamanho do vetor
void remove_produto(produto_t v[], int id, int tam){
  for(int i = 0; i < tam; i++){
    if(v[i].id == id){
      
      for(int j = i; j < tam; j++){
        v[j] = v[j+1];  
      }
      
      int new_size = tam - 1;
      produto_t *temp = realloc(v, new_size * sizeof(*temp));
      if(temp == NULL){
        printf("Realloc falhou"); // Trata erro de alocação do realloc
        return;
      }else{
        v = temp;
      }
    }
  }
}

// Calcula recursivamente o valor do estoque
float calc_estoque(produto_t vet[], int tam, int i){
  if(tam == i){
    return 0;
  }

  float calc = calc_estoque(vet, tam, i + 1) + vet[i].preco * vet[i].quantidade;
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
