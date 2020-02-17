#include <stdio.h>

int MaiorComprimento (char m[100]){
    int tam[50],cont = 0, maior, j = 0;
    for(int i = 0; i < 50; i++){
       tam[i] = 0;
    }
    while(m[j] != '\x00'){
        if(m[j] != ' ' && m[j+1] != '\x00'){
            tam[cont]++;
        }
        else if(m[j] == ' '){
          cont++;
        }
        j++;
    }
    for(int i = 0; i < 50; i++){
        if(i == 0){
            maior = tam[0];
        }
        else if (maior < tam[i]){
            maior = tam[i];
        }
    }
    
  return maior;
}

int main() {
  char str[100];
  int tam;
  fgets(str,100, stdin);
  tam = MaiorComprimento(str);
  printf("%d\n", tam);
  return 0;
}