/**
  *@file Ficheiro                 !!!!!!!!!!!!!!!!!!!!!!           .
  *\brief Neste ficheiro está presente mascáras, estruturas de dados e de stack,bem omo funções utilizadas na stack.
  *@date May 2021
  *@returns                    !!!!!!!!!!!!!!!!!!!!!!!!!!
 */
#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>
/**
 * Struct que enumera os tipos e que vai aplicá-los na struct data.
 */
typedef enum { 
  LONG = 1,    /**< Tipo Long com o valor 1 (2^0) associado */
  DOUBLE = 2,  /**< Tipo Double com o valor 2 (2^1) associado */
  CHAR = 4,    /**< Tipo Char com o valor 4 (2^2) associado */
  STRING = 8,  /**< Tipo String com o valor 8 (2^3) associado */
  arrays = 16, /**< Tipo Array com o valor 16 (2^4) associado */
  } 
  TYPE;


/**
 * Criação de máscara INTEGER.
 */
#define INTEGER  (LONG | CHAR)
/**
 * Criação de máscara NUMBER.
 */
#define NUMBER   (INTEGER | DOUBLE)

/**
 * Uma struct que nos dá os tipos de dados que estamos a usar na stack
 */
typedef struct data {
  TYPE type;            /**< Tipos de dados vindos do enum TYPE */
  struct stack *arrays; /**< Tipo de dado que constitui um array */
  long LONG;            /**< Tipo long */
  double DOUBLE;        /**< Tipo double */
  char CHAR;            /**< Tipo char */
  char *STRING;         /**< Tipo string */
} DATA;

/**
 * Definição de uma struct com as caracteristicas da stack.
 */
typedef struct stack {
  DATA array[26];  /**< Array 26 letras */
  DATA *stack;     /**< Tipo da stack */
  int size;        /**< Tamanho da stack */
  int n_elems;     /**< Numero de elementos ao momento na stack */
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
STACK_OPERATION_PROTO(struct stack *, arrays)
STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif