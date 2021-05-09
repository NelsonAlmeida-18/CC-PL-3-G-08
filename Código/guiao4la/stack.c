/**
  *@file Ficheiro que contém tudo relativo à stack que irá ser utilizada.
  *\brief Neste ficheiro tem uma funcao que cria uma stack, bem como todos os parametros que podem ser utilizados com a mesma.
  *@date April 2021 
  */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
  *\brief Esta funcao indica o tipo de um certo elemento
  *@param Recebe como parametros a stack e uma máscara.
  *@return Retorna um inteiro.
  */
int has_type(DATA elem, int mask) {
  return (elem.type & mask) != 0;
}

/**
  *\brief Esta funcao cria uma stack, bem como todos os parametros que podem ser utilizados com a mesma(tamanho,nºelementos).
  *@param Não recebe parametros.
  *@return Retorna a stack.
  */
STACK *create_stack() {
  STACK *s = (STACK *) calloc(1, sizeof(STACK));
  s->n_elems = 0;
  s->size = 100;
  s->stack = (DATA *) calloc(s->size, sizeof(DATA));
  return s;
}

/**
  *\brief Esta funcao dá push(+1) a um elemento na stack.
  *@param Recebe como parametros a stack e um elemento DATA.
  */
void push(STACK *s, DATA elem) {
  if(s->size == s->n_elems) {
    s->size += 100;
    s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
  }
  s->stack[s->n_elems] = elem;
  s->n_elems++;
}

/**
  *\brief Esta funcao da pop(-1) de um elemento na stack.
  *@param Recebe como parametros a stack.
  *@return Retorna a stack sem esse elemento.
  */
DATA pop(STACK *s) {
  s->n_elems--;
  return s->stack[s->n_elems];
}

/**
  *\brief Esta funcao devolve o topo da stack.
  *@param Recebe como parametros a stack.
  *@return Retorna o topo da stack.
  */
DATA top(STACK *s) {
  return s->stack[s->n_elems - 1];
}

/**
  *\brief Esta funcao verifica se a stack é vazia.
  *@param Recebe como parametros a stack.
  *@return Retorna um inteiro se for vazia.
  */
int is_empty(STACK *s) {
  return s->n_elems == 0;
}

/**
  *\brief Esta funcao imprime a stack recebida.
  *@param Recebe como parametros a stack.
  */
void print_stack(STACK *s) {
  int K;
  for(K = 0; K < s->n_elems; K++) {
    DATA elem = s->stack[K];
    TYPE type = elem.type;
    switch(type) {
      case LONG:
        printf("""%ld", elem.LONG); break;
      case DOUBLE:
        printf("""%g", elem.DOUBLE); break;
      case CHAR:
        printf("""%c", elem.CHAR); break;
      case STRING:
        printf("""%s", elem.STRING); break;
      case arrays:
        printf("teste");break;
    }
  }
//  printf("Num elems:%d\n",K);
  printf("\n");
}

/**
  *\brief Definição de uma macro para os operadores da stack, incluindo a função push.
  */
#define STACK_OPERATION(_type, _name)         \
  void push_##_name(STACK *s, _type val) {    \
    DATA elem;                                \
    elem.type = _name;                        \
    elem._name = val;                         \
    push(s, elem);                            \
  }                                           \
  _type pop_##_name(STACK *s) {               \
    DATA elem = pop(s);                       \
    assert(elem.type == _name);               \
    return elem._name;                        \
  }
/**
  *\brief Definição de todos os protótipos relativos aos operadores da stack.
  */
STACK_OPERATION_PROTO(struct stack *, arrays)
STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)