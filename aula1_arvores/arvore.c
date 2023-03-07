#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}
void print_arvore(Arvore *raiz, int level){
   if(raiz != NULL){
      print_arvore(raiz->dir, level+1);
      printf("\n");
      for(int i = 0; i < level;i++){
         printf(" ");
      }
      printf("%c--|", raiz->info);
      print_arvore(raiz->esq, level+1);
   }
}
//========= Exercício 2 - pré-ordem (RED)====
void pre_ordem(Arvore *raiz){
   if(raiz != NULL){
      printf("%c",raiz->info);
      pre_ordem(raiz->esq);
      pre_ordem(raiz->dir);
   }
}


//========= Exercício 2 - in-ordem(ERD) ====
void in_ordem(Arvore *raiz){
   if(raiz != NULL){
      in_ordem(raiz->esq);
      printf("%c", raiz->info);
      in_ordem(raiz->dir);
   }
}


//========= Exercício 2 - pós-ordem EDR====
void pos_ordem(Arvore *raiz){
   if(raiz!=NULL){
      pos_ordem(raiz->esq);
      pos_ordem(raiz->dir);
      printf("%c", raiz->info);
   }
}   


//========= Exercício 3 - pertence ====


//========= Exercício 4 - conta nós ====


//========= Exercício 5 - calcula altura ====



//========= Exercício 6 - conta folhas ====



int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	
   //print_arvore(a,0);
   //pre_ordem(a);
   //in_ordem(a);
   pos_ordem(a);

   arv_libera (a);

   return 0;
}

