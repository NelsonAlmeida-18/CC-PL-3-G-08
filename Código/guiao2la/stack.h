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
 * Struct que enumera os tipos e que vai aplicá-los na struct data.
 */
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;
/**< Tipo Long com o valor 1 (2⁰) associado 
 * Tipo Double com o valor 2 (2¹) associado
 * Tipo Char com o valor 4 (2²) associado
 * Tipo String com o valor 8 (2³) associado 
 **/

/**
 * Criação de máscaras INTEGER e NUMBER
 */
#define INTEGER  (LONG | CHAR)
#define NUMBER   (INTEGER | DOUBLE)

/**
 * Uma struct que nos dá os tipos de dados que estamos a usar na stack
 */
typedef struct data {
  TYPE type;       /**< tipos de dados vindos do enum TYPE */
  long LONG;       /**< Tipo long */
  double DOUBLE;   /**< Tipo double */
  char CHAR;       /**< Tipo char */
  char *STRING;    /**< Tipo string */
} DATA;

/**
 * Definição de uma estrutura com as caracteristicas da stack.
 */
typedef struct stack {
  DATA *stack;      /**< Tipo da stack */
  int size;         /**< Tamanho da stack */
  int n_elems;      /**< Numero de elementos ao momento na stack */
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