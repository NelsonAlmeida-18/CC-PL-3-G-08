/**
  *@file Ficheiro                 !!!!!!!!!!!!!!!!!!!!!!           .
  *\brief Neste ficheiro está presente mascáras, estruturas de dados e de stack,bem omo funções utilizadas na stack.
  *@date April 2021
  *@returns                    !!!!!!!!!!!!!!!!!!!!!!!!!!
 */
#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>
/**
 * \brief Declara um tipo de dados enum.
 */
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

/**
 * \brief Criação de máscaras INTEGER e NUMBER
 */
#define INTEGER  (LONG | CHAR)
#define NUMBER   (INTEGER | DOUBLE)

/**
 * \brief Definição de uma estrutura com  os tipos de dados que está na stack.
 */
typedef struct data {
  TYPE type;
  // Esta parte devia ser transformada numa union mais tarde
  long LONG;
  double DOUBLE;
  char CHAR;
  char *STRING;
} DATA;

/**
 * \brief Definição de uma estrutura com as caracteristicas da stack.
 */
typedef struct stack {
  DATA *stack;
  int size;
  int n_elems;
} STACK;

/**
 * \brief Definição dos protótipos das funções utilizadas na stack.
 */
int has_type(DATA elem, int mask);
STACK *create_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);

/**
 * \brief Definição de uma macro para os operadores da stack.
 */
#define STACK_OPERATION_PROTO(_type, _name)   \
  void push_##_name(STACK *s, _type val);     \
  _type pop_##_name(STACK *s);

/**
 * \brief Definição dos protótipos das funções utilizadas na stack.
 */
STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif