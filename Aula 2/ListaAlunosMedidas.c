#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct aluno {
  int ra;
  char nome[20];
  float p1;
  float p2;
  float atv;
} aluno;

typedef struct medidas {
  float media;
  float variancia;
  float desvio_padrao;
} medidas;

void ImprimeLista(aluno *a, int n){
  int apr = 0, rep = 0;
  float *media;
  char result[20];
  medidas sala;
  sala.media = 0;
  sala.variancia = 0;
  media = (float *)(malloc(n*sizeof(float)));
  for(int i = 0; i < n; i++){
    media[i] = ((a[i].p1 + a[i].p2)*0.35)+ (a[i].atv * 0.3);
    sala.media = sala.media + media[i];
    if(media[i] < 5.0){
      rep ++;
       printf("%d %s %.2f Reprovado\n", a[i].ra, a[i].nome, media[i]);
    }
    else{
      apr ++;
      printf("%d %s %.2f Aprovado\n", a[i].ra, a[i].nome, media[i]);
    }
  }
  sala.media = sala.media/n;
  for(int i = 0; i < n; i++){
    sala.variancia = sala.variancia + pow((media[i]-sala.media),2);
  }
  sala.variancia = sala.variancia/n;
  sala.desvio_padrao = pow(sala.variancia,0.5);
  printf("Aprovados: %d\n", apr);
  printf("Reprovados: %d\n", rep);
  printf("Media: %.2f\n", sala.media);
  printf("Variancia: %.2f\n", sala.variancia);
  printf("Desvio padrao: %.2f\n", sala.desvio_padrao);
  free(media);
}


int main(void) {
  int n;
  aluno *a;
  scanf("%d", &n);
  a = malloc(n*sizeof(aluno));
  for(int i =0; i < n; i++){
    scanf("%d %s %f %f %f", &a[i].ra,a[i].nome, &a[i].p1, &a[i].p2, &a[i].atv);
  }
  ImprimeLista(a, n);
  free(a);
  return 0;
}