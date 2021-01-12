#include <stdio.h>

void abc(char *s){
  if (s[0] == '\0') return;
  printf("%c", s[0]);
  abc(s + 1);
}

void main(){
  char a[] = {'w','e','l','i','t','o','n'};
  abc(a);
}