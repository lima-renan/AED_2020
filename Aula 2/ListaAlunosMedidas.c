#include <stdio.h>
#include <stdlib.h>

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
  float media;
  char result[20];
  for(int i = 0; i < n; i++){
    media = ((a[i].p1 + a[i].p2)*0.35)+ (a[i].atv * 0.3);
    if(media < 5.0){
      rep ++;
       printf("%d %s %.2f Reprovado\n", a[i].ra, a[i].nome, media);
    }
    else{
      apr ++;
      printf("%d %s %.2f Aprovado\n", a[i].ra, a[i].nome, media);
    }
  }
   printf("Aprovados: %d\n", apr);
   printf("Reprovados: %d\n", rep);
}

medidas Medias (aluno *a, int n){
  int apr = 0, rep = 0;
  float media = 0;
  char result[20];
  for(int i = 0; i < n; i++){
    media = media + ((a[i].p1 + a[i].p2)*0.35)+ (a[i].atv * 0.3);
  
  }
  media = media/n;
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
  return 0;
}