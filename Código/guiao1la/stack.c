/**
  *@File Este ficheiro serve para dar stack aos elementos
  *
*/
#include <stdio.h>
#include "stack.h"
#define SIZE  10240
/**\brief Função para criar a stack
  *@param line A função não recebe nada como input
  *@returns Devolve a stack 
*/
STACK criar_stack() {
  STACK s;
  s.pos = 0;
  return s;
}
/**\brief Função para dar print à stack
  *@param line A função print_stack recebe a stack como input
  *@returns nada
*/
void print_stack(STACK s) {
  for(int k = 0; k < s.pos; k++)
    printf("%ld", s.array[k]);
  printf("\n"); 
}
