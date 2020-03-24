#include <stdio.h>
#include <stdlib.h>


typedef struct node Node;
struct node{
	int valor;
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

void empilha(Pilha *p, int valor) {
	// escreva aqui seu codigo
  Node *ins = (Node*) malloc(sizeof(Node));
  ins->valor = valor;
  ins->prox = p->topo;
  p->topo = ins;
}

int desempilha(Pilha *p) {
	// escreva aqui seu codigo
  Node *aux;
  int r;
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

Pilha* copia_pilha(Pilha *p) {
	// escreva aqui seu codigo
	if(p->topo != NULL{

	}
	return NULL;
}

void imprime_pilha(Pilha *p){
	if(p->topo != NULL){
    printf("%d ", desempilha(p));
		p->topo = p->topo;
		while(p->topo != NULL){
			printf("%d ", desempilha(p));
			p->topo = p->topo;
		}
    printf("\n");
	}
	else{
		printf("Pilha vazia\n");
	}
}

int main(){
	Pilha *teste, *copia;
	int n, m;
	teste = cria_pilha();
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&m);
		empilha(teste, m);
	}
	copia = copia_pilha(teste);
	imprime_pilha(copia);
	imprime_pilha(teste);
	libera_pilha(teste);
	return 0;
}