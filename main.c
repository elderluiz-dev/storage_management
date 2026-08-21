#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "interface.h"

int main()
{  
    produto_t *lista_produto;
    int id = 1;
    int qty_lista = 0;
    int cadastro_novo = 0;

    while (1)
    {
        int option = home();
        
        switch(option)
        {
            case 1:
            {
                produto_t produto_novo = {};

                printf("\nPreencha as informações abaixo: \n");
                printf("Nome do item: ");

                while (getchar() != '\n' && getchar() != EOF); 
                fgets(produto_novo.nome, sizeof(produto_novo.nome), stdin);
                produto_novo.nome[strcspn(produto_novo.nome, "\n")] = '\0';

                printf("Preço: ");
                scanf("%f", &produto_novo.preco);
                
                printf("Quantidade: ");
                scanf("%d", &produto_novo.quantidade);

                produto_novo.id = id;

                if(cadastro_novo == 0)
                {
                    lista_produto = cadastraProdutoNovo(produto_novo);

                    qty_lista++;
                    cadastro_novo = 1;
                    id++;
                }
                else
                {
                    ERROR_TYPE_T err = cadastraProduto(&lista_produto, qty_lista, produto_novo);
                    if(err == ALLOCATION_ERROR)
                    {
                        printf("Não foi possível alocar o novo produto: Erro de alocação na memória.\n");
                        break;
                    }
                    else if(err == tamanho_ERROR)
                    {
                        printf("Não foi possível alocar o novo produto: Tamanho de vetor inválido ou endereço nulo.\n");
                        break;
                    }

                    qty_lista++;
                    id++;
                }

                break;
            }
            case 2:
            {
                int remv_id;

                if(qty_lista == 0)
                {
                    printf("\nNenhum produto cadastrado.\n");
                    break;
                }
            
                printf("Digite o ID do produto a ser removido: ");
                scanf("%d", &remv_id);
          
                if(qty_lista == 1)
                {
                    cadastro_novo = 0;
                }
                
                removeProduto(&lista_produto, remv_id, &qty_lista);
                break;
            }
            case 3:
            {
                if(qty_lista != 0)
                {
                    limpaTerminal();
                    listaProdutos(lista_produto, qty_lista, 0);
                    break;
                }

                limpaTerminal();
                printf("\nNenhum item cadastrado!\n");
                break;
            }
            case 4:
            {
                if(lista_produto == NULL)
                {
                    limpaTerminal();
                    printf("\nNenhum item cadastrado!\n");
                    break;
                }

                unsigned int id;
                
                printf("Digite o id: ");
                scanf("%u", &id);

                produto_t lista_buscada = buscaProduto(lista_produto, id, qty_lista);
                
                if(strcmp(lista_buscada.nome, "NULL_STRUCT") == 0)
                {
                    limpaTerminal();
                    printf("Item não encontrado!\n");
                    break;
                }
                else
                {
                    limpaTerminal();
                    printf("\n=== Item encontrada ===\n");
                    printf("Id: %u\n", lista_buscada.id);
                    printf("Nome: %s\n", lista_buscada.nome);
                    printf("Preço: %.2f\n", lista_buscada.preco);           
                    printf("Quantidade: %d\n", lista_buscada.quantidade);
                    
                    break;
                }

                break;
            }
            case 5:
            {
                if(qty_lista == 0)
                {
                    limpaTerminal();
                    printf("\nNenhum item cadastrado!\n");
                    break;
                }

                limpaTerminal();
                printf("\nLista ordenada com sucesso!\n");
                ordenaLista(lista_produto, qty_lista);
                break;
            }
            
            case 6:
            {
              limpaTerminal();
              printf("\nValor total do estoque: R$ %.2f\n", calculaEstoque(lista_produto, qty_lista, 0));
              break;
            }

            case 7:
            {
                produto_t *lista_free[] = {lista_produto};
                encerraPrograma(lista_free, 1);
             
                printf("\nPrograma encerrado pelo usuário.\n");
                return 0;
            }

            default:
            {
                limpaTerminal();
                printf("Opção inválida!\n");
                break;
            }
        }
    }
        
    return 0;
}
