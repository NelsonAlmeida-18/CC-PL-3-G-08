#include <stdio.h>
#include "stack.h"
#define SIZE  10240

STACK criar_stack() {
  STACK s;
  s.pos = 0;
  return s;
}

#define PUSH(s, val)        \
   s.array[s.pos++] = val;

#define POP(s)              \
  s.array[--s.pos]

void print_stack(STACK s) {
  printf("Stack: ");
  for(int k = 0; k < s.pos; k++)
    printf("\t%3ld", s.array[k]);
  printf("\n"); 
}

#define SOMAR(s)  PUSH(s, POP(s) + POP(s));
#define SUBTR(s)  {   \
  long Y = POP(s);  \
  long X = POP(s);  \
  PUSH(s, X - Y);   \
}
#define MULT(s)  PUSH(s, POP(s) * POP(s));
#define DIV(s)  {   \
  long Y = POP(s);  \
  long X = POP(s);  \
  PUSH(s, X / Y);   \
}
/*
#define AND(s) {   \
  long Y = POP(s);  \
  long X = POP(s);  \
  PUSH(s, X & Y);   \
}
*/