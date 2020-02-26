#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
  float x;
  float y;
} ponto;

int checkpoints (int n, ponto *p, ponto r1, ponto r2){
  int cont = 0;
  for(int i = 0; i < n; i++){
    if((float)p[i].x != (float)r1.x && (float)p[i].x != (float)r2.x && (float)p[i].x > (float)r1.x && (float)p[i].x < (float)r2.x){
      if((float)p[i].y != (float)r1.y && (float)p[i].y != (float)r2.y && (float)p[i].y > (float)r1.y && (float)p[i].y < (float)r2.y){
        cont++;
      }
    }
  }
  return cont;
}

int main() {
  int result, n, cont = 0;
  ponto *p, r1, r2;
  scanf("%d", &n);
  p = malloc(n * sizeof(ponto));
  for(int i = 0; i < n; i++){
    scanf("%f %f", &p[i].x, &p[i].y);
  }
  scanf("%f %f", &r1.x, &r1.y);
  scanf("%f %f", &r2.x, &r2.y);
  result = checkpoints(n, p, r1, r2);
  printf("%d\n", result);
  free(p);
  return 0;
}