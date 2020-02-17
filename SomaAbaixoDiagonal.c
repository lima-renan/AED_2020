#include <stdio.h>
#include <stdlib.h>

int SomaAbaixoDiagonal (int **m, int n){
    int sum = 0;
  for(int i = 0; i<n; i++){
    for(int k = 0; k<n; k++){
        if(i == k && i != (n-1) && k != (n-1) ){
            for(int l = 1; (i+l) < n; l++){
                sum = sum + m[(i+l)][k];
            }
        }
    }
  }
  return sum;
}

int main() {
  int **m, n, sum;
  scanf("%d",&n);
  m = (int **)malloc(n * sizeof(int**));
    for (int i = 0; i < n; i++) {
      m[i] = (int *)malloc(n * sizeof(int*));
        for(int k = 0; k<n; k++){
           scanf("%d",&m[i][k]);
        }
    }
  sum = SomaAbaixoDiagonal(m, n) ;
  printf("%d\n", sum);
  free(m);
  return 0;
}