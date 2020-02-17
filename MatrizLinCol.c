#include <stdio.h>
#include <stdlib.h>

int MatrizLinCol (int **m, int n){
    int cont =0, cont_zero_linha = 0, cont_um_linha = 0, cont_zero_coluna = 0, cont_um_coluna = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] == 0){
                cont_zero_linha++;
            }
            else if(m[i][j] == 0){
                cont_um_linha++;
            }
            else if(m[j][i] == 0){
                cont_zero_coluna++;
            }
            else if(m[j][i] == 0){
                cont_zero_coluna++;
            }
            else if(m[j][i] == 1){
                cont_um_coluna++;
            }
            else if(j == n-1){
                if(cont_zero_linha != (n-1) || cont_um_linha != 1 || cont_zero_coluna != (n-1) || cont_um_coluna != 1){
                    return 0;
                }
                cont_zero_linha = 0;
                cont_um_linha = 0;
                cont_zero_coluna = 0;
                cont_um_coluna = 0;
            }
        }
        
    }
  return 1;
}

int main() {
  int n, **m, result;
  scanf("%d", &n);
  m =(int **)malloc(n*sizeof(int**));
  for (int i = 0; i < n; i++) {
      m[i] = (int *)malloc(n * sizeof(int*));
        for(int j = 0; j<n; j++){
           scanf("%d",&m[i][j]);
        }
    }
  result = MatrizLinCol(m, n);
  printf("%d\n", result);
  return 0;
}