#include <stdio.h>
#include "stack.h"
#define SIZE  10240

STACK criar_stack() {
  STACK s;
  s.pos = 0;
  return s;
}

void print_stack(STACK s) {
  for(int k = 0; k < s.pos; k++)
    printf("%ld", s.array[k]);
  printf("\n"); 
}
