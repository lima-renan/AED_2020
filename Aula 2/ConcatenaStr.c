#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena(char *s1, char *s2){
  int i = 0, j = 0;
  char *concat;
  concat = malloc(200*sizeof(char));
  while (s1[i] != '\x00' && s1[i] != '\n' ){
    concat[i] = s1[i];
    i++;
  }
  while (s2[j] != '\x00'){
    concat[i] = s2[j];
    i++;
    j++;
  }
  concat[i] = '\x00';
  return concat;
}

int main(void) {
  char *s1, *s2;
  int i = 0, j = 0;
  s1 = malloc(100*sizeof(char));
  s2 = malloc(100*sizeof(char));
  fgets(s1, 100, stdin);
  fgets(s2, 100, stdin);
  printf("%s", concatena(s1,s2));
  free(s1);
  free(s2);
  return 0;
}