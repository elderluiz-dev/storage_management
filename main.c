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

                while (getchar() != '\n' && getchar() != EOF); 
                printf("\nPreencha as informações abaixo: \n");
                printf("Nome do item: ");
                fgets(produto_novo.nome, sizeof(produto_novo.nome), stdin);
                produto_novo.nome[strcspn(produto_novo.nome, "\n")] = '\0';

                printf("Preço: ");
                scanf("%f", &produto_novo.preco);
                
                printf("Quantidade: ");
                scanf("%d", &produto_novo.quantidade);

                produto_novo.id = id;

                if(cadastro_novo == 0)
                {
                    lista_produto = cadastra_produto_novo(produto_novo);

                    qty_lista++;
                    cadastro_novo = 1;
                    id++;
                }
                else
                {
                    cadastra_produto(&lista_produto, qty_lista, produto_novo);
                    
                    qty_lista++;
                    id++;
                }

                break;
            }
            case 2:
            {
            int remv_id;
            
            printf("Digite o ID do item a ser removido: ");
            scanf("%d", &remv_id);
          
          
            if(qty_lista == 1)
            {
                cadastro_novo = 0;
                limpa_terminal();
                remove_produto(&lista_produto, remv_id, qty_lista);
                qty_lista--;
            }else
            {
                limpa_terminal();
                remove_produto(&lista_produto, remv_id, qty_lista);
                qty_lista--;
            }
            break;
            }
            case 3:
            {
                if(qty_lista != 0)
                {
                    limpa_terminal();
                    listar_produto(lista_produto, qty_lista, 0);
                    break;
                }

                limpa_terminal();
                printf("\nNenhum item cadastrado!\n");
                break;
            }
            case 4:
            {
                if(lista_produto == NULL)
                {
                    limpa_terminal();
                    printf("\nNenhum item cadastrado!\n");
                    break;
                }

                unsigned int id;
                
                limpa_terminal();
                printf("Digite o id: ");
                scanf("%u", &id);

                produto_t lista_buscada = busca_produto_id(lista_produto, id, qty_lista);
                
                if(strcmp(lista_buscada.nome, "NULL_STRUCT") == 0)
                {
                    limpa_terminal();
                    printf("Item não encontrado!\n");
                    break;
                }
                else
                {
                    limpa_terminal();
                    printf("\n=== Item encontrada ===\n");
                    printf("Id: %u\n", lista_buscada.id);
                    printf("Nome: %s\n", lista_buscada.nome);
                    printf("Preço: %f\n", lista_buscada.preco);           
                    printf("Quantidade: %d\n", lista_buscada.quantidade);
                    
                    break;
                }

                break;
            }
            case 5:
            {
                if(qty_lista == 0)
                {
                    limpa_terminal();
                    printf("\nNenhum item cadastrado!\n");
                    break;
                }

                limpa_terminal();
                printf("\nLista ordenada com sucesso!\n");
                ordenacao(lista_produto, qty_lista);
                break;
            }

            case 6:
            {
                produto_t *lista_free[] = {lista_produto};
                encerra_programa(lista_free, 1);
             
                printf("\nPrograma encerrado pelo usuário.\n");
                return 0;
            }

            default:
            {
                limpa_terminal();
                printf("Opção inválida!\n");
                break;
            }
        }
    }
        
    return 0;
}
