#include <stdio.h>

int Triangular(int n){
  int i = 1;
  while(i<= 1000){
    if (i*(i+1)*(i+2) == n){
      return 1;
    }
    i++;
  }
  return 0;
}

int main() {
  int i = 1;
  while(i<= 1000){
    if(Triangular(i) == 1){
      printf("%d\n", i);
    }
    i++;
  }
  return 0;
}