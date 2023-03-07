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
int pertence_arv(Arvore *a, char c){
   if(a==NULL){
      return 0;
   }
   else if(a->info == c){
      return 1;
   } else{
      return pertence_arv(a->esq, c) || pertence_arv(a->dir, c);
   }
}

//========= Exercício 4 - conta nós ====
int conta_nos(Arvore *a){
   if(a==NULL){
      return 0;
   }
   return 1 + conta_nos(a->esq) + conta_nos(a->dir);
}


//========= Exercício 5 - calcula altura ====
int calcula_altura_arvore(Arvore *a){
   if(a == NULL){
      return -1;
   } else {
      int altura_esq = calcula_altura_arvore(a->esq);
      int altura_dir = calcula_altura_arvore(a->dir);
      if(altura_esq > altura_dir){
         return altura_esq + 1;
      } else {
         return altura_dir + 1;
      }
   }
}



//========= Exercício 6 - conta folhas ====
int conta_nos_folha(Arvore *a){
   if(a==NULL){
      return 0;
   } else if(a->esq == NULL && a->dir == NULL){
      return 1;
   }
   return conta_nos_folha(a->esq) + conta_nos_folha(a->dir);
}


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
   printf("\n");
   int ex3 = pertence_arv(a, 'z');
   printf("%d", ex3);
   printf("\n");
   int qtn_nos = conta_nos(a);
   printf("%d\n", qtn_nos);
   int alt_nos = calcula_altura_arvore(a);
   printf("%d\n", alt_nos);
   int nos_folha = conta_nos_folha(a);
   printf("%d\n", nos_folha);

   arv_libera (a);

   return 0;
}

