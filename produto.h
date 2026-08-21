#pragma once

typedef struct {
    unsigned int id;
    char nome[50];
    float preco;
    int quantidade;
} produto_t;

typedef enum {
    SUCCESS,
    ALLOCATION_ERROR,
    ID_NOTFOUND,
    tamanho_ERROR
} ERROR_TYPE_T;

produto_t *cadastraProdutoNovo(produto_t produto_novo);

ERROR_TYPE_T cadastraProduto(produto_t **lista, int tamanho, produto_t produto_novo);

produto_t buscaProduto(produto_t *lista, unsigned int id, int tamanho);

ERROR_TYPE_T removeProduto(produto_t **lista, unsigned int id, int *tamanho);

float calculaEstoque(produto_t *lista, int tamanho, int base);

void listaProdutos(produto_t *lista, int tamanho, int base);

void ordenaLista(produto_t *lista, int tamanho);

void encerraPrograma(produto_t **listas, int tamanho);
