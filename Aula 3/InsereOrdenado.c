#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* insere_ordenado(Node *vet, int k);
void imprime_lista(Node *lista);

int main() {
	int n, i, valor;
	Node *lst = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &valor);
		lst = insere_ordenado(lst, valor);
	}
	scanf("%d", &valor);
	lst = insere_ordenado(lst, valor);
	imprime_lista(lst);

	return 0;
}

Node* insere_ordenado(Node *lst, int k) {
	// escreva aqui seu código
  Node *aux, *cont, *ins;
  ins = (Node*) malloc(sizeof(Node));
  if(ins != NULL){
    ins->info = k;
    if(lst == NULL){
        ins->prox = NULL;
        return ins;
    }
  }
  aux = lst->prox;
  cont = lst;
  if(k < cont->info){
      ins->prox = lst;
      lst = ins;
      return lst;
  }
  else if(k == cont->info){
      ins->prox = lst;
      lst = ins;
      return lst;
  }
  else if(lst->prox != NULL){
    if(k < cont->info){
      ins->prox = lst;
      lst = ins;
      return lst;
    }
    while(aux != NULL){
      if(k < aux->info){
        cont->prox = ins;
        ins->prox = aux;
        return lst;
      }
      else if(k == aux->info){
        cont->prox = ins;
        ins->prox = aux;
        return lst;
      }
      aux = aux->prox;
      cont = cont->prox;
    }
  }
  cont->prox = ins;
  ins->prox = NULL;
  return lst;
}

void imprime_lista(Node *lista) {
	Node *p = lista;
	if (lista == NULL)
		printf("Lista vazia");
	while (p != NULL) {
		printf(" %d ", p->info);
		p = p->prox;
	}
	printf("\n");
}
