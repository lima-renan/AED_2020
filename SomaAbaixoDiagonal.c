#include <stdio.h>
#include <stdlib.h>

int SomaAbaixoDiagonal (int *m){
    int sum = 0;
  for(int i = 0; i<n; i++){
    for(int k = 0; k<n; k++){
        if(i == k && i != (n-1) && k != (n-1) ){
            for(l = 1; (i+l) < n; l++){
                sum = sum = sum + m[(i+l)][k];
            }
        }
    }
  }
  return sum;
}

int main() {
  int *m, sum;
  m = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        for(int k = 0; k<n; k++){
           scanf("%d",&m[i][k]);
        }
    }
  sum = SomaAbaixoDiagonal(m) ;
  printf("%d\n", sum);
  return 0;
}