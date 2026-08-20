#include <stdio.h>
#include "produto.h"
#include "interface.h"

int main()
{
    int cadastro_novo = 0;

    while (1)
    {
        int option;
        int last_id = 0;

        home(&option);
        
        switch(option)
        {
            case 1:
            {
                produto_t produto;

                produto.id = last_id;

                printf("Nome: ");
                scanf("%s", &produto.nome);
                //fgets(produto.nome, 50, stdin);

                printf("Preço: ");
                scanf("%f", &produto.preco);

                printf("Quantidade: ");
                scanf("%d", &produto.preco);
                
                if(cadastro_novo != 0)
                {
                    cadastra_produto_novo(produto);
                    cadastro_novo++;
                    last_id++;
                }
                else
                {
                    cadastra_produto()
                }
            }
        }
    }
    
    return 0;
}