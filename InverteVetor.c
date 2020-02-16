#include <stdio.h>
#include <stdlib.h>

void InverteVetor(int *v, int n){
  int x[n];
  for(int i = 0; i<n; i++){
    x[i] = v[((n-1)-i)];
  }
  for(int i = 0; i<n; i++){
    v[i] = x[i];
  }
}

int main() {
  int n;
  int *v;
  int i;
  scanf("%d", &n);
  v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d",&v[i]);
    }
  InverteVetor(v, n);
  for(int i = 0; i<n; i++){
    printf("%d\n", v[i]);
  }
  free(v);
  return 0;
}