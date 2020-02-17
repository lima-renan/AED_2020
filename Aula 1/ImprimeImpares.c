#include <stdio.h>

int main() {
  int n, cont = 0 , i=0;
  scanf("%d",&n);
  while(cont< n){
    if (i%2 != 0){
      printf("%d\n", i);
      cont++;
    }
    i++;
  }
  return 0;
}