#include <stdio.h>

typedef struct ponto{
  float x;
  float y;
} ponto;

int checkpoint (ponto p, ponto r1, ponto r2){
  if(p.x > r1.x && p.x < r2.x){
    if(p.y > r1.y && p.x < r2.y){
      return 1;
    }
  }
  return 0;
}

int main() {
  int result;
  ponto p, r1, r2;
  scanf("%f %f", &p.x, &p.y);
  scanf("%f %f", &r1.x, &r1.y);
  scanf("%f %f", &r2.x, &r2.y);
  result = checkpoint(p, r1, r2);
  printf("%d\n", result);
  return 0;
}