#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *ant;
	Node *prox;
};

int lista_vazia(Node *lista);
Node* inclui_fim(Node *lista, int x);
void imprime_lista(Node *lista);
Node* soma_listas(Node *lst1, Node *lst2);

int main() {
	int n, i, valor;
	Node *l1 = NULL;
	Node *l2 = NULL;
	Node *l3 = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &valor);
		l1 = inclui_fim(l1, valor);
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &valor);
		l2 = inclui_fim(l2, valor);
	}
	l3 = soma_listas(l1, l2);
	imprime_lista(l3);

	return 0;
}

int lista_vazia(Node *lista) {
	return (lista == NULL);
}

Node* soma_listas(Node *lst1, Node *lst2) {
	// escreva aqui seu código
    Node *soma, *ins;
    Node *aux1 = lst1, *aux2 = lst2, *aux1r, *aux2r;
    int cont1 = 0, cont2 = 0, a;
    if(lst1 == NULL && lst2 == NULL){
    }
    else if(lst1 == NULL || lst2 == NULL){
        if(lst1 == NULL){
            soma = lst2;
            return soma;
        }
        else{
            soma = lst1;
            return soma;
        }
    }
    else{
        soma = (Node *) malloc(5000*sizeof(Node));
        ins = (Node *) malloc(sizeof(Node));
        while(aux1->prox == NULL || aux2->prox == NULL){
            if(aux1 != NULL && aux2 != NULL){
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }
            else{
                if(aux1 == NULL){
                    aux2 = aux2->prox;
                    cont2++; 
                }
                else{
                    aux1 = aux1->prox;
                    cont1++; 
                }
            }
        }
        soma = lst1;
        aux1r = aux1->ant;
        aux2r = aux2->ant;
        while(soma->prox != NULL){
            soma = soma->prox;
        }
      if(aux1 != NULL && aux2 != NULL && cont1 == 0 && cont2 == 0){
        while(aux1r != NULL && aux2r != NULL){
          if(aux1->info + aux2->info < 10){
            ins->info = aux1->info + aux2->info;
            ins->prox = NULL;
            if(soma == NULL){
              soma->info = ins->info;
              soma->ant = ins->prox;
            }
            else{
              soma->ant = ins;
            }
          }
          else{
            ins->info = (aux1->info + aux2->info)%10;
            ins->prox = NULL;
            if(soma == NULL){
              soma->info = ins->info;
              soma->ant = ins->prox;

            }
            else{
              soma->ant = ins;
            }

          }
          aux1r = aux1->ant;
          aux2r = aux2->ant;
        }
        return soma;
      }
      else if(cont1 != 0){
        while(cont1 != 0){
          soma->info = aux1->info;
          soma->ant = aux1->ant;
          cont1--;
        }
        if(aux1->info + aux2->info < 10){
          ins->info = aux1->info + aux2->info;
          ins->prox = NULL;
          if(soma == NULL){
            soma->info = ins->info;
            soma->ant = ins->prox;
          }
          else{
            soma->ant = ins;
          }
        }
        else{
          ins->info = (aux1->info + aux2->info)%10;
          ins->prox = NULL;
          if(soma == NULL){
            soma->info = ins->info;
            soma->ant = ins->prox;

          }
          else{
            soma->ant = ins;
          }

        }
        aux1r = aux1->ant;
        aux2r = aux2->ant;
        return soma;
      }
      else if(cont2 != 0){
        while(cont2 != 0){
          soma->info = aux2->info;
          soma->ant = aux2->ant;
          cont2--;
        }
        if(aux1->info + aux2->info < 10){
          ins->info = aux1->info + aux2->info;
          ins->prox = NULL;
          if(soma == NULL){
            soma->info = ins->info;
            soma->ant = ins->prox;
          }
          else{
            soma->ant = ins;
          }
        }
        else{
          ins->info = (aux1->info + aux2->info)%10;
          ins->prox = NULL;
          if(soma == NULL){
            soma->info = ins->info;
            soma->ant = ins->prox;

          }
          else{
            soma->ant = ins;
          }

        }
        aux1r = aux1->ant;
        aux2r = aux2->ant;
        return soma;
      } 

    }
  }


    


Node* inclui_fim(Node *lista, int x) {
	Node *p = (Node*) malloc(sizeof(Node));
	if (p == NULL) {
		printf("Não foi possível alocar memoria!\n");
		exit(1);
	}
	p->info = x;
	if (lista_vazia(lista)) {
		p->ant = NULL;
		p->prox = NULL;
		return p;
	}
	Node *q = lista;
	while (q->prox != NULL)
		q = q->prox;
	q->prox = p;
	p->ant = q;
	p->prox = NULL;

	return lista;
}

void imprime_lista(Node *lista) {
	Node *p = lista;
	if (lista_vazia(lista))
		printf("Lista vazia");
	while (p != NULL) {
		printf(" %d ", p->info);
		p = p->prox;
	}
	printf("\n");
}


