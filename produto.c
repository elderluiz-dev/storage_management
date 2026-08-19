#include "produto.h"
#include <stdlib.h>
#include <stdio.h>

int remove_produto(produto_t v[], int id, int tam){
  for(int i = 0; i < tam; i++){
    if(v[i].id == id){
      
      for(int j = i; j < tam; j++){
        v[j] = v[j+1];  
      }
      
      int new_size = tam - 1;
      produto_t *temp = realloc(v, new_size * sizeof(*temp));
      if(temp == NULL){
        printf("Realloc falhou");
        return 1;
      }else{
        v = temp;
      }
      
      return 0;
    }
  }
  
  return -1;
}
