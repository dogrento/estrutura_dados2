#include "abb.h"


Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
   /* Completar */
   if(a == NULL){
      // aloca espaço
      a = (Arvore*)malloc(sizeof(Arvore));
      // atribui valor ao atributo info e configura suas contiações para NULL
      a->info = v;
      a->esq = NULL;
      a->dir = NULL;
   // se o valor for maior que o info, trabalhar pela direita   
   } else if(v > a->info){
      a->dir = inserir(a->dir, v);
   // se o valor for menor ou igual ao info, trabalhar pela esquerda   
   } else{
      a->esq = inserir(a->esq, v);
   }
   return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
   /* Completar */
   
   return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
   /* Completar */
  
  return 1; 
    
}

//========= Q2 - min =====


//========= Q2 - max =====

//========= Q3 - imprime_decrescente =====


//========= Q4 - maior ramo =====


void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () {

   int i;

   Arvore *a = cria_arvore_vazia ();

   //inserir
   //....

   printf("\n");
   pre_order (a);	
   printf("\n");


   // ====== Q5 ====

   return 0;
}

