#include <stdio.h>
#include <stdlib.h>


typedef struct node Node;
struct node{
	char valor;
	Node* prox;
};

typedef struct Pilha{
	Node *topo;
}Pilha;

Pilha* cria_pilha () {
	// escreva aqui seu codigo
  Pilha *p = (Pilha*) malloc(sizeof(Pilha));
  p->topo = NULL;

  return p;
}

int pilha_vazia (Pilha *p) {
	// escreva aqui seu codigo
  return (p->topo == NULL);
}

void empilha(Pilha *p, char valor) {
	// escreva aqui seu codigo
  Node *ins = (Node*) malloc(sizeof(Node));
  ins->valor = valor;
  ins->prox = p->topo;
  p->topo = ins;
}

char desempilha(Pilha *p) {
	// escreva aqui seu codigo
  Node *aux;
  char r;
  if(p->topo != NULL){
    aux = p->topo;
    p->topo = aux->prox;
    r = aux->valor;
    free(aux);
    return r;
  }
  else{
      printf("Pilha vazia\n");
      exit(1);
  }
}

void libera_pilha(Pilha *p) {
	// escreva aqui seu codigo
  free(p);
}

void imprime_pilha(Pilha *p){
	if(p->topo != NULL){
    printf("%c ", desempilha(p));
		p->topo = p->topo;
		while(p->topo != NULL){
			printf("%c ", desempilha(p));
			p->topo = p->topo;
		}
    printf("\n");
	}
	else{
		printf("Pilha vazia\n");
	}
}

Pilha* copia_pilha(Pilha *p) {
	// escreva aqui seu codigo
  Pilha *copia = (Pilha*) malloc(sizeof(Pilha));
  Pilha *copia2 = (Pilha*) malloc(sizeof(Pilha));
  int c;
  Node *aux;
	if(p->topo != NULL){
    aux = p->topo;
    while(aux != NULL){
      empilha(copia2, aux->valor);
      aux = aux->prox;
    }
    while(copia2->topo != NULL){
      c = desempilha(copia2);
      empilha(copia, c);
     copia2->topo = copia2->topo;
    }
    free(copia2);
    free(aux);
    return copia;
	}
  copia->topo = NULL;
  return copia;
}

int palindromo(Pilha *p) {
	// escreva aqui seu codigo
    Pilha *copia = copia_pilha(p);
    Pilha *copia2 = (Pilha*) malloc(sizeof(Pilha));
    Node *aux;
	if(copia->topo != NULL){
    aux = copia->topo;
    while(aux != NULL){
        empilha(copia2, aux->valor);
        aux = aux->prox;
    }
    while(copia->topo != NULL && copia2->topo != NULL){
        if(copia->topo-> valor != copia2->topo->valor){
            free(copia);
            free(copia2);
            return 0;
        }
    }
    free(copia);
    free(copia2);
    return 1;
  }
  return 0;
}

int main(){
	Pilha *teste, *copia;
	int n;
  char m;
	teste = cria_pilha();
	scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf(" %c",&m);
    empilha(teste, m);
  }
  imprime_pilha(teste);
	printf("%d\n", palindromo(teste));
	libera_pilha(teste);
	return 0;
}